#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#include<queue>
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

inline ll gcd(ll x,ll y){
	if(y==0)return x;
	else return gcd(y,x%y);
}


int main(){
	register int t,l,i,j,n,m,ptr;	
	char * a=new char[120000];
	scanf("%s",a);
	l=strlen(a);
	bool visit[120000];
	bool vi[10];
	int dist[120000];
	for (i = 0; i < l ; ++i)
	{
		visit[i]=false;
		dist[i]=0;
	}
	visit[0]=true;
	for (i = 0; i < 10 ; ++i)
	{
		vi[i]=false;
	}
	queue<int> q;
	q.push(0);  
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==l-1)break;
		if(top>0 and !visit[top-1]){
			dist[top-1]=dist[top]+1;
			visit[top-1]=true;
			q.push(top-1);
		}
		if(top<l-1 and !visit[top+1]){
			dist[top+1]=dist[top]+1;
			visit[top+1]=true;
			q.push(top+1);
		}
		if(!vi[a[top]-48]){
			for (i = 0; i < l; ++i)
			{
				if (a[i]==a[top] and !visit[i])
				{
					dist[i]=dist[top]+1;
					visit[i]=true;
					q.push(i);
				}
			}
			vi[a[top]-48]=true;
		}
	}
	printf("%d\n", dist[l-1]);
	return 0;
}