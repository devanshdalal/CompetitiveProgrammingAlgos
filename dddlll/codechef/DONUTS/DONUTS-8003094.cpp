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
// using namespace std;
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
    std::ios_base::sync_with_stdio(0);

    std::cin >> t;
    int a[500000];
    while(t--){
        std::cin >> n >> m;
        int ans=0;
        for (int i = 0; i <m; ++i)
        {
        	std::cin >> a[i] ;
        }
        std::sort(a,a+m);
        for (int i = 0,j=m-2; j>=i ;)
        {
        	if (a[i]>0)
        	{
        		a[i]--;
        		j--;
        		ans++;
        	}else if(j>i){
        		i++;
        	}else{
        		break;
        	}
        }

        std::cout << ans  << "\n";
        
    }

    return 0;
}