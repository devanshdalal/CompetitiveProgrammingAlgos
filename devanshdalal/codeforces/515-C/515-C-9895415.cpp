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

int g[201][201];
bool happy[10001],vis[10011];
int l,n,m;

void dfs(int u){
	for (int i = 0; i <m+n ; ++i)
	{
		if ( !vis[i] and g[u][i])
		{
			vis[i]=1;
			happy[i]=1;
			dfs(i);
		}
	}
}

char a[29];
int num[11];

void add(int i){
	switch(i){
		case 2:
		case 3:
		case 5:
		case 7: num[i]++; break;
		case 4: num[2]+=2; break;
		case 6: num[2]++;
				num[3]++; break;
		case 8: num[2]+=3; break;
		case 9: num[3]+=2; break;
	}
}

void sub(int i,int k){
	switch(i){
		case 2:
		case 3:
		case 5:
		case 7: num[i]-=k; break;
		case 4: num[2]-=2*k; break;
		case 6: num[2]-=k;
				num[3]-=k; break;
		case 8: num[2]-=3*k; break;
		case 9: num[3]-=2*k; break;
	}
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n ;
    cin  >> a;
    l =strlen(a);
    for (int i = 0; i < l; ++i)
    {
    	int j=a[i]-'0';
    	for (; j>1 ;--j)
    	{
    		add(j);
    	}
    }
    std::vector<int> ans;
    for (int i = 7; i>1 ; --i)
    {
    	for (int j = 0; j < num[i]; ++j)
    	{
    		ans.pb(i);
    	}
    	if (num[i]>0)
    	{
    		int k=num[i];
    		for (int j = i; j>1  ; j--)
    		{
    			sub(j,k);
    		}
    	}
    }
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << ans[i] ;
    }

    return 0;

}