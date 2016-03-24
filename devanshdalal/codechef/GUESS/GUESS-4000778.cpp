#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#include<stack>
// #define DD ios_base::sync_with_stdio(false)
#define maxx 10001
using namespace std;
typedef long long ll;

// #ifdef _WIN32
// inline int getchar_unlocked() { return getchar(); }
// inline putchar_unlocked(char ch) { return putchar(ch);  }
// #endif
// void r(int &x){
//     register unsigned int c = getchar_unlocked();
//     x = 0;int neg=0;
//     for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
//     if(c=='-'){neg=1; c=getchar_unlocked(); }
//     for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
//     if(neg)x=-x;
// }

// char buf[11];int ix; 
// inline void writeInt(int x) {
//      ix = 10;
//      buf[10] = '\0';
//      do 
//      {
//         buf[--ix] = (x % 10) + '0';
//         x/= 10;
//      }while(x);
//      do
//      {
//         putchar_unlocked(buf[ix]);
//      } while (buf[++ix] != '\0');
// }

inline ll gcd(ll x,ll y){
	if(y==0)return x;
	else return gcd(y,x%y);
}

int main(){
	register int t,l,i,j,n,m,ptr;
	
	scanf("%d",&t);
	j=0;
	n=0;
	while(t--){
		scanf("%d%d",&n,&m);
		int o1=(n+1)>>1,e1=n>>1;
		int o2=(m+1)>>1,e2=m>>1;
		ll num=ll(o1)*ll(e2)+ll(o2)*ll(e1);
		ll den=ll(n)*ll(m);
		ll gcd1=gcd(den,num);
		printf("%lld/%lld\n", ll(num/gcd1) , ll(den/gcd1) );

	}
	return 0;
}