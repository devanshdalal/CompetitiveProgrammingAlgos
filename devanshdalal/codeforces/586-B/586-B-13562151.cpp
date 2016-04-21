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
using namespace std;
ll mod = 1000000007;

int n,m;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int a[1000];
int b[1000];
int c[1001];

int main(){
    int t,j,k,l,p,q;
    std::ios_base::sync_with_stdio(0);

    
    std::cin >> n;
    b[0]=a[0]=0;
    for (int i = 1; i < n; ++i)
    {
    	cin >> a[i];
    	a[i]+=a[i-1];
    }
    for (int i = 0; i < n-1; ++i)
    {
    	cin >> b[i];
    }
    b[n-1]=0;
    for (int i = n-2; i>=0; --i)
    {
    	b[i]+=b[i+1];
    }
    for (int i = 0; i < n; ++i)
    {
    	cin >> c[i];
    }
    int ans = INT_MAX;



    // for (int i = 0; i < n; ++i)
    // {
    // 	cerr << a[i] << " ";
    // }
    // cerr << endl;

    // for (int i = 0; i < n; ++i)
    // {
    // 	cerr << b[i] << " ";
    // }
    // cerr << endl;

    // for (int i = 0; i < n; ++i)
    // {
    // 	cerr << c[i] << " ";
    // }
    // cerr << endl;

    for (int i = 0; i < n; ++i)
    {
    	for (int j = i+1; j < n; ++j)
    	{
    		ans  = min(a[i]+c[i]+b[i] + a[j]+c[j]+b[j],ans);
    	}
    }
        
	cout << ans << endl;

    return 0;
}