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

int main(){
    ll t,n;
    std::ios_base::sync_with_stdio(0);


    string s;
    std::cin >> s ;
    n=s.length();

    reverse(s.begin(), s.end());

    int ans=1;
    for (int i = 0; i < s.length(); ++i)
    {
    	ans+= s[i]=='7'?(1<<i):0;
    }

    for (int i = 1; i <n ; ++i)
    {
    	ans += (1<<i);
    }

    cout << ans << endl;

    return 0;
}