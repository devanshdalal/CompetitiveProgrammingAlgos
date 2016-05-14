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
const ll mod = 1000000009;

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
    int t,i,j,k,l,n,m,p,q;
    DD;
    cin>>t;
    int a[100001];
    while(t--){
        cin >> n>> m;
        char s;
        for (i = 0; i < n; ++i)
        {
            a[i]=0;
        }
        for ( i = 0; i < m; ++i)
        {
            cin >> s >> p;
            a[p-1]=s;
        }
        ll lastp=-1,prod=1;

        for (i = 0; i < n; ++i)
        {
            // cerr << a[i] << ' ';
            if (a[i]!=0)
            {
                if (lastp!=-1 and a[lastp]!=a[i])
                {
                    prod=prod*(i-lastp)%mod;
                }
                lastp=i;
            }
        }
        // cerr << endl ;
        cout << prod << endl;

    }
    return 0;
}