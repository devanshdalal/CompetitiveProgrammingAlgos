#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 100007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}


int main() {
    ll t,p,n,m,k,x;
    io;

    cin >> n ;
    int a[301];
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i] ;
    }
    bool done=0;
    while(!done){
    	int i;
    	done=1;
    	for (i = 0; i < n-1; ++i)
    	{
    		if (a[i]>0)
    		{
    			a[i]--;
    			cout << "P";
    			done=0;
    		}
    		cout << "R";
    	}
    	if (a[i]>0)
		{
			a[i]--;
			cout << "P";
    			done=0;
		}
		cout << "L";

    	for ( i = n-2; i>0 ; --i)
    	{
    		if (a[i]>0)
    		{
    			a[i]--;
    			cout << "P";
    			done=0;
    		}
    		cout << "L";
    	}
		
		// if (a[i]>0)
		// {
		// 	a[i]--;
		// 	cout << "P";
		// }
		// cout << "R";    	
    }


  return 0;
}