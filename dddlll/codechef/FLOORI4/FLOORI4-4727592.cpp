#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
ll mod = 1000000007;
ll nmod = 1000000007;

inline ll f(ll n){
	ll val=n%nmod;
	ll p2=(val*val)%nmod;
	ll p4=(p2*p2)%nmod;
	p2=( (6*(p4*val%nmod) + 15*p4 +10*(p2*val%nmod) - n)%nmod + nmod)%nmod;
	if (p2%30!=0)
	{
		cerr << "error" << endl;
	}
	return p2/30;
}

inline ll sum(ll i,ll j){
	return f(j)-f(i);
}

int main(){
    ll t,i,j,k,l,n,m;
    scanf("%lld",&t);
    // cerr << 7*8%5/2 << endl;
    while(t--){
        scanf("%lld %lld",&n,&mod);
        nmod=30*mod;
        ll rt=sqrt(n),ans=0;
        ll next=n,prev=n+1;
        for (i = 2; i <rt; ++i)
        {
        	prev=(l=n/i) + 1;
        	// cerr << "prev " << prev << endl; 
        	ans+=((i-1)*sum(l,next)%mod);
        	// cerr << (i-1)<<" "<< sum(prev-1,next) << endl;
        	next=l;
        }
        for (i = 1; i < prev ; ++i)
        {
        	ll sqi=i*i%mod;
        	ans+=((sqi*sqi%mod)*(n/i))%mod;
        }
        // ll a2=0;
        // for (i = 1; i <=n ; ++i)
        // {
        // 	ll sqi=i*i%mod;
        // 	a2+=(sqi*sqi%mod)*(n/i);
        // }
        // cerr << a2%mod << " ";
        printf("%lld\n", (mod+ans%mod)%mod );
    }
    return 0;
}