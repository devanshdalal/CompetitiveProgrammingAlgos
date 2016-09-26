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

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int a[1001];

int main(){
    int t,k,n,l,p,q;
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
        	cin >> a[i];
        }
        sort(a,a+n);
        ll sum=0;
        int i;
        for (i = n-1; i>0; )
        {
        	sum+=a[i]+a[i-1];
        	i-=4;
        }
        if(i==0)sum+=a[0];
        if (n<=2)
        {
        	sum=0;
        	for (int i = 0; i < n; ++i)
        	{
        		sum+=a[i];
        	}
        }
        cout << sum << endl;


        
    }
    return 0;
}