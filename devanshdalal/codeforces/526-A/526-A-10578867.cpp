#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000003;

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

ll fact[mod],ifact[mod],inv[mod];

// ll ncr(ll n,ll r){
//     if (n<r)
//     {
//         return 0;
//     }
//     return (fact[n]*ifact[n-r]*ifact[r])%mod;
// }

char a[1000];

int main(){
    ll t,n,m,l,r;
    ios_base::sync_with_stdio(0);

    // for (int i =fact[0]=ifact[0]=inv[1]=1; i<mod ; ++i)
    // {
    //     fact[i]=i*fact[i-1]%mod;
    //     if(i>1)inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    //     ifact[i]=ifact[i-1]*inv[i]%mod;
    // }
    cin >> n;
    cin >> a;
    bool done=0;
    for (int i = 0; i < n and !done; ++i)
    {
    	if (a[i]=='*')
    	{
    		for (int d = 1; d<n and !done ; ++d)
    		{
    			int c=0;
    			for (int j = i+d;a[j]=='*' and j <n and !done ; j+=d,c++)
    			{
    				// cerr << "c " << c << " "  << i <<" " << j << endl;
    				if (c==3)
    				{
    					done=1;
    				}
    			}
    		}
    	}
    }
    cout << (done?"yes":"no") << endl;

    return 0;
}