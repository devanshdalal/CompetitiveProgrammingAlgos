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

int n,m;

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
    int t,j,k,l,p,q;
    std::ios_base::sync_with_stdio(0);

    std::cin >> t;
    std::pair<int,int> a[500*500+1];
    int b[501][501];
    while(t--){
        int ans=0;
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cin >> p;
                a[ p ]=std::make_pair(i,j);
            }
        }
        for (int i = 2; i <= n*n; ++i)
        {
            ans += std::abs(a[i].first-a[i-1].first)+std::abs(a[i].second-a[i-1].second);
        }
        std::cout << ans << "\n";
        
    }

    return 0;
}