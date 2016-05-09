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
int n,k,m,a[100000];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	int t,i,j=0,te;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1)printf("%d",a[0]);
	else{
		int gc=gcd(a[0],a[1]);
		for(i=2;i<n;i++){
			gc=gcd(a[i],gc);
			if(gc==1)break;
		}
		for(i=0;i<n;i++){
			if(a[i]==gc)break;
		}
		if(i==n)printf("-1");
		else printf("%d",gc);
	}
	return 0;
}