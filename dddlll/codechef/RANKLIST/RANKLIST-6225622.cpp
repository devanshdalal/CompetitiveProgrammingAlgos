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

ll g(ll n){
	ll x1=n+1,x2=x1;
	if (n&1)
	{
		x2/=2;
	}else{
		n/=2;
	}
	n%=mod;
	x1%=mod;
	x2%=mod;
	return ((n*x1)%mod)*x2%mod;
}

int main(){
    ll t,k,n,m,s;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> n >> s;
    	s=s-n;
    	ll i=2;
    	for (ll j=0; i <=n; ++i)
    	{
    		j++;
    		if (s-j<0)
    		{
    			break;
    		}
    		s=s-j;
    	}
    	cout << (n+1-i) << "\n";
    }

    return 0;
}