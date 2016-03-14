#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>
typedef long long ll;
using namespace std;
#define ma 100100
char a[ma];

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

char buf[21];int ix;
int putchar_unlocked(char ch) { return putchar(ch);  } 
inline void writeL(ll x) {
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
 
int main(){
	int t,i,p,q,X,n;
	r(t);
	while(t--){
		r(n);
		int arr[n];
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int ans[n];
		ans[0]=0;
		ll sum=0;
		for(i=1;i<n;i++){
			if(arr[i]==arr[i-1])ans[i]=ans[i-1];
			else ans[i]=i;
			sum=sum+ll(ans[i]);
		}
		printf("%lld\n",sum);
	}
	return 0;
}