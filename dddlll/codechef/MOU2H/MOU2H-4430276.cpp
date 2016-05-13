#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include <queue>
#include<vector>
#include<unordered_map>
#define DD ios_base::sync_with_stdio(false)
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
#define P pair<int,int>
#define N 1000005
using namespace std;
const ll mod = 1000000009;


class comp1 {
    public:
    bool operator()(P t1, P t2) // Returns true if t1 is earlier than t2
    {
       return t1.second>t2.second;
    }
};

inline ll domod(ll c){
	if(c>mod)return c-mod;
	if(c<0)return c+mod;
	return c;
}

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int *a=new int[N],*last=new int[8*N],*b=new int[N];
    ll *dp=new ll[N],*sum=new ll[N];
    while(t--){
    	scanf("%d",&n);
    	scanf("%d",&a[0]);
    	for ( i = 1; i < n; ++i)
    	{
    		scanf("%d",&a[i]);
    		b[i]=a[i]-a[i-1];
    		last[4*N+b[i]]=0;
    	}
    	dp[0]=sum[0]=1;
    	for (i = 1; i < n; ++i)
    	{
    		p=last[4*N+b[i]];
    		sum[i]=domod(2*sum[i-1] -(p==0?0:sum[p-1]));
    		last[4*N+b[i]]=i;
    	}

    	printf("%lld\n", ((ll)sum[n-1]-1+mod)%mod );
    }

    return 0;
}