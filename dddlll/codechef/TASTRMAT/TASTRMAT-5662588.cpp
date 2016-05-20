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
ll p = 100001 ;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

char a[100010],b[100010];
ll l,m,pr[100010],qr[100010];

ll calc(){
	ll ans1=0,ans2=0;
	for (int i = 0; i < m; ++i)
	{
		if (b[i]=='0')
		{
			ans1+=mpow(p,l-m+i);
		}
		pr[i]=ans1;
		if (b[i]=='1')
		{
			ans2+=mpow(p,l-m+i);
		}
		qr[i]=ans2;
	}
}

ll f(int s,int e){
	if(e<s)return 0;
	return (pr[e]-(s==0?0:pr[s-1]))%mod;
}

ll g(int s,int e){
	if(e<s)return 0;
	return (qr[e]-(s==0?0:qr[s-1]))%mod;
}

int main(){
    int t,j,k;
    io;

    cin >> a;
    l=strlen(a);
	cin >> t;
	ll pinv=mpow(p,mod-2);
	ll ppow[l+1];
	for (int i =ppow[0]=1; i <l ; ++i)
	{
		ppow[i]=ppow[i-1]*pinv%mod;
	}
	while(t--){
		cin >> b ;
		m=strlen(b);
		calc();
		// ll z0=calc('0');
		// ll z1=calc('1');
		ll ans=0;
		for (int i = 0; i < l; ++i)
		{
			int s,e;
			e=m-1-(m-i-1);
			if(e>=m)e=m-1;
			s=m-(l-i);
			if(s<0)s=0;
			// cerr << s << " " << e << endl ;
			if (a[i]=='0')
			{
				ans+=g(s,e)*ppow[i]%mod;
				// ans+=g(0,m-1)*mpow(pinv,i);
			}else{
				ans+=f(s,e)*ppow[i]%mod;
				// ans+=f(0,m-1)*mpow(pinv,i);
			}
		}
		cout << (mod+ans%mod)%mod << "\n";
	}
	


    return 0;
}