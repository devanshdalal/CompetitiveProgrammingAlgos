#include<iostream>
#include<stdio.h>
typedef long long ll;
using namespace std;
 
int main(){
	int t,i,j;
	cin>>t;
	while(t--){
		cin>>i>>j;
		printf("%lld\n",ll(i)*ll(j)-ll(i)-ll(j));
	}
	
}