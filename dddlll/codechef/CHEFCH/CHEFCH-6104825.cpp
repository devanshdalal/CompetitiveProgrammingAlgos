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

int main(){
    int t,k,n,l,p,q;
    ios_base::sync_with_stdio(0);

    cin >> t;
    char a[100001];
    while(t--){
        cin >> a;
        l=strlen(a);
        int a1=0,a2=0;
        for (int i = 0; i < l; ++i)
        {
        	if (i&1)
        	{
        		if (a[i]=='+')
        		{
        			a1++;
        		}else{
        			a2++;
        		}
        	}else{
        		if (a[i]=='-')
        		{
        			a1++;
        		}else{
        			a2++;
        		}
        	}
        }
        cout << min(a1,a2) << "\n";
        
    }
    return 0;
}