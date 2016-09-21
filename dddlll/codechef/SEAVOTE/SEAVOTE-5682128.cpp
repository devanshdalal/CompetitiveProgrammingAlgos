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

/////  This is completely written by me: devansh dalal .  

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

    cin >> t;
    int a[10010];
    while(t--){
        cin >> n;
        for (int i =p=q=0; i < n; ++i)
        {
        	cin >> a[i];
        	if (a[i]>0)
        	{
        		p++;
        	}
        	q+=a[i];
        }
        if ( q>=100 and (q-p)<100 )
        {
        	cout << "YES\n";
        }else{
        	cout << "NO\n";
        }


        
    }
    return 0;
}