#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#define DD ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

int len[10000],n;

bool cmp(char *aa,char *bb){
	int al=strlen(aa);
	int bl=strlen(bb),i;
	for(i=0;i<min(al,bl) and aa[i]==bb[i];i++);
	return (i==min(al,bl) and al<bl) || aa[i]<bb[i];
}

int main(){
	DD;
	int t,i,j,k,l,x,y,z;
	cin>>t;
	char *arr[10000];
	for(i=0;i<10000;i++)arr[i]=new char[12];
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>> arr[i];
			len[i]=strlen(arr[i]);
		}
		sort(arr,arr+n,cmp);
		int al,bl;
		for(i=0;i<n-1;i++){
			al=strlen(arr[i]);
			bl=strlen(arr[i+1]);
			for(j=0;j<min(al,bl) and arr[i][j]==arr[i+1][j];j++);
			if(j==min(al,bl))break;
		}
		if(i<n-1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
