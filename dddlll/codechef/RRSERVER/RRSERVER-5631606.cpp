#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define VI vector <int>
#define VVI vector < 	vi >
#define PII pair <int,int>
#define VPII vector < pii >
#define MI map < int, int >
#define SI set< int >
#define clr(x) x.clear()
#define sz(x) ((int) x.size())
#define F first
#define S second
#define abs(a) ((a<0)?(-a):a)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define mem1(a,c,b) (memset(a, c, sizeof(a[0]) * b))
#define mem2(a,d,b,c) (memset(a, d, sizeof(a[0][0])*b*c))
#define fastio ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 10000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int L[3001][3001];  // Create a tab to store results of subproblems 

void lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   for (i = 0; i < n; i++)
      L[i][i] = 1;
    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    // return L[0][n-1];
}

ll n,m;
bool g[21][21];

struct tabl
{
	ll cost,rv,cut,siz;
} tab[1<<21];

int cut(int j,int s1){
	int ans=0;
	for (int i=0; i <n; ++i)
	{
		if((1<<i)&s1 and g[i][j])ans+=1;
	}
	return ans;
}

int cut2(int j,int s1){
	int ans=0;
	for (int i=0; i <n; ++i)
	{
		if(((1<<i)&s1)==0 and g[i][j])ans+=1;
	}
	return ans;
}

ll minLA(){
	for (int i =1; i<(1<<n); ++i)
	{
		tab[i].cost=mod;
		tab[i].siz=1000;
	}
	tab[0].cost=0;
	tab[0].cut=0;
	tab[0].siz=0;
	for (int i = 0; i <(1<<n); ++i)
	{
		for (int j =0; j<n ; ++j){
			int k=(1<<j)|i;
			// cerr << k << " ";
			if(((1<<j)&i)==0 and tab[k].siz==1000){
				tab[k].siz=1+tab[i].siz;
			}
		}
	}
	// for (int i = 0; i <(1<<n); ++i)
	// {
	// 	cerr << i <<","<< tab[i].siz << " ";
	// }
	for (int k=1; k<=n; ++k)
	{
		for (int i =0; i<(1<<n); ++i){
			if(tab[i].siz==k-1){
				// cerr << "hee " << n <<" "<< (2<<n) << endl;
				int c1=tab[i].cut;
				int nc=c1+tab[i].cost;
				for (int j=0; j<n ; ++j)
				{
					int l=(1<<j)|i;
					if(((1<<j)&i)==0 and tab[l].cost>nc){
						tab[l].cost=nc;
						tab[l].cut=c1-cut(j,i)+cut2(j,i);
					}
				}
			}
		}
	}
	// for (int i = 0; i <(1<<n); ++i)
	// {
	// 	cerr << i <<","<< tab[(2<<n)-1].cost << " 	";
	// }
	return tab[(1<<n)-1].cost;
}

int main(){
    	
    int p,q;
	cin >> n >> m ;
	memset(g,0,sizeof(g));
	for (int i = 0; i < m; ++i)
	{
		cin >> p >> q;
		p--; q--;
		g[p][q]=g[q][p]=1;
	}
	cout << minLA() << endl;

    return 0;
}