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

int r,c;int g[101];


int main(){
	int t,i,j,x=0,y=0;bool di=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>g[i];
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		g[x-1]+=y-1;
		g[x+1]+=g[x]-y;
		g[x]=0;
	}
	for(i=1;i<=n;i++){
		cout<<g[i]<<endl;
	}
	return 0;
}