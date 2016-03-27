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
typedef long long ll;
typedef unsigned long long ul;
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

int owner2[10010],s[10010];

int findp(int chef){
	if (owner2[chef]!=chef)
	{
		owner2[chef]=findp(owner2[chef]);
	}
	return owner2[chef];
}

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for (i = 1; i <= n; ++i)
        {
        	scanf("%d",&s[i]);
			owner2[i]=i;
        }
        scanf("%d",&q);
        while(q--){
        	scanf("%d",&k);
        	if (k)
        	{
        		scanf("%d",&k);
        		printf("%d\n", findp(k) );
        	}else{
        		scanf("%d %d",&k,&l);
                i=findp(k);
                j=findp(l);
        		if (i==j)
        		{
        			printf("Invalid query!\n");
        			continue;
        		}
        		if (s[i]>s[j])
        		{
        			owner2[j]=i;
        		}else if (s[i]<s[j])
        		{
        			owner2[i]=j;
        		}
        	}
        }
	}
    return 0;
}