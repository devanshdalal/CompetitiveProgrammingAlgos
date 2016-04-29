#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 100007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}


int a[501],n,m,b[1011];

bool vis[501];

ll ans(std::vector<int> v1){
	ll mya=0;
	std::vector<int> v;
	for (int i = v1.size()-1; i >=0; --i)
	{
		v.pb(v1[i]);
	}

    // cerr << "here " << v.size() << " "  << n << endl;
	for (int i = 0; i < m; ++i)
	{
		int j=v.size()-1;
		for(; j>=0 and v[j]!=b[i] ;j--){
			mya+=a[v[j]];
		}
		v.erase(v.begin()+j);
		v.push_back(b[i]);
	}
	return mya;
}

int main() {
    ll t,p;
    io;

    cin >> n >> m ;
    fill(vis,vis+n+1,0);
    for (int i = 1; i <=n; ++i)
    {
    	cin >> a[i];
    }
    std::vector<int> v;
    for (int i = 0; i < m; ++i)
    {
    	cin >> p;
    	b[i]=p;
    	if (!vis[p])
    	{
    		vis[p]=1;
    		v.pb(p);
    	}
    }
    // for (int i = 0; i < v.size(); ++i)
    // {
    // 	cerr << v[i] << " ";
    // }
    // cerr << "here " << endl;
    cout << ans(v) << "\n";

    

  return 0;
}