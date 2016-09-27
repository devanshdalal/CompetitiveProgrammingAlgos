#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

/////  This is completely written by me:  .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

/**
 * In this code we have a very large aay called a, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tr: build_tr(1, 0, N-1)
 * Update tr: update_tr(1, 0, N-1, i, j, value)
 * Query tr: query_tr(1, 0, N-1, i, j)
 */

// struct data
// {
// 	ll a[4][4],c[4];
// };

// char a[1000100];
// data *tr=new data[1000110*5];

// /**
//  * Build and init tr
//  */
// void build_tr(int node, int a, int b) {
//   	if(a > b) return; // Out of range
  	
//   	if(a == b) { // Leaf node
//   		// memset(tr[node].c,0,4*sizeof(ll));
//   		// memset(tr[node].a,0,16*sizeof(ll));
//     	tr[node].c[a[a]] = 1;
//     	tr[node].a[a[a]][a[a]] = 1;
// 		return;
// 	}
	
// 	int c1=node*2,c2=c1|1;

// 	build_tr(c1, a, (a+b)/2); // Init left child
// 	build_tr(c2, 1+(a+b)/2, b); // Init right child
	
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		tr[node].c[i] = tr[c1].c[i] + tr[c2].c[i] ;
// 	}
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		for (int j= 0; j < 4; ++j)
// 		{
// 			tr[node].a[i][j] = tr[c1].a[i][j] + tr[c2].a[i][j] + tr[c1].c[i]*tr[c2].c[j]; 
// 		}
// 	}
// }

/**
 * Increment elements within range [i, j] with value value
 */
// void update_tr(int node, int a, int b, int i ) {
  
// 	if(a > b || a > i || b < i) // Current segment is not within range [i, j]
// 		return;
//   	if(a == i && b == i) { // Segment is fully within range
//   		for (int i = 0; i < 3; ++i)
//   		{
//   			tr[node].l[i]=tr[node].m[i]=tr[node].r[i]=0;
//   		}
//     	tr[node].m[a[a]] = tr[node].l[a[a]] = tr[node].r[a[a]] = 1;
//     	tr[node].sum=a[a];	
// 		return;
// 	}
// 	int mid=(a+b)/2;
// 	int c1=node*2,c2=c1|1;
// 	if (i<=mid){
// 		update_tr(c1, a, mid , i); // Updating left child
// 	}else{
// 		update_tr(c2, 1+mid, b, i); // Updating right child
// 	}

// 	int s1=tr[c1].sum,s2=tr[c2].sum;
// 	for (int i = 0; i < 3; ++i){
// 		tr[node].l[i]=tr[c1].l[i];
// 		tr[node].m[i]=tr[c1].m[i] + tr[c2].m[i] ;
// 		tr[node].r[i]=tr[c2].r[i];
// 	}
// 	for (int i = 0; i < 3; ++i){
// 		tr[node].l[(s1+i)%3]+=tr[c2].l[i];
// 		tr[node].r[(s2+i)%3]+=tr[c1].r[i];
// 	}
// 	for (int i = 0; i < 3; ++i){
// 		for (int j= 0; j < 3; ++j){
// 			tr[node].m[(i+j)%3] += tr[c1].r[i]*tr[c2].l[j];
// 		}
// 	}
// 	tr[node].sum=(s1+s2)%3;
// }

// data query_tr(int node, int a, int b, int i, int j,int s,int e) {
	
// 	if(a > b || a > j || b < i) return tr[0]; // Out of range
// 	if(a == i && b == j) // Current segment is totally within range [i, j]
// 		return tr[node];
// 	int c1=node*2,c2=c1|1;
// 	int mid=(a+b)/2;
// 	if (j<=mid)
// 	{
// 		return query_tr(c1, a, mid, i, j,s,e);
// 	}else if (i>mid)
// 	{
// 		return query_tr(c2, mid+1, b, i, j,s,e);
// 	}
// 	data q1 = query_tr(c1, a, mid, i, mid ,s,e ); // Query left child
// 	data q2 = query_tr(c2, 1+mid, b, 1+mid, j,s,e); // Query right child
	
