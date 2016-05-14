#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define eq(a,b) abs(a-b)<=0.00000001
#define LMT 101
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

double fact[LMT];
double *mah[LMT],*na2[LMT];

inline ll merge(int arr[], int temp[], int left, int mid, int right){
  int i, j, k;
  ll inv_count = 0;
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)){
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else{
      temp[k++] = arr[j++];
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count += ll(mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
 
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  return inv_count;
}

inline ll _mergeSort(int arr[], int temp[], int left, int right)
{
  ll mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
 
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

ll mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main(){
    ll t,i,j,k,l,n,m,p,q;
    fact[0]=1.0;
    for (i =1; i < 101; ++i){
        fact[i]=d(i)*fact[i-1];
        mah[i]=new double[i*i/2 + 1];
        mah[i][0]=1.0/fact[i];
    }

    mah[1][0]=1.0;
	mah[1][1]=0.0;
    for (i = 2; i < LMT; ++i)
    {
        int rng=i*(i-1)/2,oldrng=(i-1)*(i-2)/2;
        double agg2=0.0,agg3=0.0;
        for (j = 0; j <= rng ; ++j)
        {
        	// d my=0.0;
        	// for (k = max(ll(0),j-i+1); k <= min(j,(ll)oldrng) ; ++k)
        	// {
        	// 	my+=mah[i-1][k];
        	// }
            if(j<=oldrng)agg3+=mah[i-1][j];
            if (j-i>=0)agg2+=mah[i-1][j-i];
            mah[i][j]=(agg3-agg2)/d(i);
            // na2[i][j]=mah[i][j]=my/d(i);
            // if (eq(mah[i][j],na2[i][j])==false)
            // {
            // 	cerr << mah[i][j] << " "<< na2[i][j] <<  endl;
            // 	cerr << i << " "<< j << endl;
            // 	exit(0);
            // }
        }
    }


    scanf("%lld",&t);
    ll a[1001];
    int b[1001];
    while(t--){
        scanf("%lld %lld",&n,&k);
        // cerr<< t  << "\nn " << n << " k " << k << endl;
        for (i = 0; i < n; ++i)
        {
            scanf("%lld",&p);
            b[i]=a[i]=p;
            // cerr << a[i] << " ";
        }
        // cerr << endl;
   	    ll half=n*(n-1)/4;
        d norm=d(n)*d(n-1)/4.0,ans,brute;
        ll curr=mergeSort(b,(int)n);
        d part=d(curr);
        // dbg(curr);
        if(k>=curr)
        {
            brute=ans=0.0;
        }else if (k<1)
        {
            brute=ans=max(0.0,part-(d)k);
        }else{
            p=1+n*(n-1)/2;
        	d *isum=new d[p],*agg=new d[p];
        	isum[0]=0;
        	agg[0]=mah[n][0];
        	for (i = 1; i < p; ++i){
        		agg[i]=agg[i-1]+mah[n][i];
        		isum[i]=isum[i-1]+i*mah[n][i];
        	}
        	// for (i = 0; i < p; ++i)
        	// {
        	// 	cerr << agg[i] << " " << isum[i] << "     ";
        	// }cerr << endl;
    		int my=1,hy=half+(n%4==0 or n%4==1?0:1);
			d fex=norm,oldf;
			bool gat=false;
        	for (i = 1; i <=k; ++i)
        	{
        		// dbg(fex);
        		// dbg(my);
        		// dbg(hy);
        		hy=my + (eq(int(fex),fex)?int(fex)-1:int(fex));
        		my++;
        		oldf=fex;
        		fex=fex*(agg[p-1]-agg[hy]);
        		fex+=(isum[hy]-isum[my-1])-(my-1)*(agg[hy]-agg[my-1]);
        		if (hy<my){
        			gat=true;
        			break;
        		}
        	}
        	// cerr << "fex11 " << fex << " "<< my << " "<< hy << endl;
        	if (gat){
        		// cerr << "ddcndfv " << i << endl;
        		for (i++ ; i <=k; ++i)
        		{
        			// cerr << "llll "<< oldf <<" " << my << endl;
        			oldf=oldf*(agg[p-1]-agg[my-1]);
        			my++;
        		}
        		// cerr << "oldf" << oldf << endl;
        		if (curr<my)
        			brute=0;
				else
					brute=oldf;
        	}else{
        		if(curr<my)
        			brute=0;
				else if (curr<=hy)
					brute=curr-my+1;
				else
					brute=oldf;
        	}
      //   	mem[0]=0.0;
      //   	for (j = 1; j<p ; ++j)
    		// {
    		// 	mem[j]=min(norm,d(j-1));
    		// 	// cerr << "mem["<<j<<"] "<< mem[j] << endl;
    		// }
      //   	for (i = 2; i <=k; ++i)
      //   	{
      //   		d the=0.0;
      //   		for (j = 0; j<p; ++j)
      //   		{
      //   			tem[j]=mah[n][j]*mem[j];
      //   		}
      //   		sort(tem,tem+p);
      //   		for (j = 0; j<p; ++j)
      //   		{
      //   			the+=tem[j];
      //   		}
      //   		for (j = 1; j<p ; ++j)
	    	// 	{
	    	// 		if (the<mem[j-1]){
	    	// 			rem[j]=the;
	    	// 		}else{
	    	// 			rem[j]=mem[j-1];
	    	// 		}
      //       		// cerr << "rem["<<j<<"] "<< rem[j] << endl;
	    	// 	}
	    	// 	swagg(rem,mem);
      //   	}
      //   	// cerr << curr << endl;
      //       // for (i = 0; i < p; ++i)
      //       // {
      //       // 	cerr << "mem["<<i<<"] "<< mem[i] << endl;
      //       // }cerr << endl;
      //   	ans=brute=mem[curr];
	        // dbg(brute);
	        // dbg(ans);
	        // if (abs(brute-ans)>0.000001)
	        // {
	        // 	cerr << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvf" << endl;
	        // 	if(brute>ans){
	        // 		cerr << "........................" << endl;
	        // 	}
        	// 	for (i = 0; i < n; ++i)
        	// 	{
        	// 		cerr << a[i] << " ";
        	// 	}cerr << endl;
	        // }
        }
        // if (ans!=brute)
        // {
        //     dbg(ans);
        //     dbg(brute);
        //     i=1/0;
        //     exit(0);
        // }
        printf("%0.7lf\n", brute );
        // cerr << "-------------------------\n" << endl;
    }

    // k=1;
    // for (i = k; i < 101 ; ++i)
    // {
    //     double expe=0;
    //     int rng=i*(i-1)/2;
    //     for (j = 0; j<=rng; ++j)
    //     {
    //         // expe+=mah[i][j]*d(j);
    //         expe+=d(j)*mah[i][j];
    //     }
    //     printf("%0.10lf\n",expe );
    // }cerr << endl;

    return 0;
}