#include <bits/stdc++.h>
#include <cstring>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define PRIME 23
#define M 100001
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

ll n,k;
ll a[265500];
ll d[265500];

int main() {
		
	std::ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	d[0]=a[0];
	for (int i = 1; i < n ; ++i)
	{
		d[i]=a[i]+min(d[i-1],i>=2?d[i-2]:0) ;
		d[i]=min ( d[i] , a[i]+(i>=3?d[i-3]:0) );
		// cout << d[i] << " ";
	}
	// cout << endl;

	ll ans = min(min(d[n-1],n>=2?d[n-2]:mod),n>=3?d[n-3]:mod);

	cout << ans << endl;

	return 0;
}