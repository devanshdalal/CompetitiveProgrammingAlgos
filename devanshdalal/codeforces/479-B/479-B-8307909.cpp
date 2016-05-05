#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;
    int a[10001],n;

// int findmin(){
// 	int cmin=1000000;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cmin=min(cmin,a[i]);
// 	}
// 	return cmin;
// }

// int findmax(){
// 	int cmin=-1;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cmin=max(cmin,a[i]);
// 	}
// 	return cmin;
// }

int main(){
    int t,i,j,k,l,m,p,q;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; ++i)
    {
    	// scanf("%d",&p);
    	scanf("%d",&a[i]);
    	// a[p]++;
    }
    // int start=1,end=10000;
    // for (i = 1; i<=end ; ++i)
    // {
    // 	if (a[i]!=0)
    // 	{
    		
    // 	}
    // }

    // int cmin=findmin(),cmax=findmax();
    int ans1[100001],ans2[100001];
    int cmin,cmax;
    for (i = 0; i <k; ++i)
    {
    	int mini=-1,maxi=-1;
    	cmax=0,cmin=10000;
    	for (l = 0; l < n; ++l)
    	{
    		if (a[l]<=cmin)
    		{
    			mini=l;
    			cmin=a[l];
    		}
    		if (a[l]>=cmax)
    		{
    			maxi=l;
    			cmax=a[l];
    		}
    	}
    	if (cmin==cmax)
    	{
    		break;
    	}
    	ans1[i]=maxi;
    	ans2[i]=mini;
    	a[mini]++;
    	a[maxi]--;
    }

    	int mini=-1,maxi=-1;
    cmax=0,cmin=10000;
    	for (l = 0; l < n; ++l)
    	{
    		if (a[l]<=cmin)
    		{
    			mini=l;
    			cmin=a[l];
    		}
    		if (a[l]>=cmax)
    		{
    			maxi=l;
    			cmax=a[l];
    		}
    	}

    printf("%d %d\n",cmax-cmin, j=i );
    for (i = 0; i < j; ++i)
    {
    	printf("%d %d\n", ans1[i]+1,ans2[i]+1 );
    }
    return 0;
}