// 	data t;

// 	for (int i = 0; i < 4; ++i)
// 	{
// 		t.c[i] = q1.c[i] + q2.c[i] ;
// 	}
// 	t.a[s][e] = q1.a[s][e] + q2.a[s][e] + q1.c[s]*q2.c[e]; 

// 	// for (int i = 0; i < 4; ++i)
// 	// {
// 	// 	for (int j= 0; j < 4; ++j)
// 	// 	{
// 	// 		t.a[i][j] = q1.a[i][j] + q2.a[i][j] + q1.c[i]*q2.c[j]; 
// 	// 	}
// 	// }
// 	return t;
// }

// int main() {
// 	for(int i = 0; i < N; i++) a[i] = 1;

// 	build_tr(1, 0, N-1);

// 	memset(lazy, 0, sizeof lazy);

// 	update_tr(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
// 	update_tr(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
// 	update_tr(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

// 	cout << query_tr(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
// }

char TAB[126];

inline void readInt(int &x) {
    register int c= getchar_unlocked();x = 0;
    for(; (c<48 || c>57); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) x = (x<<1) + (x<<3) + c - 48;
}

inline void getch(char &c){
    for(c = getchar_unlocked(); c==' ' or c=='\n'; c = getchar_unlocked());
}

char buf[21];int ix;
inline void printInt(ll x) {
     ix = 20;
     do {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do{
        putchar_unlocked(buf[ix]);
     } while (buf[ix++] != '\n');
}

struct qd
{
	int l,r,s,e,p2;
	ll p1;
};

char a[1000100];
qd   b[1000101];
ll ans[1000101];
vector<int> v[1000101];

int main(){
    int n,q,L,R;
    TAB['c']=0;
    TAB['h']=1;
    TAB['e']=2;
    TAB['f']=3;
    buf[20]='\n';

    scanf("%s",a);
    n=strlen(a);
    // scanf("%d\n",&q);
    readInt(q);
    char s,e;
    for(int i=0;i<q;i++){
        getch(s); getch(e); readInt(L); readInt(R);
    	// scanf("%c %c %d %d\n",&s,&e,&L,&R);
    	b[i].s=TAB[s];
    	b[i].e=TAB[e];
    	v[b[i].l=L-1].pb(i);
    	v[b[i].r=R-1].pb(i);
    }
    register ll fr[4]={0,0,0,0},gr[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for (int i = 0; i < n; ++i)
    {
    	a[i]=TAB[a[i]];
        gr[0][a[i]]+=fr[0];
        gr[1][a[i]]+=fr[1];
        gr[2][a[i]]+=fr[2];
        gr[3][a[i]]+=fr[3];

    	// for (int j = 0; j < 4; ++j)
    	// {
    	// 	gr[j][a[i]]+=fr[j];
    	// }
    	fr[a[i]]++;
    	// gr[a[i]][a[i]]++;
    	// for (int j= 0,end; j<v[i].size() ; ++j)
    	// {
    	for (vector<int>::iterator it=v[i].begin(),end=v[i].end();it!=end;it++)
    	{
    		int id=*it;
    		s=b[id].s; e=b[id].e;
    		if (b[id].l==i)
    		{
    			ans[id]=-gr[s][e];
    			b[id].p1=fr[s]-(a[i]==s);
    			b[id].p2=fr[e];
    		}else{
    			ans[id]+=gr[s][e] - (b[id].p1*(fr[e]-b[id].p2));
    			// cerr << id << " " <<  ans[id]<< " 	";
    		}
    	}
    }
    for (int i = 0; i < q; ++i)
    {
    	// printf("%lld\n", ans[i] );
    	printInt(ans[i]);
    }

    return 0;
}