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

char a[200];

int main(){
	int t,i,j=0,te;// j(1),1(2),14(3),144(4)
	scanf("%s",&a); n=strlen(a);
	for(i=0;i<n;){
		if(a[i]!='1'){ goto label;}
		else if(i<n-1 and a[i+1]=='1'){ i++; continue;}
		if(i==n-1)break;
		if(i<n-2 and a[i+1]=='4' and a[i+2]=='4'){
			i=i+3;
		}else if(i<n-1 and a[i+1]=='4'){
			i=i+2;//cout<<"ggg\n";
		}else{ goto label;}
	}
	cout<<"YES\n";j=1;
	label:if(j==0)cout<<"NO\n";
	return 0;
}