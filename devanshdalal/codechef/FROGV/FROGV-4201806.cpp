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

struct node
{
	int ind,coor,range;	
};

bool comp1(node a , node b){
	return a.coor <= b.coor;
}

int main(){
    int t,i,j,k,l,n,m,p,q;
    node a[100010];
    int loc[100010];
    scanf("%d %d %d",&n,&k,&p);
    for (i = 1; i <= n; ++i)
    {
    	scanf("%d",&a[i].coor);
    	a[i].ind=i;
    }
    sort(a+1,a+n+1,comp1);
    
    for (i = 1; i <= n; ++i)
    {
    	loc[a[i].ind]=i;
    }

    a[n].range=n;
    for (i = n-1; i>=0 ; i--)
    {
    	if (a[i+1].coor-a[i].coor<=k)
    	{
    		a[i].range=a[i+1].range;
    	}else{
    		a[i].range=i;
    	}
    }

    // cout << "p "<< p << endl;
    for (i = 0; i < p; ++i)
    {
    	scanf("%d%d",&k,&l);
    	int l1=loc[k],l2=loc[l];
    	if (l1>l2)
    	{
    		q=l2;
    		l2=l1;
    		l1=q;
    	}
    	if (a[l1].range<l2)
    	{
    		printf("No\n");
    	}else{
    		printf("Yes\n");
    	}
    }
    return 0;
}