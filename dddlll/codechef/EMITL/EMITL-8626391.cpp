#include <bits/stdc++.h>
#include <cstring>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
// typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

ll t,n;

int main(){
	// #ifndef USE_ONLINE_JUDGE 
	//    freopen("input.txt", "r", stdin);
	//    freopen("output.txt", "w", stdout);
	// #endif
    std::ios_base::sync_with_stdio(0);

    cin >> t;

    char s[200];

    int f[200];

    while(t--){
    	cin >> s;
    	// fill(f,f+200,0);
    	f['L']=f['T']=f['I']=f['M']=f['E']=0;
    	int len=strlen(s);
    	for (int i = 0; i < len ; ++i)
    	{
    		f[s[i]]++;
    	}
    	if (f['L']>=2 and f['T']>=2 and f['I']>=2 and f['M']>=2 and (f['E']>=2 or (f['E']>=1 and len==9)  ))
    	{
    		cout << "YES\n";
    	}else{
    		cout << "NO\n";
    	}
    }



    return 0;
}