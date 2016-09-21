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

int main(){
    int t,j,k,l,p,q,n;
    io;

    cin >> n;
    ll a[n],b[n],c[n],sum=0;
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    	sum+=a[i];
    }
    ll ans=0;
    if (sum%3==0)
    {
    	ll t1=0,t2=a[n-1];
    	c[n-1]= (a[n-1]==sum/3);
	    for (int i = n-2; i >=0; --i)
	    {
	    	t2+=a[i];
	    	c[i]=c[i+1]+ (t2==sum/3?1:0);
	    }
	    for (int i = 0; i < n-1; ++i)
	    {
	    	t1+=a[i];
	    	if(t1==sum/3)ans+= (sum==0?c[i+1]-1:c[i+1]);
	    	// cerr << t1 << " " << sum/3 << " " << c[i+1] << endl;
	    }
    }
    cout << ans << endl;


    

    return 0;
}