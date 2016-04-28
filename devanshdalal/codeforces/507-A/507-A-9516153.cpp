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

int main(){
    int t,j,k,l,p,q;
    io;
    int sum=0;
    pair<int,int> a[1000];

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        a[i].S=i;
        cin >> a[i].F;
    }
    sort(a,a+n);
    int i;
    for ( i= 0; i < n; ++i)
    {
        if (sum+a[i].F>k)
        {
            break;
        }
        sum+=a[i].F;
    }
    cout << i << endl;
    for (int j = 0; j < i; ++j)
    {
        cout << a[j].S+1 << " ";
    }
    return 0;
}