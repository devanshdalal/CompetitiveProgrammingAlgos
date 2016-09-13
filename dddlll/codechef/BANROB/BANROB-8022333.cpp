#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
// using namespace std;
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

std::pair<ll,ll> a[100001];

#define BILLION 1000000000.0

int main(){
    int t,M;
    double p;
    std::ios_base::sync_with_stdio(0);


    std::cin >> t ;
    while(t--){
	    std::cin >> M >> p ;
	    
	    double ans = BILLION*(1.0 - (M&1?-1.0:1.0)*pow(p,M))/(1.0+p);

	    std::cout << std::fixed << std::setprecision(5) << ans << " " << BILLION - ans << "\n";

    }

    


    return 0;
}