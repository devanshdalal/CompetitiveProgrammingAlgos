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

ll a[100001],*rem[100001];
int temp[202][100002],minV[100002];

int main(){
    int t,n,k,m,l,r,c,p,q;
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n >> k >> m;
        for (int i = 1; i <=n; ++i)
        {
            cin >> a[i];
            minV[i]=1000;
        }
        for (int i = 0; i < 201; ++i)
        {
            memset( temp[i],0,sizeof(temp[i][0])*(n+1) );
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> l >> r >> c;
            temp[c][l]++;
            temp[c][r+1]--;
        }
        for (int i = 1; i < 201 ; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                temp[i][j]+=temp[i][j-1];
                // cerr << temp[i][j] << " ";
                if (temp[i][j]>0 and minV[j]>i)
                {
                    minV[j]=i;   
                }
            }//cerr << endl;
        }
        // for (int i = 0; i <=n; ++i)
        // {
        //     cerr << minV[i] << " " ;
        // }cerr << endl;
        for (int i = 0; i <=n; ++i)
        {
            if(rem[i])free(rem[i]);
            rem[i]=new ll[k+1];
        }
        for (int i = 0; i <=k; ++i)
        {
            rem[0][i]=0;
        }

        for (int i = 1; i <=n; ++i)
        {
            for (int j = 0; j <=k; ++j)
            {
                rem[i][j]=rem[i-1][j]+a[i];
                if (a[i]<0 and j>=minV[i] )
                {
                    rem[i][j]=max(rem[i][j],rem[i-1][ j-minV[i] ]);   
                }
            }
        }
        cout << rem[n][k] << endl;
        
    }
    return 0;
}