#include<stdio.h>
#include<cstring>
char a[100],b[100];

const char lis[]={'0','1','A','A','A','A','9','A','8','6'};

int main(){
	int t,l,i;
	scanf("%d",&t);
	while(t--){
		scanf("%s",&a);l=strlen(a);
		for(i=0;i<l;i++){
			if(lis[a[i]-'0']!='A'){ b[l-1-i]=lis[a[i]-'0'];       }
			else break;
		}
		b[l]='\0';
		if(i==l) printf("YES\n%s\n",b);
		else printf("NO\n");
	}
}