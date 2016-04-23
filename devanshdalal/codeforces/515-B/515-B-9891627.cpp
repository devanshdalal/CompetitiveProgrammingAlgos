#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
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

int g[201][201];
bool happy[10001],vis[10011];
int a,b,s,n,m;

void dfs(int u){
	for (int i = 0; i <m+n ; ++i)
	{
		if ( !vis[i] and g[u][i])
		{
			vis[i]=1;
			happy[i]=1;
			dfs(i);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    fill(happy,happy+sizeof(happy),0);
    fill(vis,vis+sizeof(vis),0);
    memset(g,0,sizeof(g));
    cin >> a ;
    for (int i = 0; i < a; ++i)
    {
    	cin >> s;
    	happy[s]=1;
    }
    cin >> b ;
    for (int i = 0; i < b; ++i)
    {
    	cin >> s;
    	happy[n+s]=1;
    }
    for (int i = 0; i < n*m; ++i)
    {
    	int u=i%n,v=n+(i%m);
    	g[u][v]=g[v][u]=1;
    }
    for (int i = 0; i < m+n; ++i)
    {
    	if (happy[i] and !vis[i])
    	{
    		dfs(i);
    	}
    }
    int i;
    for (i = 0; i < m+n; ++i)
    {
    	if (happy[i]==0)
    	{
    		break;
    	}
    }
    printf(i==m+n?"Yes\n":"No");

    return 0;
}