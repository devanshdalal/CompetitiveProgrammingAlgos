#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
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
	while(N--){
		scanf("%d",&M);
		queue<int> Q;
		Q.push(1);
		int ans;
		for(i=0;true;){
			k=Q.front();
			Q.pop();
			i++;
			if(k!=0){
				Q.push((10*k)%M);
				Q.push((10*k+1)%M);
			}else{
				ans=i;
				break;
			}
		}
		//~ printf("ans %d\n",ans);
		bool arr[100];
		for(i=99;ans!=0 && i>=0;i--){
			if(ans&1)arr[i]=1;
			else arr[i]=0;
			ans=ans/2;
		}
		
		for(i++;i<100;i++){
			if(arr[i])putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
	return 0;
}
