#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define DD ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;
#define mod 10000

int main(){
	DD;
	int t,i,j,k,l,x,y,z,n,u,q;
	cin>>x>>u>>q;
	int al[u],ar[u];
	for(i=0;i<u;i++){
		cin>> al[i]>>ar[i];
	}
	for(;q--;){
		cin>>x>>y;
		ll ans=0;
		for(i=0;i<u;i++){
			if(x>ar[i] or y<al[i])continue;
			else if(al[i]<=x and ar[i]<=y and ar[i]>=x){
				ll len=ar[i]-x+1;
				ans+=len*ll(x-al[i])+len*(len+1)/2;
			}else if(al[i]>=x and ar[i]<=y){
				ll len=ar[i]-al[i]+1;
				ans+=len*(len+1)/2;
			}else if(al[i]>=x and ar[i]>=y and al[i]<=y){
				ll len=y-al[i]+1;
				ans+=len*(len+1)/2;
			}else if(x>=al[i] and y<=ar[i]){
				ll len=y-x+1;
				ans+=ll(x-al[i])*len + len*(len+1)/2;
			}
			ans%=mod;
			//~ cout<<"ans:"<<ans<<endl;
		}
		//~ cout<< ans<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
