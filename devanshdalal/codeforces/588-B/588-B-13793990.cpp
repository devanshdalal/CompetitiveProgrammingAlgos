#include <bits/stdc++.h>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
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

std::vector<ll> primeFactors(ll n)
{
	std::vector<ll> v;
    if (n%2 == 0)
    {
        v.push_back(2);
        while(n%2==0)
        n = n/2;
    }
 
    for (ll i = 3; i*i <= n; i = i+2)
    {
    	if (n%i==0)
    	{
        	v.push_back(i);
        	n/=i;
	        while (n%i == 0)
	        {
	            n = n/i;
	        }
    	}
    }
 
	if(n>1)v.push_back(n);
	return v;
}

ll n;

int main(){
    std::ios_base::sync_with_stdio(0);

    cin >> n;

    std::vector<ll> v=primeFactors(n);

    ll ans =1;
    for (std::vector<ll>::iterator i = v.begin(); i != v.end(); ++i)
    {
    	ans = ans*(*i);
    }
    cout << ans ;


    return 0;
}