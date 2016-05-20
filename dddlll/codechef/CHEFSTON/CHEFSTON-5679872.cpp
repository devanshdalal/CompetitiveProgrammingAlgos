#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int main(){
    ll t,k,l,p,n,m;
    io;

    cin >> t;
    ll a[101010];
    while(t--){
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
        	cin >> a[i];
        }
        ll ans=-1;
        for (int i = 0; i < n; ++i)
        {
        	cin >> p;
        	if (ll(k/a[i])*p>ans)
        	{
        		ans=ll(k/a[i])*p;
        	}
        }
        cout << ans << "\n";


        
    }
    return 0;
}