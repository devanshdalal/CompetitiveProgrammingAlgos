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
int n,k;char a[2000009];

const char he[]= {'h','e','a','v','y','\n'};

inline bool checkh(int x){
	int c;
	for(c=0;c+x<n && c<5;c++){
		if(a[x+c]!=he[c])return 0;
	}
	if(c==5)return 1;
	return 0;
}

const char met[]={'m','e','t','a','l','\n'};

inline bool checkm(int x){
	int c;
	for(c=0;c+x<n && c<5;c++){
		if(a[x+c]!=met[c])return 0;
	}
	if(c==5)return 1;
	return 0;
}

int main(){
	int t,i,j,l,x=0,y=0;bool di=0;ll count=0;
	scanf("%s",&a);n=strlen(a); //cout<<strlen(he)<<endl;
	for(i=0;i<n;){
		if(checkh(i)){x++;i+=5;}
		else if(checkm(i)){count+=(ll)x;i+=5;}
		else i++;
	}
	cout<<count;
	return 0;
}