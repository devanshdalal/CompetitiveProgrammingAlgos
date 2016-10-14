#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cassert>

typedef long long ll;

bool ispow2(int a){
	while(a%2==0){
		a/=2;
	}
	return a==1;
}

int count2(int a){
	int ret=0;
	if(a==0)return 0;
	while(a%2==0){
		a/=2;
		ret++;
	}
	return ret;
}

int main(){
	
	std::ios_base::sync_with_stdio(0);
	int t,a,b,ans;

	std::cin >> t;
	while(t--){
		std::cin >> a>> b;
		assert( ispow2(b) );
		if( ispow2(a) ){
			ans=count2(std::max(b/a,a/b));
		}else{
			ans=0;
			while(a>1 and !ispow2(a)){
				a=a/2;
				ans++;
			}
			ans+=count2(std::max(b/a,a/b));
		}
		std::cout << ans << "\n" ;
	}
	
	return 0;

}