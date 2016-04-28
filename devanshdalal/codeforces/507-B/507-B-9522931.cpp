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

ll dis(ll x,ll y ){
    return x*x+y*y;
}

int main(){
    ll r,x,y,x1,y1;
    io;

    cin >> r >> x >> y >> x1 >> y1;

    ll d=dis(x-x1,y-y1),ans;
    // if (p*p==d and p%(2*r)==0)
    // {
    //     ans=p/(2*r);
    // }else{
    // }
    // cerr << x-x1 << " " << y-y1 << " " << d << endl;
        ans= ceil( sqrt(d)/(2.0*r));
    cout << ans << "\n";
    


    return 0;
}