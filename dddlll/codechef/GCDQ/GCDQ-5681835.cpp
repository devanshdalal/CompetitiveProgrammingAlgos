#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define io ios_base::sync_with_stdio(0)
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

inline int gcd(int a,int b){
	while(b){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

char buf[21];int ix;
//int putchar_unlocked(char ch) { return putchar(ch);  }
inline void writeL(int x) {
     ix = 20;
     buf[20] = '\n';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[ix++] != '\n');
}

//int getchar_unlocked()  {return getchar();}
inline void Read(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int a[101010],b[101010],c[101010];

int main(){
    int t,k,l,r,n;

    // scanf("%d",&t);
    Read(t);
    while(t--){
    	// scanf("%d %d",&n,&k);
    	Read(n); Read(k);
        for (int i = 1; i <=n; ++i)
        {
    		// scanf("%d",&a[i]);
    		Read(a[i]);
        }
        b[1]=a[1];
        c[n]=a[n];
        for (int i = 2; i <=n; ++i)
        {
        	if (b[i-1]==1)
        	{
        		b[i]=1;
        	}else{
        		b[i]=gcd(a[i],b[i-1]);
        	}
        }
        for (int i = n-1; i>0; --i)
        {
        	if (c[i+1]==1)
        	{
        		c[i]=1;
        	}else{
        		c[i]=gcd(a[i],c[i+1]);
        	}
        }
        for (; k-- > 0 ; )
        {
        	// scanf("%d %d\n", &l,&r );
        	Read(l); Read(r);
        	// assert(l>1 or r<n);
        	if (l>1 and r<n)
        	{
        		// printf("%d\n", gcd(b[l-1],c[r+1]) );
        		writeL(gcd(b[l-1],c[r+1]));
        	}else if (l>1)
        	{
        		// printf("%d\n", b[l-1] );
        		writeL( b[l-1] );
        	}else
        	{
        		// printf("%d\n", c[r+1] );
        		writeL( c[r+1] );
        	}
        }
    }
    return 0;
}