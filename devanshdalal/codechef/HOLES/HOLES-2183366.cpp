#include<stdio.h>
#include<cstring>
int a[26];
char s[100];
int main(){
	register int i,t,l;
	scanf("%d",&t);
	while(t--){
	for(i=0;i<26;i++)  a[i]=0;
	scanf("%s",&s);l=strlen(s);
    	for(i=0;i<l;i++){
		a[s[i]-65]++;
	}
	printf("%d\n",a[0]+a[1]*2+a[3]+a[14]+a[15]+a[16]+a[17]);
	}
	return 0;
}