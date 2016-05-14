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
const ll mod = 1000000007;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char ch) { return putchar(ch);  }
#endif
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
}

char buf[11];int ix; 
inline void writeInt(int x) {
     ix = 10;
     buf[10] = '\n';
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
    int t,i,j,k,l,n,m,p,q,r,g,b;
    scanf("%d",&t);
    while(t--){
        int rmax=0,gmax=0,bmax=0;
        scanf("%d %d %d %d",&r,&g,&b,&m);
        for ( i = 0; i < r; ++i)
        {
            scanf("%d",&p);
            rmax=max(rmax,p);
        }

        for ( i = 0; i < g; ++i)
        {
            scanf("%d",&p);
            gmax=max(gmax,p);
        }

        for ( i = 0; i < b; ++i)
        {
            scanf("%d",&p);
            bmax=max(bmax,p);
        }

        q=max(max(rmax,gmax),bmax);
        for (i = 0; i < m; ++i)
        {
            if (rmax>=gmax and rmax>=bmax)
            {
                rmax/=2;
                // gmax++;
                // bmax++;
            }else if(gmax>=bmax){
                gmax/=2;
                // rmax++;
                // bmax++;
            }else{
                bmax/=2;
                // rmax++;
                // gmax++;
            }
            if (q>max(max(rmax,gmax),bmax))
            {
                q=max(max(rmax,gmax),bmax);
            }

        }

        

        printf("%d\n",q );
    }
    return 0;
}