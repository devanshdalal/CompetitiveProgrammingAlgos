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


int a[301],n;
char b[301][301];

bool vis[301],com[301];

void dfs(int v){
	vis[v]=1;
	com[v]=1;
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i] and b[v][i]=='1')
		{
			dfs(i);
		}
	}
}

int main() {
    ll t,p,m,k,x;
    io;

    cin >> n ;
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	cin >> b[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	if (!vis[i])
    	{
    		fill(com,com+n,0);
    		dfs(i);
    		std::vector<int> v;
    		for (int j=0; j<n ; ++j)
    		{
    			if (com[j])
    			{
    				v.pb(a[j]);
    				/* code */
    			}
    		}
    		sort(v.begin(), v.end());
    		for (int j=0,l=0; j<n ; ++j)
    		{
    			if (com[j])
    			{
    				a[j]=v[l++];
    			}
    		}
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	cout << a[i] << " ";
    }






  return 0;
}