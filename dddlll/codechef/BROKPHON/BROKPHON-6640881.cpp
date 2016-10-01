#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 10000001
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

int a[100000];

int main(){
    ll t,k,n,m,s;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> n ;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll ans=0;
        int j=0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i]!=a[i-1])
            {
                ans++;
                if(j==0)ans++;
                j=1;
            }else{
                j=0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}