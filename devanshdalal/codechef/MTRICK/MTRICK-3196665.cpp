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

ll C;
inline ll mulmod(ll a,ll b){
    ll x = 0,y=a%C;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%C;
        }
        y = (y*2)%C;
        b /= 2;
    }
    return x%C;
}

int main(){
	//DD;
	register ll t,i,j,k,N,A,B;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&N);
		ll a[1003];
		for(i=1;i<=N;i++){
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&A);  scanf("%lld",&B); scanf("%lld",&C);
		char arr[N+90];
		scanf("%s",arr);
		bool done=false,mode=true;
		ll mainP=1,ext=0;
		for(k=0,i=1,j=N;k<N;k++){
			if(arr[k]=='R'){
				mode=!mode;
			}else if(arr[k]=='M'){
				ext=mulmod(ext,B);
				mainP=mulmod(mainP,B);
				done=true;
			}else if(arr[k]=='A'){
				ext=(ext+A)%C;
				done=true;
			}            //~ cout<<"exr "<<ext<<" "<<mainP<<endl;
			if(mode){
				//~ if(done)
					//~ cout<<"mul(a[i],mainP) "<<mul(a[i],mainP)<<endl;
					printf("%lld ",(mulmod(a[i],mainP)+ext)%C);
				//~ else{
					//~ printf("%lld ",a[i]);
				//~ }
				i++;
			}else{
				//~ if(done)
					printf("%lld ",(mulmod(a[j],mainP)+ext)%C);
				//~ else{
					//~ printf("%lld ",a[j]);
				//~ }
				j--;
			}
		}
		printf("\n");
	}
	return 0;
}