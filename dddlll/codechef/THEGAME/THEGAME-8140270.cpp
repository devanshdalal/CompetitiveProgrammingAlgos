#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
// using namespace std;
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

int n,m;
char *a[100000];
bool *vis[100000];

int dfs(int x,int y){

	int res=1;
	if (y+1<m and a[x][y+1]=='o' and !vis[x][y+1] )
	{
		vis[x][y+1]=1;
		res+=dfs(x,y+1);
	}
	if (x+1<n and a[x+1][y]=='o' and !vis[x+1][y] )
	{
		vis[x+1][y]=1;
		res+=dfs(x+1,y);
	}
	if (y-1>=0 and a[x][y-1]=='o' and !vis[x][y-1] )
	{
		vis[x][y-1]=1;
		res+=dfs(x,y-1);
	}
	if (x-1>=0 and a[x-1][y]=='o' and !vis[x-1][y] )
	{
		vis[x-1][y]=1;
		res+=dfs(x-1,y);
	}
	return res;
}

int main(){
    ll t,k,l,p,q;
    std::ios_base::sync_with_stdio(0);
    clock_t start=clock();
    // a=new char[100000];

    std::cin >> t;
    while(t--){

    	std::cin >> n >> m ;
    	for (int i = 0; i < n; ++i)
    	{
    		a[i]=new char[m+1];
    		std::cin >> a[i];
    		vis[i]=new bool[m+1];
    		std::fill(vis[i],vis[i]+m,0);
    	}
		std::vector<int> part;
		// assert(a[0][0]=='o' and a[n-1][m-1]=='o');

		for (int i = 0; i<n; ++i)
		{
			for (int j = 0; j<m; ++j)
			{
				// assert(a[i][j]=='o' or a[i][j]=='#');
				if (a[i][j]=='o' and !vis[i][j])
				{
					vis[i][j]=1;
					part.pb(dfs(i,j));
				}
				// if (j==m-1 and i==n-1)
				// {
				// 	assert(vis[0][0]);
				// 	// assert(vis[n-1][m-1]);
				// }
			}
		}

		double ans=1.0;
		// std::cerr << part.size() << "\n";
		// for (int i = 0; i < part.size(); ++i)
		// {
		// 	std::cerr << part[i] << " ";
		// }std::cerr << "\n";
		for (int i = 1; i < part.size(); ++i)
		{
			ans += double(part[i])/double(part[i]+part[0]);
		}

		std:: cout << std::fixed << std::setprecision(10) << ans << "\n";

		for (int i = 0; i < n; ++i)
		{
			free(a[i]);
			free(vis[i]);
		}

    }


    // std::cerr << double(clock()-start)/CLOCKS_PER_SEC << "\n";

    return 0;
}