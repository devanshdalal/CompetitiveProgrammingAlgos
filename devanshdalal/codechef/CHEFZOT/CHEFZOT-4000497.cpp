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

int main(){
	register int t,l,i,j,n,m,ptr;
	
	scanf("%d",&t);
	j=0;
	n=0;
	while(t--){
		scanf("%d",&i);
		if(i==0){
			n=max(j,n);
			j=0;
		}else j++;

	}
	printf("%d\n",max(n,j));
	return 0;
}