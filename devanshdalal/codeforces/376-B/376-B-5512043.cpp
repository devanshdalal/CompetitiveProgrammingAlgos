#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	int t,i,j,k,l,x,y,z,n,m;
	cin>> n>>m;
	int ans=0;
	int bal[n];
	for(i=1;i<=n;i++)bal[i]=0;
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		bal[x]+=z;
		bal[y]-=z;
	}
	for(i=1;i<=n;i++)if(bal[i]>0)ans+=bal[i];
	cout<< ans<<endl;
	return 0;
}