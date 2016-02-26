#include <stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1010];

int main(){
	int t,i,j,l,n;
	int arr[26];
	for(i=0;i<26;i++) arr[i]=0;
	scanf("%d",&t);
	while(t--){
		scanf("%s",&a);
		l=strlen(a);
		n=l/2;
		for(i=0;i<n;i++){
			arr[a[i]-'a']++;
			arr[a[l-i-1]-'a']--;
		}
		for(i=0;i<26;i++){
			if(arr[i]!=0) break;
		}
		if(i==26) printf("YES\n");
		else printf("NO\n");
		for(;i<26;i++) arr[i]=0;
	}
}