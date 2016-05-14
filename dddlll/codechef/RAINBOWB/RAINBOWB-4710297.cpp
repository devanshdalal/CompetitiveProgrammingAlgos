#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

inline ll mpow(ll base, ll exponent){
    ll result = 1;
    while (exponent ){
        if (exponent&1)result = (result * base)%mod;
        exponent = exponent >> 1;
        base = (base * base)%mod;
    }
    return result;
}

ll ncr(int n,int r){
	if (r==0 or n<=r)
	{
		return 1;
	}
	return ll(n)*ncr(n-1,r-1)/ll(r);
}

int main(){
    int t,i,j,k,l,n,m,p,q;
	scanf("%d",&n);
    
    ll ans=0;
    if (n<13)
    {
    	printf("0\n");
    }else{
    	ll *fact=new ll[n],*inv=new ll[n],*finv=new ll[n];
		finv[0]=finv[1]=inv[1]=fact[0]=fact[1]=1;
    	for(i=2;i<n;i++){
			inv[i]=mod-inv[mod%i]*(mod/i)%mod;
			fact[i]=(fact[i-1]*i)%mod;
			finv[i]=(finv[i-1]*inv[i])%mod;
		}
    	n-=13;
	    for (p = 0; p <= n; ++p)
	    {
	    	// 301388891
	    	ll ncr=((fact[p+6]*finv[6])%mod)*finv[p];
	    	ncr%=mod;
	    	ll n2=((fact[n-p+5]*finv[5])%mod)*finv[n-p];
	    	n2%=mod;
	    	if ((n-p)&1)
	    	{
	    		ans-=(ncr*n2)%mod;
	    	}else{
	    		ans+=(ncr*n2)%mod;
	    	}
	    }
    	printf("%lld\n", (mod+(ans%mod))%mod );
    }

    return 0;
}