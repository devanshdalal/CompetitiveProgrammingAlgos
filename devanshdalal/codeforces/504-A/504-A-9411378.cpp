#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define endl ('\n')
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

/////  This is completely written by me: devansh dalal .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

pair<int,int> a[100000],ans[100000];
// vector<int> g[100000];

int main(){
    int t,k,n,l,p,q;
    ios_base::sync_with_stdio(0);

    cin >> n;
    queue<int> mq;
    for(int i=0;i<n;i++){
        cin >> p >> q;
        a[i]=make_pair(p,q);
        if (p==1){
        	mq.push(i);
        }
    }
    p=0;
    while(!mq.empty()){
    	int i=mq.front(); mq.pop();
    	if(a[i].F<1)continue;
    	int j=a[i].S;
    	ans[p]=make_pair(i,j);
    	p++;
    	a[i].F=0;
    	a[j].F--; a[j].S=a[j].S^i;
    	if (a[j].F==1)
    	{
    		mq.push(j);
    	}
    }
    cout << p << endl;
    for (int i = 0; i < p; ++i)
    {
    	cout << ans[i].F << " " << ans[i].S << endl;
    }
    // assert(p==n-1);

    return 0;
}