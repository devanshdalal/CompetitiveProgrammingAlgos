#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
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

bool eq(char a[11],char b[11]){
	if(strlen(a)!=strlen(b))return 0;
	for (int i = strlen(b)-1; i>=0 ; --i)
	{
		if (a[i]!=b[i])return 0;
	}
	return 1;
}

ll a,b,c;
ll eval(ll x,ll y){
	return a*x+b*y+c>0?1:-1;
}

int main(){
    ll x0,y0,x1,y1;
    io;

	cin >> x0 >> y0;
	cin >> x1 >> y1;
	cin >> m;
	int ans=0;
	for (int i = 0; i < m; ++i)
	{
		cin  >> a >> b >> c;
		if (eval(x0,y0)*eval(x1,y1)<0)
		{
			ans++;
		}
	}
	cout << ans ;
	

    return 0;
}