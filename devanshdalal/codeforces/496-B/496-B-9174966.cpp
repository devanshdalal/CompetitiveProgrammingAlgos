#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define VI vector <int>
#define VVI vector < 	vi >
#define PII pair <int,int>
#define VPII vector < pii >
#define MI map < int, int >
#define SI set< int >
#define clr(x) x.clear()
#define sz(x) ((int) x.size())
#define F first
#define S second
#define abs(a) ((a<0)?(-a):a)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define mem1(a,c,b) (memset(a, c, sizeof(a[0]) * b))
#define mem2(a,d,b,c) (memset(a, d, sizeof(a[0][0])*b*c))
#define fastio ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int findm(vector<int> v){
	int p=0;
	for (int i = 1; i < v.size(); ++i)
	{
		// cerr << v[i] << " ";
		p=max(p,v[i]-v[i-1]);
	}
	// cerr << endl;
	return p;
}

bool comp(std::vector<int> v1,std::vector<int> v2){
    for (int i = 0; i < v1.size(); ++i)
    {
        if(v1[i]<v2[i])return 1;
        else if(v1[i]>v2[i])return 0;
    }
    return 0;
}


int main(){
    int t,i,j,k,l,n,m,p,q;
    cin >> n;
    // cerr << n << endl;
    char a[10001];
    cin >> a ;
    int b[10001];

    std::vector<int> mini;
    for (i = 0; i < n; ++i)
    {
        b[i]=a[i]-'0';
        mini.push_back(9);
    }

    for (i = 0; i < n; ++i)
    {
        std::vector<int> v;
        for (j = 0,k=i; j<n; ++j)
        {
            v.push_back(b[k]-b[i]>=0?b[k]-b[i]:10+b[k]-b[i]);
            k++;
            if(k>=n)k-=n;
        }
        if(comp(v,mini)){
            for (j = 0; j < n; ++j)
            {
                mini[j]=v[j];
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        cout << mini[i] ;
    }
    cout<< endl;


    return 0;
}