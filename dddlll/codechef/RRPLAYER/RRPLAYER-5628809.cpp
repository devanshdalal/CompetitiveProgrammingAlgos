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

int L[3001][3001];  // Create a table to store results of subproblems 

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

int main(){
    	
    ll t,n,p,q,m,j;
    	scanf("%lld",&t);
    dbl h[3001];
    h[1]=1.0;
    for (int i =2; i <3001; ++i)
    {
    	h[i]=h[i-1]+1.0/i;
    }
    while(t--){
    	scanf("%lld",&n);
    	printf("%0.8lf\n", h[n]*dbl(n) );

    }

    return 0;
}