#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 10000001
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

char a[100000];
int k,n;

int fill(int i,int j){
	if (j-i+1>k)
	{
		int mid = (i+j+1)/2;
		a[mid]=1-a[j];
		return 1+fill(i,mid-1)+fill(mid+1,j);
	}else{
		return 0;
	}
}

int main(){
    ll t,i,j,s;
    ios_base::sync_with_stdio(0);

    cin >> t ;
    while(t--){
    	cin >> n >> k ;
        cin >> a;
        ll ans =0;
        if (k==1)
        {
        	ll ans1=0,ans2=0;
        	for (int i = 0; i < n; ++i)
        	{
        		if (i%2==0)
        		{
        			ans1+=a[i]=='0';
        		}
        		else{
        			ans1+=a[i]=='1';
        		}
        	}
        	for (int i = 0; i < n; ++i)
        	{
        		if (i%2==1)
        		{
        			ans2+=a[i]=='0';
        		}
        		else{
        			ans2+=a[i]=='1';
        		}
        	}
        	if (ans1<ans2)
        	{
        		ans = ans1;
        		for (int i = 0; i < n; ++i)
        		{
                    a[i]=(i&1)?'0':'1';
                }
            }else{
                ans = ans2;
                for (int i = 0; i < n; ++i)
                {
        			a[i]=(i&1)+'0';
        		}
        	}
        }else{
	        for (i = 0; i < n; )
	        {
    	        for (j=i; j<n and a[j]==a[i] ; ++j);
    	        j--;
                if(j-i+1>k){    
    	        	for (int ii = i+k; ii <=j ; ii+=k+1){
    	        		if(ii==j){
    	        			cerr << "ii1 " << j-1 << endl; 
    	        			a[j-1]=(a[i]=='0'?'1':'0');
    	        		}else{
    	        			cerr << "ii " << ii << endl; 
    	        			a[ii]=(a[i]=='0'?'1':'0');
    	        		}
    	        		ans++;
    	        	}
                    // cerr << "here " << endl;
                }
	        	i=j+1;
	        }
        }
        // cerr << a[2] << endl;
        cout << ans << "\n" << a << endl;
    }


	// cout << "here " << t << endl;


    return 0;
}