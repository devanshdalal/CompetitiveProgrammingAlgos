#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
int n,k,m;char a[2000009],b[2000009];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int r,c;char g[100][100];


int main(){
	int t,i,j,x=0,y=0;bool di=0;
	scanf("%d%d\n",&r,&c);
	for(i=0;i<r;i++){
		scanf("%s",g[i]);
	}
	for(i=0;i<r;i++){
		di=1;
		for(j=0;j<c;j++){
			di=di && (g[i][j]=='.'?1:0);
		}
		x+=di;
	}
	for(j=0;j<c;j++){
		di=1;
		for(i=0;i<r;i++){
			di=di && (g[i][j]=='.'?1:0);
		}
		y+=di;
	}
	cout<<x*c + y*(r-x);
	return 0;
}