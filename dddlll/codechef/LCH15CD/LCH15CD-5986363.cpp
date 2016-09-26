#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
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
        if (ex&1)r=(r * b);
        ex = ex >> 1;
        b = (b * b);}
    return r;
}

char a[1001];
int b[1000];

int main(){
    int t,N,D;
    io;



    cin >> t;
    while(t--){
        cin >> N >> D;
        ll pd[20];
        for (int i =pd[0]= 1; i <=N; ++i)
        {
            pd[i]=pd[i-1]*D;
        }
        int dest=pd[N];
        ll dp[dest];
        memset(dp,mod*mod,sizeof(dp));
        dp[0]=0;
        for (int i = 1; i < dest ; ++i)
        {
            for (int j=0; i-pd[j]>=0 and j <N ; ++j)
            {
                ll c1=0,c2=0;
                for (int k = 0,l=i; l>0 and k < N ; ++k)
                {
                    c1=c1^(l%D);
                    c2=c2+(l%D);
                    l/=D;
                }
                dp[i]=min(dp[i],dp[i-pd[j]]+c1*c2);
            }
        }
        cout << dp[dest-1] << endl;

        
    }
    return 0;
}