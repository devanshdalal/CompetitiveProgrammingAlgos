#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cassert>

int mod=1000000009;

int main(){
	int t,l,m,i;
	std::ios_base::sync_with_stdio(0);
	char a[200000],b[200000];
	int d1[200000],d2[200000];
	
	std::cin >> t;

	while(t--){
		std::cin >> a ;
		std::cin >> b ;
		//std::cout << a << "\n" << b  << "\n";
		l=strlen(a);
		m=strlen(b);
		if(m<l){ std::swap(a,b); std::swap(l,m); }
		//assert(strlen(b)==l);
		assert(m<=200000);	
		
		d1[0]= a[0]=='#'?mod:0;
		d2[0]= b[0]=='#'?mod:0;

		for(i=1;i<l;i++){
			if(a[i]=='#'){
				d1[i]=mod;
			}else{
				d1[i]=std::min(d1[i-1],d2[i-1]+1);
			}

			if(b[i]=='#'){
				d2[i]=mod;
			}else{
				d2[i]=std::min(d2[i-1],d1[i-1]+1);
			}
			
			d1[i]=std::min(d1[i],d2[i]+1);
			d2[i]=std::min(d2[i],d1[i]+1);
			
			if(std::min(d1[i],d2[i])>=mod)break;
		}
		for(int j=l;j<m;j++){ 
			d2[j]=b[j]=='#'?mod:d2[j-1]; 
		}
		if( i<l or std::min(d1[0],d2[0])>=mod ){
			std::cout << "No\n" ;
		}else{
			std::cout << "Yes\n" << std::min(d1[l-1],d2[m-1]) << "\n" ;	
		}
	}


}