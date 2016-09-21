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

inline void multiply(ll F[2][2], ll M[2][2]){
  ll x =  ((F[0][0]*M[0][0])%mod) + ((F[0][1]*M[1][0])%mod);
  ll y =  ((F[0][0]*M[0][1])%mod) + ((F[0][1]*M[1][1])%mod);
  ll z =  ((F[1][0]*M[0][0])%mod) + ((F[1][1]*M[1][0])%mod);
  ll w =  ((F[1][0]*M[0][1])%mod) + ((F[1][1]*M[1][1])%mod);
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = y>=mod?y-mod:y;
  F[1][0] = z>=mod?z-mod:z;
  F[1][1] = w>=mod?w-mod:w;
}

inline void multiply2(ll F[2][2]){
  ll x =  F[0][0] + F[0][1];
  ll y =  F[0][0];
  ll w =  F[1][0];
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = y;
  F[1][0] = y;
  F[1][1] = w;
}

void power(ll F[2][2], ll n){
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply2(F);
}

ll pre,nxt;
ll fib1(ll n){
  ll FF[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(FF, n-1);
  pre=FF[1][1];
  nxt=FF[1][0];
  return FF[0][0];
}

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
    io;

    cin >> t;
    while(t--){
        cin >> p >> q;
        cout << fib1( __gcd(p,q)  )<< '\n';


        
    }
    return 0;
}