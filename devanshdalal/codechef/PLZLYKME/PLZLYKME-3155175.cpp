#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
using namespace std;
typedef long long ll;
typedef double d;
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

struct node{
	int par;
	int left,right,mid; 
	int lh,mh,rh,h;
};

int main(){
	//DD;
	register int t,i,j,k,L,D,C,S;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&L,&D,&S,&C);
		bool done=0;
		d lhs=d(S);
		d rhs=d(L);
		D--;
		while(D--){
			if(lhs-rhs>=-eps){
				done=true;
				break;
			}
			rhs/=(1+C);
		}		
		if(lhs-rhs>=-eps){
			done=true;
		}
		printf(done?"ALIVE AND KICKING\n":"DEAD AND ROTTING\n");
	}
	return 0;
}