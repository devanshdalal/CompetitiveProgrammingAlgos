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

    cin >> n >> k;
    ll a[101];
    ll mx=1,mn=1000;
    for (int i = 1; i <=n; ++i)
    {
    	cin >> a[i];
    	mx=max(a[i],mx);
    	mn=min(a[i],mn);
    }
    if (mx-mn<=k)
    {
    	cout << "YES\n";
    	for (int i =1; i <=n; ++i)
    	{
    		int color=1;
    		for (int j= 0; j <a[i] ; ++j)
    		{
    			if (j<=mn)
    			{
    				cout << "1 ";
    			}else{
    				cout << ++color <<" ";
    			}
    		}
    		cout << "\n";
    	}
    }else{
    	cout << "NO\n";
    }

    return 0;
}