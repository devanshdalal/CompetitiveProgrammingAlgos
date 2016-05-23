#include <bits/stdc++.h>
#include <ctime>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 10000001
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

ll mymod=1000000007;


typedef ll INT;
/* Type for values in the array. */
typedef ll VAL;	

/* compare the value inside the array */
#define VAL_LT(x,y) x < y

/* a struct to hold preprocessed information */

struct rmqinfo {
  INT alen;     // length of original array
  VAL * array;  // pointer to original array
  INT ** sparse;
  INT * block_min;
  INT * labels;
};

/* clear the least significant x-1 bits */
static inline INT clearbits(INT n, INT x){
  return((n >> x) << x);  
}

/* return floor of log n. assumes n > 0
 * uses __builtin_clz for GCC */
static inline INT intlog2(INT n){
#ifdef __GNUC__
  return(__builtin_clz(n)^31);
#else
  INT res;
  for(res = 0; n > 0; n >>= 1, res++);
  return(res-1);
#endif
}

/*
 * return position of least significant set bit. assumes n > 0
 * uses __builtin_ctz for GCC */
static inline INT lsbset (INT n){
#ifdef __GNUC__
  return(__builtin_ctz(n));
#else
  INT res = 0;
  while(n % 2 == 0){
    res++; n >>= 1;
  }
  return(res);
#endif
}

/*
 * Return the position in array which gives the minimum value
 * in the subarray a[x..y] using a naive algorithm.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query_naive(VAL * a, INT x, INT y){
  INT z, tmp;
  VAL minval;
  if(x == y) return x;
  if(x > y){
    tmp = x; x = y; y = tmp;
  }
  z = x;
  minval = a[x];  
  for(x++; x <= y; x++){
    if(VAL_LT(a[x],minval)){
      z = x; minval = a[x];
    }
  }
  return(z);
}

/*
 * Preprocess array in linear time so that range minimum
 * queries can be conducted in constant time.
 */
struct rmqinfo * rm_query_preprocess(VAL * array, INT alen){
  struct rmqinfo * info;
  INT i, j, g, rows, cols, block_cnt, rowelmlen;
  INT * block_min, **sparse, *labels;
  INT gstack[32], gstacksize = 0;
  
  info = (struct rmqinfo *) malloc(sizeof(struct rmqinfo));
  /* divide input array into blocks of size 32.
   * block_cnt is the number of such blocks.
   * block_minpos is an array that contains the 
   * minimum positions in each block. */
  block_cnt = ((alen-1) >> 5) + 1;
  block_min = (INT *) malloc (sizeof(INT) * block_cnt);
  for(i = j = 0; i < alen; i++){
    if(i % 32 == 0){
      if(i > 0) j++;
      block_min[j] = i;
    } else if(VAL_LT(array[i],array[block_min[j]])){
      block_min[j] = i;
    }
  }
  /* make a sparse table for the rmq of the blocks.
   * sparse[j][i] represents the minimum in
   * block[i] to block[i + 2^{j+1} - 1] */
  rows = intlog2(block_cnt);
  sparse = NULL;
  /* sparse tables aren't needed when the array is less than 32 elements long */
  if(rows > 0){
    sparse = (INT **) malloc (sizeof(INT *) * rows);
    /* first row is min of adjacent entries. Table entries are
     * converted to positions in original array */
    sparse[0] = (INT *) malloc (sizeof(INT) * (block_cnt - 1));
    for(i = 0; i < block_cnt - 1; i++){
      if(VAL_LT(array[block_min[i+1]],array[block_min[i]]))
        sparse[0][i] = block_min[i+1];
      else
        sparse[0][i] = block_min[i];
    }
    for(j = 1; j < rows; j++){
      rowelmlen = 2 << j;    /* 2^{j+1} */
      cols = block_cnt - rowelmlen + 1;
      sparse[j] = (INT *) malloc (sizeof(INT) * cols);
      for(i = 0; i < cols; i++){
        if(VAL_LT(array[sparse[j-1][i + (rowelmlen >> 1)]],array[sparse[j-1][i]]))
          sparse[j][i] = sparse[j-1][i + (rowelmlen >> 1)];
	else
	  sparse[j][i] = sparse[j-1][i];	
      }
    }
  }
  
  /* create integers for constant time rmq inside the blocks
   * In each block:
   * - g[i]: the first position to the left of i
   * where array[g[i]] < array[i] (or -1 if there is no such position).
   * - l[i]: the jth bit of l[i] is 1 iff j is the first
   * position left of i where array[j] < array[i] */
  labels = (INT *) malloc(sizeof(INT) * alen);
  for(i = 0; i < alen; i++){
    if(i % 32 == 0) gstacksize = 0;
    labels[i] = 0;
    while(gstacksize > 0 && (VAL_LT(array[i],array[gstack[gstacksize-1]]))){
      gstacksize--;
    }
    if(gstacksize > 0){
      g = gstack[gstacksize-1];
      labels[i] = labels[g] | (1 << (g%32));
    }
    gstack[gstacksize++] = i;
  }
  info->array = array;
  info->sparse = sparse;
  info->block_min = block_min;
  info->labels = labels;
  info->alen = alen;
  return info;  
}


