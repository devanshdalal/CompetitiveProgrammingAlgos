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

ll n;

double k,b;
double x1,x2;

int main() {
		
	std::ios_base::sync_with_stdio(0);

	cin >> n;
	cin >> x1 >> x2;
	x1+=0.00000000001;
	x2-=0.00000000001;
	std::vector<pair<double,int> > a1(n);
	std::vector<pair<double,int> > a2(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> k  >> b;
		double y1 = k*x1+b,y2=k*x2+b;
		a1[i]=make_pair(y1,i);
		a2[i]=make_pair(y2,i);
	}

	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());

	bool done=1;
	for (int i = 0; i < n; ++i)
	{
		if (a1[i].second!=a2[i].second){
			done=0;
			break;
		}
	}

	cout << (!done?"YES\n":"NO\n") ;
	

	return 0;
}