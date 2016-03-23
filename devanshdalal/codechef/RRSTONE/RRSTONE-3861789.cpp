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

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline putchar_unlocked(char ch) { return putchar(ch);  }
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

int main(){
	register ll t,i,j,n,m;
	scanf("%lld%lld",&n,&m);
	ll a[n];
	for (i = 0; i < n; ++i){
		scanf("%lld",&a[i]);
	}
	if(m==0){
		for(i=0;i<n;i++){
			printf("%lld ", a[i]);
		}
	}else{
		ll mac=a[0];
		for(i=0;i<n;i++){
			mac=(a[i]>mac?a[i]:mac);
		}
		for(i=0;i<n;i++){
			a[i]=mac-a[i];
		}
		if(m&1){




			for(i=0;i<n;i++){
				printf("%lld ", a[i]);
			}
		}else{

				mac=a[0];
				for(i=0;i<n;i++){
					mac=(a[i]>mac?a[i]:mac);
				}

			
			for(i=0;i<n;i++){
				a[i]=mac-a[i];
			}
			for(i=0;i<n;i++){
				printf("%lld ", a[i]);
			}
		}
	}

	printf("\n");

	
	return 0;
}