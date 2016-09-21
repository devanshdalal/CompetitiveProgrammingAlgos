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

pair<int,int> a[101010];


int main(){
    ll n,q,p,t;
    ios_base::sync_with_stdio(0);

    cin >> t ;

    while(t--){
    	cin >> n ;
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> p >> q ;
    		a[i]=make_pair(q,p);
    	}
    	sort(a,a+n);
    	int cur=-1,ans=0;
    	for (int i = 0; i < n; ++i)
    	{
    		if (cur<a[i].S)
    		{
    			cur=a[i].F;
    			ans++;
    		}
    	}
    	cout << ans << "\n";


    }
    

    return 0;
}