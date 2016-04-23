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

/////  This is completely written by me:  .  

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
    int t,a,b,s;
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> s;
    a=abs(a);
    b=abs(b);
    printf( (s-a-b)>=0 and (s-a-b)%2==0 ?"Yes\n":"No\n");


    return 0;
}