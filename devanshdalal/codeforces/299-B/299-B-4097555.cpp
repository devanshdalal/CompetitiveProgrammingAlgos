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
int n,k,m;char a[300009];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int main(){
	int t,i,j=0,te,pos=0;int done=1;
	scanf("%d%d",&n,&k);
	scanf("%s",&a);
	if(n==2 )printf("YES");
	else{
		for(i=0;i<n;){
			pos=i;
			for(j=i+k;j>i;j--){
				if(j>=n)continue;
				if(a[j]=='.'){i=j;break;}
			}
			if(pos==i){done=0;break;}
			if(i==n-1){break;}
		}
		if(done)printf("YES");
		else printf("NO");
	}
	return 0;
}