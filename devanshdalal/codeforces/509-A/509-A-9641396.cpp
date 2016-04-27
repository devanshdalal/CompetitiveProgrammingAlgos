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

int main(){
    int t,k,n,l,p,q;
    ios_base::sync_with_stdio(0);

    cin >> n;
    ll a[11][11];
    for (int i = 1; i <=n; ++i)
    {
    	a[i][1]=a[1][i]=1;
    	a[i][0]=a[0][i]=0;
    }
    for (int i = 2; i <=n; ++i)
    {
    	for (int j= 2; j <=n; ++j)
    	{
    		a[i][j]=a[i-1][j]+a[i][j-1];
    	}
    }
    cout << a[n][n] ;
    return 0;
}