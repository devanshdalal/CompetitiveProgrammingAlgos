#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include <climits>
#include<map>
#include<cmath>
#define DD ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

inline int gcd(int a,int b){
	while(b>0){
		int re=a;
		a=b;
		b=re%b;
	}
	return a;
}

int main(){
	DD;
	int t,i,j,k,l,x,y,z,n,m,u,q;
	char ar[100100];
	while(true){
		cin>>ar;
		//~ cout<<"fjskldfsd "<<(x=7)<<endl;
		if(ar[0]=='*')break;
		n=l=strlen(ar);
		int per[130];
		fill(per,per+130,0);
		for(i=0;i<l;i++){
			per[ar[i]]++;
		}
		sort(per,per+130);
		int hcf=per[129];
		for(i=0;i<129;i++){
			//~ cout<<" "<<per[]
			hcf=gcd(hcf,per[i]);
		}
		//~ cout<<"hcf"<<hcf<<endl;
		int ans=1;
		for(k=hcf;k>0;k--){
			if(n%k==0){
				bool f=true;
				for(i=0;i<n/k and f;i++){
					char ch=ar[i];
					for(j=1;j<k;j++){
						if(ar[i+j*n/k]!=ch){f=0;break;}
					}
				}
				if(f){
					ans=k;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
