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
int n,k;

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

char a[201];
int arr[10],b[10];

int main(){
	int t,i,j=0,te;// j(1),1(2),14(3),144(4)
	scanf("%d",&t);
	memset(arr,0,sizeof(arr));
	memset(b,0,sizeof(arr));
	scanf("%s",&a); n=strlen(a);
	for(i=0;i<n;i++){
		if(a[i]=='5')arr[2]++;
		else if(a[i]=='9')arr[6]++;
		else arr[a[i]-'0']++;
	}
	for(;t!=0;t=t/10){
		j=t%10;
		if(j==5)b[2]++;
		else if(j==9)b[6]++;
		else b[j]++;
	}
	int ma= 200;
	for(i=0;i<10;i++){
		if(b[i]){
			ma=min(ma,arr[i]/b[i]);
		}
	}
	cout<<ma;
	return 0;
}