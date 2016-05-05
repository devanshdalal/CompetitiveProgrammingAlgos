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
    int t,i,j,k,l,n,m,p,q;
    DD;
    cin >> n;
    ll a[n],b[n],ans=0;
    b[0]=0;
	cin >> a[1];
    b[1]=a[1];
    for (i = 2; i <=n; ++i)
    {
    	cin >> a[i];
    	b[i]=b[i-1]+a[i];
    }
    if (b[n]%3==0)
    {
    	ll p1=b[n]/3,p2=2*b[n]/3;
    	p=0;
    	for (i = 1; i < n; ++i)
    	{
    		if (b[i]==p1)
    		{
    			p++;
    		}else if (b[i]==p2)
    		{
    			ans+=ll(p);
    		}
    	}
    	if (p1==0)
    	{
    		// cerr <<  p << endl;
    		ans=ll(p)*ll(p-1)/2;
    	}
    }
    else{
    	ans=0;
    }

    cout << ans << endl;
    return 0;
}