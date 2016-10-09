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
ll mod = 1000000000;

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

ll *ncr[4001],*rem[2001];

int main(){
    int t,k,n,m,p,q;
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 4001; ++i)
    {
    	ncr[i]=new ll[4001];
    	ncr[0][i]=0;
    }
    for (int i = 0; i < 2001 ; ++i)
    {
    	rem[i]=new ll[2001];
    }
    ncr[0][0]=1;
    for (int i = 1; i < 4001; ++i)
    {
    	ncr[i][0]=1;
    	for (int j = 1; j <i; ++j)
    	{
    		ll tmp=ncr[i-1][j-1]+ncr[i-1][j];
    		if (tmp>=mod)tmp-=mod;
    		ncr[i][j]=tmp;
    	}
    	ncr[i][i]=1;
    }
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll sum;
        for (int k = rem[0][0]=1; k <=m  ; ++k)
        {
        	rem[0][k]=0;
        }
        for (int i = 1; i <=n; ++i)
        {
        	sum = 0;
        	for (int j = 0; j <=m; ++j)
        	{
        		sum +=rem[i-1][j];
        		if(sum>=mod)sum-=mod;
        		// assert(ncr[m+j-1][j]==ncr[m+j-1][m-1]);
        		// assert(ncr[j+m-1][j]>=0);
        		// assert(ncr[j+m-1][j]<=mod);
        		// assert(sum<=mod);
        		rem[i][j]=ll(sum*ncr[j+m-1][j])%mod;
        		// assert(rem[i][j]>=0);
        		// cerr << rem[i][j] << " ";
        	}
        	// cerr << endl;
        }
        for (int j = sum= 0; j <=m; ++j)
        {
        	// cerr << rem[n][j] << endl;
        	sum+=rem[n][j];
        }
        // cout << (sum) << "\n";
        cout << (sum%mod) << "\n";
    }
    return 0;
}