#include <bits/stdc++.h>
#include <cstring>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define PRIME 23
#define M 100001
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

ll l,p,q;

int main(){
	// #ifndef USE_ONLINE_JUDGE 
	//    freopen("input.txt", "r", stdin);
	//    freopen("output.txt", "w", stdout);
	// #endif
    std::ios_base::sync_with_stdio(0);

    cin >> l ;
    cin >> p ;
    cin >> q;

    double t = double(l)/double(p+q);

    cout << std::fixed << setprecision(10) << double(l) - q*t << endl;


    return 0;
}