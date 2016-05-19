#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

ll mem[101][101];

int main(){
    ll t,i,j,k,l,n,m,p,q;
    ll a[1001];
    scanf("%lld",&n);
    for (i = 1; i <=n; ++i)
    {
		scanf("%lld",&a[i]);
    }

    for (i = 0; i <=n; ++i)
    {
    	mem[i][i]=1;
    	mem[i+1][i]=1;
    }
    for (j = 1; j <=n; ++j)
    {
    	for (i = j-1; i>0 ; --i)
    	{
    		mem[i][j]=mem[i+1][j];
    		for (k = i+1; k<=j ; ++k)
    		{
    			if (a[k]==-a[i] and a[k]>0)
    			{
    				mem[i][j]=(mem[i][j]+mem[i+1][k-1]*mem[k+1][j])%mod;
    			}
    		}
    	}
    }

    printf("%lld\n", mem[1][n]);
    return 0;
}