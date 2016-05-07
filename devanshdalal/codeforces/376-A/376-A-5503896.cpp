#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(false);
	int t,i,j,k,l,x,y,z;
	char arr[1000100];
	cin>> arr;
	l=strlen(arr);
	int pivot=0;
	ll tor=0;
	for(i=0;i<l;i++)if(arr[i]=='^'){pivot=i;break;}
	for(i=0;i<pivot;i++){
		if(arr[i]!='=')tor+=(ll)abs(i-pivot)*(ll)(arr[i]-48);
	}
	for(i=pivot+1;i<l;i++){
		if(arr[i]!='=')tor-=(ll)abs(i-pivot)*(ll)(arr[i]-48);
	}
	if(tor>0)cout<<"left"<<endl;
	else if(tor==0)cout<<"balance"<<endl;
	else cout<<"right"<<endl;
	return 0;
}