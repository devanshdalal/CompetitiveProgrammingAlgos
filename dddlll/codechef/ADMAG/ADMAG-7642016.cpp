#include<stdio.h>
#include<iostream>

typedef long long ll;

ll fib[89];

int bsearch(ll n){
	int l=1,h=87,m;
	while(l<=h){
		m=(l+h)/2;
		if(n<fib[m]){
			h=m-1;
		}else if(n>fib[m]){
			l=m+1;
		}else{
			return m;
		}
	}
	return h;
}

int main(){
	std::ios_base::sync_with_stdio(0);
	ll n,t;
	
	fib[0]=fib[1]=1;
	fib[2]=2;
	for(int i=3;i<88;i++){
		fib[i]=fib[i-1]+fib[i-2];
		//std::cerr << fib[i] << "\n" ;
	}
	std::cin >> t;
	while(t--){
		std::cin >> n ;
		std::cout << bsearch(n) << "\n";
	}
	


	return 0;
}