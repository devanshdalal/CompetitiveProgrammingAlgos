#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 10000001
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

/////  This is completely written by me:  .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

ll a[100000];

inline ll mymod(ll x,ll y){
	ll prod=x*y;
	if (prod<mod)return prod;
	return prod%mod;
}

int main(){
    ll t,i,n,m,s;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> n ;
        ll ans =0;
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> a[i];
    	}
    	sort(a,a+n);
    	ll last=mpow(2,n-1),first=1,inv2=mpow(2,mod-2);
    	for (int i = 0; i < n; ++i)
    	{
			ans += (first - last)*a[i]%mod;
			first=mymod(first,2);
			last=last*inv2%mod;
    	}
        cout << (ans%mod + mod)%mod << "\n";
    }

    return 0;
}