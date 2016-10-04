#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000003;

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

std::vector<int> g[1000000];

struct node
{
	int id,cost,deg;
};

node data[1000000];

bool cmp(node a , node b){
	return a.deg<b.deg;
}

int main(){
    ll t,n,m,a,b,c;
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
    	data[i].id=i;
    	data[i].cost=0;
    	data[i].deg=0;
    }
    for (int i = 0; i < m; ++i)
    {
    	cin >> a >> b >> c;
    	g[a].pb(b);
    	g[b].pb(a);
    	data[a].cost+=c;
    	data[a].deg++;
    	data[b].cost+=c;
    	data[b].deg++;
    }
    sort(data,data+n,cmp);
    for (int i = 0; i < n; i+=2)
    {
    	cout << data[i].id << " ";
    }


    return 0;
}