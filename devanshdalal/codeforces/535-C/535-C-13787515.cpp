#include <bits/stdc++.h>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
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

ll A,B,n,   l,t,m,   r;

ll bsearch(ll tar){
	ll left=l , right=r;
	while(left<=right){
		ll mid=(left+right)/2;
		ll sum=(2*A+(l+mid-2)*B)*(mid- l +1)/2;
		// dbg(sum);
		// dbg(tar);
		if (sum<tar)
		{
			left=mid+1;
		}else if(sum>tar){
			right=mid-1;
		}else{
			return mid;
		}
	}
	// dbg(right);
	return right;
}

int main(){
    std::ios_base::sync_with_stdio(0);

    cin >> A>> B >> n;

    while(n--){
    	cin >> l >> t >> m ;

    	ll tot=t*m;

    	ll al=A+(l-1)*B;

    	r = l  + (t-al)/B ;

    	// dbg(al);
    	// dbg(r);

    	if (r<l)
    	{
    		cout << "-1\n";
    	}else{
	    	ll ans = min(r,bsearch(tot) );
    		cout << ans <<"\n";

    	}
    }


    return 0;
}