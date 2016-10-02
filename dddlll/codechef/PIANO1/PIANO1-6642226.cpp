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

char a[1000];

int main(){
    ll t,i,n,m,l;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> a ;
        l = strlen(a);
        for (int i =m= 0; i < l; ++i)
        {
            if (a[i]=='T')
            {
                m+=2;
            }else{
                m++;
            }
        }
        cin >> n;
        n=12*n;
        ll ans =0;
        for (int i = 1; i*m <= n  ; ++i)
        {
            ans +=n-i*m;
        }
        cout << ans << "\n";
    }

    return 0;
}