/*
 * Return the position in array which gives the minimum value
 * in the subarray rmqinfo.array[x..y] using preprocessed information.
 * When there are multiple positions with the same minimum value,
 * in the range, the smallest index is returned.
 */
INT rm_query(const struct rmqinfo * info, INT l, INT r){
  INT blocknum_l, blocknum_r, blockdiff, blockmin;
  INT tmp, v, bpos;
  INT v1, v2, pos1, pos2;
  if(l == r) return l;
//  if(l > r){
//    tmp = l; l = r; r = tmp;
//  }
  blocknum_l = (l >> 5); blocknum_r = (r >> 5);  /* obtain which blocks l and r will come in */
  bpos = blocknum_l << 5;
  switch(blockdiff = blocknum_r - blocknum_l){
  case 0: /* one inblock query in block blocknum_l. from position (l%32) to (r%32) */
    v = clearbits(info->labels[r], l % 32); /* clear (x - 1) insiginificant bits */
    return ((v == 0) ? r : bpos + lsbset(v));
    break;
  case 1:  /* two inblock queries. in block blocknum_l and blocknum_r.
	    * in blocknum_l: postion (l%32) to 31  
	    * in blocknum_r: postion 0 to (r%32) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
    break;
  default: /* two inblock queries, and a query over the blocks.
	    * in blocknum_l: postion (l%32) to 31
	    * in blocknum_r: postion 0 to (r%32).
	    * block (blocknum_l+1) to (blonum_r-1) */
    tmp = bpos + 31;
    v1 = clearbits(info->labels[tmp], l%32);
    v2 = info->labels[r];
    pos1 = (v1 == 0) ? tmp : (bpos + lsbset(v1));
    pos2 = (v2 == 0) ? r : lsbset(v2) + (blocknum_r<<5);
    if(blockdiff == 2){ /* (blocknum_l+1) == (blonum_r-1) */
      blockmin = info->block_min[blocknum_l+1];
    } else {
      /* rmq of blocknum_l+1 to blocknum_r-1 */
      int t1, t2, k;
      k = intlog2(blockdiff-1) - 1;
      t1 = info->sparse[k][blocknum_l+1];
      t2 = info->sparse[k][blocknum_r - (1 << (k+1))];
      blockmin = (VAL_LT(info->array[t2],info->array[t1])) ? t2 : t1;
    }
    pos1 = (VAL_LT(info->array[blockmin],info->array[pos1])) ? blockmin : pos1;
    return((VAL_LT(info->array[pos2],info->array[pos1])) ? pos2 : pos1);
  }
}

void rm_free(struct rmqinfo * info){
  INT block_cnt, rows, i;
  block_cnt = ((info->alen-1) >> 5) + 1;
  rows = intlog2(block_cnt);
  for(i = 0; i < rows; i++)
    free(info->sparse[i]);
  free(info->sparse);
  free(info->block_min);
  free(info->labels);
  free(info);
}

inline ll mpow(ll b, ll ex){
  if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

ll arr[10000000];

int main(){
    ll n,k,q;
    ios_base::sync_with_stdio(0);
		clock_t start=clock();

    cin >> n >> k >> q ;
    ll a,b,c,d,e,f,r,s,t,m;
    
    //ll * arr=new ll[n];
    cin >> a >> b >> c>>d>>e>>f>>r>>s>>t>>m>>arr[0];
    mod=s;
    ll tprod=t;
    for (int i = 1; i < n; ++i)
    {
    	tprod=tprod*t%s;
      if (tprod<=r)
      {
        arr[i]=(a*(arr[i-1]*arr[i-1]%m) + b*arr[i-1] + c)%m;
      }else{
        arr[i]=(d*(arr[i-1]*arr[i-1]%m) + e*arr[i-1] + f)%m;
      }
      // cerr << arr[i] << " ";
    }
    // cerr << endl;

    ll L1,La,Lc,Lm,D1,Da,Dc,Dm;
    cin >>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	
    rmqinfo * ds = rm_query_preprocess(arr,n);
    //return 0;

    ll sum =0,prod=1;

    while(q--){
    	L1 = (La * L1 + Lc) % Lm;
      D1 = (Da * D1 + Dc) % Dm; 
      ll L = L1 + 1;
      ll R = min(L + k - 1 + D1, n);

      // cerr << "L "<<L << "R "<<R<<endl;

      // cerr << "ans1 "<< ans1<< endl;
      ll ans1=arr[rm_query(ds,L-1,R-1)];
      sum+=ans1;
      prod=prod*ans1%mymod;
    }
    
    cerr <<  "Time " << ( std::clock() - start ) / (double) CLOCKS_PER_SEC << endl; 

    cout << sum << " " << prod << '\n';

    return 0;
}