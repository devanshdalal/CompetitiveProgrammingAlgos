#include <bits/stdc++.h>
#include <cstring>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define PRIME 23
#define M 100001
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
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

ll n,q;

int main(){
	// #ifndef USE_ONLINE_JUDGE 
	//    freopen("input.txt", "r", stdin);
	//    freopen("output.txt", "w", stdout);
	// #endif
    std::ios_base::sync_with_stdio(0);

    cin >> n >> q ;

    string s;

    cin >> s;
    char change[200];
    for (int i = 0; i < 200; ++i)
    {
    	change[i]=i;
    }
    char c1,c2;
    while(q--){
    	cin >> c1 >> c2;
    	if (c1==c2)continue;
    	for (int i = 'a'; i <= 'z'; ++i)
    	{
    		if (change[i]==c1)
    		{
    			change[i]=c2;
    		}else if (change[i]==c2)
    		{
    			change[i]=c1;
    		}
    	}
    }


    for (int i = 0; i < s.length(); ++i)
    {
    	s[i]=change[s[i]];
    	// cerr << change[s[i]] ;
    }

    cout << s;


    return 0;
}