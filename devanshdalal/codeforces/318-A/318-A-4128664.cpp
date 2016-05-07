#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
ll n,k,m;char a[2000009],b[2000009];

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
	int t,i,j,x=0,y=0,tt=0,tw=0;bool di=0;
	cin>>n>>k;
	if(k<=(n+1)/2){
		cout<<2*k-1;
	}else cout<<2*(k-(n+1)/2);
	return 0;
}