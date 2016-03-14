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
	int t,i,j,k,p,q,x1,x2,y1,y2,n;
	r(n);
	int arr[n+1][n+1];
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			scanf("%d",&arr[i][j]);
		}	
	}
	int mem[n+1][n+1][11];
	for(i=0;i<=n;i++){
		for(j=0;j<11;j++){
			mem[0][i][j]=0;
			mem[i][0][j]=0;
		}
	}
	for(i=1;i<=n;i++){
		int tem[11];
		for(j=0;j<11;j++){
			tem[j]=0;
		}
		for(j=1;j<=n;j++){
			tem[arr[i][j]]++;
			for(k=1;k<11;k++){
				mem[i][j][k]=mem[i-1][j][k]+tem[k];
			}
		}	
	}
	/*
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<11;k++){
				cout<<mem[i][j][k]<<"|";
			}
			cout<<" ";
		}	
		cout<<endl;
	}*/
	
	r(q);
	while(q--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int tem[11];
		int cou=0;
		for(i=1;i<11;i++){
			tem[i]=mem[x2][y2][i]+mem[x1-1][y1-1][i]-mem[x1-1][y2][i]-mem[x2][y1-1][i];
			//cout<<mem[x2][y2][i]<<"|"<<mem[x1-1][y1-1][i]<<"|"<<mem[x1-1][y2][i]<<"|"<<mem[x2][y1-1][i]<<"}";
			if(tem[i]>0)cou++;
		}
		//~ for(i=1;i<11;i++){
			//~ cout<<tem[i]<<"|";
		//~ }
		//~ cout<<endl;
		//~ 
		printf("%d\n",cou);
	}
	return 0;
}