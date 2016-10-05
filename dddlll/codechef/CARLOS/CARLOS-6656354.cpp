#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 2000000003;

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

std::vector<int> g[300];
bool vis[300];
int type[300];

void dfs(int u,int t){
	type[u]=t;
	for (std::vector<int>::iterator i = g[u].begin(); i != g[u].end(); ++i){
		int v=*i;
		if (!vis[v])
		{
			vis[v]=1;
			dfs(v,t);
		}
	}
}

int tab[200001][201],a[200000];

int main(){
    ll t,n,m,k,x,y;
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
    	cin >> m >> k >> n;
    	memset(vis,0,sizeof(vis));
    	memset(type,0,sizeof(type));
    	for (int i = 1; i < 201; ++i)
    	{
    		g[i].clear();
    	}
    	for (int i = 0; i < k; ++i)
    	{
    		cin >> x >> y;
    		g[x].pb(y);
    		g[y].pb(x);
    	}
    	int label=1;
    	for (int i = 1; i <=m; ++i)
    	{
    		if (!vis[i]){
    			vis[i]=1;
    			dfs(i,label++);
    		}
    	}
    	for (int i = 0; i < n; ++i){
    		cin >> a[i];
    	}
    	for (int i = 1; i <=m; ++i){
    		if (type[i]==type[a[0]]){
    			tab[0][i]=1;
    		}else{
    			tab[0][i]=mod;
    		}	
    	}
    	tab[0][a[0]]=0;
    	for (int i = 1; i <n ; ++i)
    	{
    		int cm=mod;
    		for (int j = 1; j<=m ; ++j)
    		{
    			cm = min(cm,tab[i-1][j]);
    			if(j==a[i])tab[i][j]=cm;
    			else if (type[j]==type[a[i]])
    			{
    				tab[i][j]=cm+1;
    			}else{
    				tab[i][j]=mod;
    			}
    		}
    	}
    	int ans = mod;
    	for (int i = 1; i<=m; ++i)
    	{
    		ans = min(ans,tab[n-1][i]);
    	}
    	// for (int i = 0; i < n; ++i){
    	// 	for (int j = 1 ; j<=m; ++j){
    	// 		cerr << tab[i][j] << " ";
    	// 	}
    	// 	cerr << endl;
    	// }
    	cout << (ans==mod? -1 : ans) << endl; 
    }

    return 0;
}