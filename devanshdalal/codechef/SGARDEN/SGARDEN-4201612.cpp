#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 100100
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod= 1000000007;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char ch) { return putchar(ch);  }
#endif
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

char buf[11];int ix; 
inline void writeInt(int x) {
     ix = 10;
     buf[10] = '\0';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[++ix] != '\0');
}

ll gcd(ll x,ll y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

inline ll lcm(ll x,ll y){
    return x*(y/gcd(x,y));
}

const int U=500;
int primes[U],parr[maxx];

inline ll mpow(ll base, int exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base)%mod;
        exponent = exponent >> 1;
        base = (base * base)%mod;
    }
    return result;
}


int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int a[maxx];
    primes[0]=primes[1]=1;
    for (i = 2; i < U; ++i)
    {
    	if (primes[i]==0)
    		for (j = i*i; j < U; j+=i)primes[j]=1;
    }
	for (i=2, j= 0; i < U; ++i)
	{
		if (primes[i]==0)
		{
			primes[j++]=i;
			// cout << primes[j] << endl;
		}
	}
	// for (i = 0; i < 10; ++i)
	// {
	// 	cout << primes[i] << " " ;
	// }cout<< endl;
    bool vis[maxx];

    while(t--){
        memset(vis,0,sizeof(vis));
        memset(parr,0,sizeof(parr));
        scanf("%d",&n);
        for (i = 1; i <= n; ++i)scanf("%d",&a[i]);
        for ( i = 1; i <= n; ++i)
        {
            if(!vis[i]){
                for(j=i,k=0;!vis[j];k++){
                    vis[j]=true;
                    j=a[j];
                }
                for (j = 0; primes[j]*primes[j] <= k; ++j)
                {
                	for (l=0 ;k!=1 and k%primes[j]==0 ; l++)
                	{
                		k/=primes[j];
                	}if (l)
                	{
                		parr[primes[j]]=max(parr[primes[j]],l);
                	}
                }
                if (k!=1)
                {
                	parr[k]=max(1,parr[k]);
                }
            }
        }
        ll ans=1;
        for (i = 0; i < n; ++i)
        {
        	if (parr[i])
        	{
        		// cout << "ff" << ans << " "<<  mpow(i,parr[i]) << endl;
        		ans= (ans*mpow(i,parr[i]))%mod;
        		// cout << "hhhh "<< mpow(i,parr[i]) <<" " << ans << endl;
        	}
        }

        printf("%lld\n", ans);
    }
    return 0;
}