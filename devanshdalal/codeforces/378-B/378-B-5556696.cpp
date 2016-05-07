#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
using namespace std;
typedef long long ll;
using namespace std;

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

int main(){
	//DD;
	register int t,i,j,k,N,M;
	scanf("%d",&N);
	int a[N+1],b[N+1];
	for(i=1;i<=N;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	bool ar[N+1],br[N+1];
	memset(ar+1,1,sizeof(ar));
	memset(br+1,1,sizeof(ar));
	for(i=j=N,k=2*N;k>N;k--){
		if(a[i]<b[j]){
			br[j--]=0;
		}else{
			ar[i--]=0;
		}
	}
	for(i=1;i<=N;i++){
		if(i<=N/2 or ar[i])printf("1");
		else printf("0");
	}
	printf("\n");
	for(i=1;i<=N;i++){
		if(i<=N/2 or br[i])printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}