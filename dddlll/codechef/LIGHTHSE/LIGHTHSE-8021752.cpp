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

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

std::pair<ll,ll> a[100001];

int main(){
    ll t,n,k,l,p,q;
    std::ios_base::sync_with_stdio(0);


    std::cin >> t ;
    while(t--){
	    std::cin >> n ;
	    ll minx=1000000001,miny=1000000001,maxx=-1000000001,maxy=-1000000001;int mini,maxi;
	    for (int i = 0; i <n; ++i)
	    {
	    	std::cin >> a[i].first >> a[i].second ;
	    	if (a[i].first<minx or (a[i].first==minx && a[i].second>a[mini].second) )
	    	{
	    		mini=i;
	    		minx=a[i].first;
	    	}
	    	if (a[i].first>=maxx or (a[i].first==maxx && a[i].second<a[maxi].second))
	    	{
	    		maxi=i;
	    		maxx=a[i].first;
	    	}
	    	miny=std::min(a[i].second,miny);
	    	maxy=std::max(a[i].second,maxy);
	    }
	    bool done=0;
	    std::vector<std::pair<int,int> > ans;
	    for (int i = 0; !done && i < n; ++i)
	    {
	    	if (a[i].first<=minx and a[i].second<=miny)
	    	{
	    		ans.push_back(std::make_pair(1,i));
	    		done=1;
	    	}
	    	else if (a[i].first>=maxx and a[i].second<=miny)
	    	{
	    		ans.push_back(std::make_pair(2,i));
	    		done=1;
	    	}
	    	else if (a[i].first>=maxx and a[i].second>=maxy)
	    	{
	    		ans.push_back(std::make_pair(3,i));
	    		done=1;
	    	}
	    	else if (a[i].first<=minx and a[i].second>=maxy)
	    	{
	    		ans.push_back(std::make_pair(4,i));
	    		done=1;
	    	}
	    }
	    if (!done)
	    {
	    	if (a[mini].second<=a[maxi].second)
	    	{
	    		ans.push_back(std::make_pair(1,mini));
	    		ans.push_back(std::make_pair(3,maxi));
	    	}else{
	    		ans.push_back(std::make_pair(4,mini));
	    		ans.push_back(std::make_pair(2,maxi));
	    	}
	    }

	    // std::cerr << " case " << t << " " << ans.size() << "\n";
	    
	    std::cout << ans.size() << "\n";
	    for (int i = 0; i < ans.size(); ++i)
	    {
    		std::cout << ans[i].second+1 <<  (ans[i].first==1?"NE":(ans[i].first==2?"NW":(ans[i].first==3?"SW":"SE" ) )) << "\n";
	    }
    }

    


    return 0;
}