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

char g[101][101];
int x[101],y[100];

int main(){
	int t,i,j;bool di=1,fi=1;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%s",g[i]);
	}
	bool te=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(g[i][j]=='.'){break;}
		}
		if(j==n){break;}
	}
	if(i!=n)di=0;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(g[i][j]=='.'){break;}
		}
		if(i==n){break;}
	}
	if(j!=n)fi=0;
	if(fi || di){
		if(di){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(g[i][j]=='.'){x[i]=j; break;}
				}
			}
			for(i=0;i<n;i++){
				cout<<i+1<<" "<<x[i]+1<<endl;
			}
		}else{
			for(j=0;j<n;j++){
				for(i=0;i<n;i++){
					if(g[i][j]=='.'){y[j]=i; break;}
				}
			}
			for(i=0;i<n;i++){
				cout<<y[i]+1<<" "<<i+1<<endl;
			}
		}
	}else{
		cout<<-1<<endl;
	}
	return 0;
}