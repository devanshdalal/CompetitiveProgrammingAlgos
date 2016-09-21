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

/////  This is completely written by me: devansh dalal .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

pair<int,int> a[101010];

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009};
int siz=sizeof(primes)/sizeof(int);
ll n,m;
vector< int > fa[1010];

void addf(int n){
	int m=n,ind=n;
	for (int i = 0; n>1 and i < siz; ++i)
	{
		while(m%primes[i]==0){
			m/=primes[i];
		}
		if (m<n)
		{
			fa[ind].pb(n/m);
			n=m;
		}
	}
}

ll mem[1001];

ll f(ll p,ll q,ll r,ll s){
	ll a = mem[m-m/p] + mem[m-m/q] + mem[m-m/r] + mem[m-m/s];
	ll b = mem[m-(m/p+m/q-m/(p*q))] + mem[m-(m/p+m/r-m/(p*r)) ] + mem[m-(m/p+m/s-m/(p*s))];
	b += mem[m-(m/q+m/r-m/(q*r))] + mem[m-(m/q+m/s-m/(q*s))] + mem[m-(m/r+m/s-m/(r*s)) ];
	ll c = mem[ m - (m/p+m/q+m/r-m/(p*q)-m/(q*r)-m/(p*r)+m/(p*q*r)) ];
	c+= mem[ m - (m/p+m/q+m/s-m/(p*q)-m/(q*s)-m/(p*s)+m/(p*q*s)) ];
	c+= mem[ m - (m/p+m/s+m/r-m/(p*s)-m/(s*r)-m/(p*r)+m/(p*s*r)) ];
	c+= mem[ m - (m/s+m/q+m/r-m/(s*q)-m/(q*r)-m/(s*r)+m/(s*q*r)) ];
	ll d = mem[ m - (m/p+m/q+m/r+m/s-m/(p*q)-m/(q*r)-m/(r*s)-m/(p*r)-m/(p*s)-m/(q*s)  +m/(p*q*r)+m/(p*q*s)+m/(q*r*s)+m/(p*r*s) - m/(p*q*r*s) ) ];
	return (a-b+c-d)%mod;
}

int main(){
    ll t,L,R;
    ios_base::sync_with_stdio(0);
    mem[0]=0;
    mem[1]=1;
    for (int i = 1; i < 1001; ++i)
    {
    	addf(i);
    	while (fa[i].size()<4)
    	{
    		fa[i].pb(1);
    	}
    }
    // cout << "jfdsh" << fa[1][1]  << endl;

    cin >> t ;
 
    while(t--){
    	cin >> n >> m >> L >> R ;
    	for (int i =2; i <=m; ++i)
    	{
    		mem[i]=mpow(i,n);
    	}
    	// cerr << f(1,1,1,1) << endl;
    	ll mpn = mem[m],ans=0;
    	for (int i = L; i <=R; ++i)
    	{
    		ans+=mpn-f(fa[i][0],fa[i][1],fa[i][2],fa[i][3]);
    	}
    	cout << (mod+(ans%mod))%mod << "\n";

    	


    }
    

    return 0;
}