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

ll a[101010];

inline ll f(ll n){
	return n*(n+1)/2;
}

int main(){
    ll n,m,k,q,t;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> n >> k;
    	for (int i = 0; i < k; ++i)
    	{
    		cin >> a[i];
    	}
    	if (k==0)
    	{
    		// cout << ll(f(n)+ll(1) ) << "\n";
    		cout << ((f(n)+1)%2==0?"Mom\n":"Chef\n") ;
    	}else{
    		sort(a,a+k);
	    	int i=0;
	    	ll sum=0;
	    	bool trivial=0;
	    	if (a[0]==1)
	    	{
	    		trivial=1;
	    	}
	    	for (; i < k; ++i){
	    		ll temp = f(a[i]-1)-(i>0?f(a[i-1]):0);
	    		sum+=temp;
	    		if (sum<a[i]){
	    			break;
	    		}
	    	}
	    	if (i==k)
	    	{
	    		sum+= f(n)-f(a[k-1]);
	    	}

	    	if (trivial)
	    	{
	    		// cerr << i << " " << (sum+1) << "\n";
	    		cout << (1%2==0?"Mom\n":"Chef\n") ;
	    	}else{
	    		// cerr << i <<" "<< trivial << " " << (sum+1) << "\n";
	    		cout << ((1+sum)%2==0?"Mom\n":"Chef\n") ;
	    	}
    		
    	}


    }
    

    return 0;
}