#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << std::endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
ll mod = 1000000007;
#define x (std::sqrt(2))
#define y (std::sqrt(3))
#define xy (std::sqrt(6))
// #define x (std::sqrt(2)/2.0)
// #define y (std::sqrt(3)/2.0)
// #define xy (std::sqrt(6)/2.0)

inline ll mpow(ll b, ll ex){
    if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    ll i , k , s;
    double ai, bi;

    std::cin >> i >> k >> s;
    std::cin >> ai >> bi;

    if (abs(k-i)&1)
    {
        double temp=ai*(x-xy)+bi*(x+xy);
        bi=ai*(x+xy)+bi*(-x+xy);
        ai=temp;
        i++;
    }

    double Q = std::exp(std::log(ai+bi)+double(2*(k-i)-s)*log(2) );


    std::cout << std::fixed << std::setprecision(6) << Q << "\n";


    return 0;
}