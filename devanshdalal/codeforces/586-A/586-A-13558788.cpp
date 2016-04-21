#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
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

int a[1000];

int main(){
    int t,j,k,l,p,q;
    std::ios_base::sync_with_stdio(0);


        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
        	cin >> a[i];
        }
        int i=0,ans=0;
        for(;i<n and a[i]==0;i++);
        for(;n-1>=i and a[n-1]==0;n--);
        	// cerr << "hwrw" << endl;
        for (; i < n;)
        {
        	// cerr << i << endl;
        	if(a[i]==0){
        		int c=1,j=i+1;
        		while(j<n and a[j]==0){
        			c++;
        			j++;
        		}
        		if(c<=1){
        			ans++;
        		}
        		i=j;
        	}else{
        		ans++;
        		i++;
        	}
        }
        cout << ans << endl;

    return 0;
}