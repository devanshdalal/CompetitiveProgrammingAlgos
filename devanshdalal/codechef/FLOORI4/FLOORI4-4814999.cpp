#include<string.h>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stdio.h>
typedef unsigned long long ul;
typedef long long ll;
typedef double d;
using namespace std;
ll mod,mod30;

inline ll f(ll n){
	ll val=n%mod30;
	ll p2=(val*val)%mod30;
	ll p4=(p2*p2)%mod30;
	return ( ((6*p4*val%mod30) +(15*p4)+ (10*p2*val%mod30)-val)%mod30 )/30 ;
}

inline ll r4th(ll i,ll j){
	return f(j)-f(i);
}

int main(){
    ll t,i,k,l,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&mod);
        mod30=30*mod;
        ll rt=sqrt(n),finl=0;
        ll next=n,prev=n+1;
        for (i = 2; i <rt; ++i){
        	prev=(l=n/i) + 1;
        	finl+=(i-1)*r4th(l,next);
        	next=l;
        }
        for (i = 1; i < prev ; ++i){
        	ll sqi=i*i%mod;
        	finl+=(sqi*sqi%mod)*(n/i)%mod;
        }
        printf("%lld\n", (mod+finl%mod)%mod );
    }
    return 0;
}