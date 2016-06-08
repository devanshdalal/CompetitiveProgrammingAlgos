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

struct point
{	
	int x,y,z;
};

point a[100000];

int p4[100];

int main(){
    int t,j,A,B,C,D;
    std::ios_base::sync_with_stdio(0);

    for (int i = 0; i < 100; ++i)
    {
    	p4[i]=i*i*i*i;
    	// p4[i]*=p4[i];
    }

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i].x >> a[i].y >> a[i].z ;
	}

	while(m--){
		std::cin >> A >> B >> C >> D;
		double ans=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				ans += double( std::max(abs(A*(a[i].x-a[j].x)+B*(a[i].y-a[j].y) + C*(a[i].z-a[j].z)),abs(D)) )/sqrt(p4[abs(a[i].x-a[j].x)]+p4[abs(a[i].y-a[j].y)]+p4[abs(a[i].z-a[j].z)]);
			}
		}
		std::cout << std::fixed <<  std::setprecision(10)  << (2.0*ans/n)/(n-1) << "\n";

	}

    return 0;
}