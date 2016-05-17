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

int main(){
    int t,i,j,l,n,m,p,q;
    scanf("%d",&t);
    char a[100001];
    while(t--){
    	ll x , k , lastk;
    	scanf("%lld %lld",&x,&k);
    	for (i = 0; i < 60; ++i)
    	{
    		if ((ll(1)<<i)>k)
    		{
    			lastk=k-(ll(1)<<(--i));
    			break;
    		}
    	}
    	double part=d(x)/d(ll(1)<<i);

        printf("%0.8lf\n", part*(d(lastk)+0.5) );
    }
    return 0;
}