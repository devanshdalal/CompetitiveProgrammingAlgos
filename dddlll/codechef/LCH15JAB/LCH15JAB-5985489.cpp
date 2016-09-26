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

char a[1001];
int b[1000];

int main(){
    int t,j,k,l,p,q;
    io;



    cin >> t;
    while(t--){
        cin >> a;
        l =strlen(a);
        fill(b,b+100,0);
        for (int i = 0; i < l; ++i)
        {
            b[a[i]-'a']++;
        }
        int i;
        for (i = 0; i < 26; ++i)
        {
            if (2*b[i]==l)
            {
                break;
            }
        }
        cout << (i!=26?"YES\n":"NO\n") ;
        
    }
    return 0;
}