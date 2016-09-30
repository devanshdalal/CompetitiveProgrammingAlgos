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

char a[200000];

int main(){
    int t,k,l,p,q;
    io;

    cin >> t;
    while(t--){
        cin >> n>> k;
        cin >> a;
        int ans=0,*b=new int[n+1];
        for (int i = 0; i < n; ++i)
        {
        	if(i>0)b[i]=b[i-1]+b[i];
        	if ((a[i]=='G' and b[i]%2==0) or (a[i]=='R' and b[i]%2) )continue;
        	b[i]+=1;
        	b[min(n,i+k)]-=1;
        	ans+=1;
        }

        cout << ans << '\n';
    }
    return 0;
}