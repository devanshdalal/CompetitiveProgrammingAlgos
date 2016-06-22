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
ll a[65500];

int main() {
		
	std::ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a,a+n);

	ll ans=0;

	for (int i = 0,j=0; i < n and j<n; ++i)
	{
		while(j<n and a[j]-a[i]<k)j++;
		ans += n-j;
		// if (j<n and a[j]-a[i]>=k)
		// {
		// }
	}

	cout << ans << endl;

	return 0;
}