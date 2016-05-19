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

int *a;

inline ll mpow(ll base, ll exponent)
{
	if (base==1)return 1;
    ll result = 1;
    while (exponent ){
        if (exponent&1)result = (result * base)%mod;
        exponent = exponent >> 1;
        base = (base * base)%mod;
    }
    return result;
}

int main(){
    ll t,i,j,l,m,p,q,n,L,R;
    scanf("%lld",&t);
    a=new int[10001000];
    while(t--){
        scanf("%lld %lld %lld %lld",&n,&m,&L,&R);
        ll ans=0;
        // if (max(m,n)>1000)
        // {
        // 	printf("1\n" );
        // 	continue;
        // }


        memset(a+L,0,sizeof(a[0])*(m-L+1));
        // memset(a,0,sizeof(a[0])*(m+1));
        // for (i = L; i <=m; ++i)
        // {
        // 	cerr << a[i] << " ";
        // }cerr << endl;
        for (i = L; i<=R; ++i)
        {
    		// cerr<< ans << "," << a[i] << endl;
        	if (a[i]==1)continue;
    		ans= (ans + mpow(m/i,n)*(1-a[i]))%mod;
    		for (j=2*i; j<=m; j+=i){
    			a[j]+=(1-a[i]);
    		}
        }

        // memset(a+R,0,sizeof(a[0])*(m-R+1));
        // memset(a,0,sizeof(a[0])*(m+1));
        for (i = R+1; i<=m; ++i)
        {
        	if (a[i]==0)continue;
    		ans= (ans - mpow(m/i,n)*a[i])%mod;
    		for (j=2*i; j<=m; j+=i){
    			a[j]-=a[i];
    		}
        }
        
        printf("%lld\n", ((ans%mod)+mod)%mod);
    }
    return 0;
}