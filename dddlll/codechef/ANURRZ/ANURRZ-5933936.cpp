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

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

ll b[1001],a[1001][1001];

int main(){
    int t,k,n,l,p,q;
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <=n; ++i)
        {
        	cin >> b[i];
        }
        for (int i = 0; i <=n; ++i)
        {
        	for (int j= 0; j<=b[i]+1; ++j)
        	{
        		a[i][j]=0;
        	}
        }
        a[1][1]=1;
        for (int i=2; i <=n; ++i)
        {
        	ll sum=0;
        	for (int j=b[i-1]+1; j>0; --j)
        	{
        		sum+=a[i-1][j-1];
        		if(sum>=mod)sum-=mod;
        		if(j<=b[i])a[i][j]=sum;
        	}
        	// for (int j=1; j<=b[i-1]+1; ++j)
        	// {
        	// 	cerr << a[i][j] << " ";
        	// }
        	// cerr << endl;
        }
        ll ans=0;
        for (int i = 1; i <=b[n]; ++i)
        {
        	ans+=a[n][i];
        }
        cout << (ans%mod) << endl;



        
    }
    return 0;
}