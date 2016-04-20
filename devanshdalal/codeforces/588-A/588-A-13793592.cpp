#include <bits/stdc++.h>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
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

ll n;
ll a[100000],p[100000];

int main(){
    std::ios_base::sync_with_stdio(0);

    cin >> n;

    ll ans =0, meatcost=10000;

    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i] >> p[i];
    	if (p[i]<meatcost)
    	{
    		meatcost=p[i];
    	}
    	ans += meatcost*a[i];
    }

    cout << ans ;

    return 0;
}