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

ll g(ll n){
	ll x=n+1,y=n;
	if (n&1)
	{
		x/=2;
	}else{
		y/=2;
	}
	n%=mod;
	x%=mod;
	y%=mod;
	return (n*x%mod)*y%mod;
}

int main(){
    ll t,k,n,m,lmt;
    ios_base::sync_with_stdio(0);

    cin >> n >> mod;
    ll p[n+1];
    ll *fact=new ll[mod+1],*sum=new ll[mod+1];
    for (int i = 0; i < n; ++i)
    {
    	cin >> p[i];
    }
    for (lmt = fact[sum[0]=0]=1; lmt < mod+1 ; ++lmt)
    {
    	fact[lmt]=fact[lmt-1]*lmt%mod;
    	sum[lmt]=(sum[lmt-1]+fact[lmt]*lmt)%mod;
    	if(fact[lmt]==0)break;
    	// cerr << sum[lmt] << " ";
    }
    ll ans=0;
    for (int i = 0; i < n; ++i)
    {
    	// cerr << p[i] << " p " << (p[i]<lmt? sum[p[i]]: sum[lmt]) << " " << g(p[i]) << " " << p[i]*p[i]*(p[i]+1)/2 << "     ";
    	ans+=(p[i]<lmt? sum[p[i]]: sum[lmt]) + g(p[i]);
    }
    // cerr << "dscsd" << endl;
    cout << ans%mod << endl;

    return 0;
}