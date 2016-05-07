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
typedef double d;
int n,k,m;;

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

char a[20000];

int main(){
	int t,i,j,l;bool di=1,fi=1;
	scanf("%d\n",&n);
	scanf("%s",&a);l=strlen(a);
	int ans=0;
	for(i=0,j=0;i<l;i+=n){
		if(i>=3 and a[i-1]==a[i-2] and a[i-2]==a[i-3]){
			ans++;
			a[i]=a[i-1];
		}
	}
	cout<<ans;
	return 0;
}