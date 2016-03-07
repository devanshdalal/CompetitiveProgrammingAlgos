#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
#define M 1000000007
using namespace std;

int a[100000],n,m,k;
 

int main(){
int t,i, x,y;
scanf("%d",&t);
while(t--){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	k=a[k-1];
	x=0;
	for(i=0;i<n;i++){
		if(a[i]<k)x++;
	}
	cout<<x+1<<endl;
}
return 0;
}