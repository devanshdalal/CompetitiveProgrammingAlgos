#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 10000001
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
    ll t,m,A,B;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> A >> B ;
        bool done =0;
        do{
            m = __gcd(A,B);
            B = B/m;
            if (B==1)
            {
                done=1;
            }
        }while(m>1);
        cout << (done?"Yes\n":"No\n")  ;
    }

    return 0;
}