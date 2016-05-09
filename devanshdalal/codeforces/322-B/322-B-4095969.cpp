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
int n,k,m,rgb[3];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

bool comp(int a,int b){
	return (a%3)<(b%3);
}

int main(){
	int t,i,j=0,te;
	scanf("%d%d%d",&rgb[0],&rgb[1],&rgb[2]);
	sort(rgb,rgb+3,comp);
	te=rgb[0]%3 + rgb[1]%3 +rgb[2]%3;
	int res=(rgb[0]/3 + rgb[1]/3 + rgb[2]/3 );  j=(te==4 and rgb[0]%3==0 and rgb[0]!=0) ? 1 : rgb[0]%3;
	//cout<< j <<endl;
	cout<<res + j;
	return 0;
}