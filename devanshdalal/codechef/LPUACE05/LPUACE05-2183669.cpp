#include<stdio.h>
typedef long long ll;
int p[40];

int main(){
	register int i,j,k,l,t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=n;
		for(i=0;n;i++){
			p[i]=n%2;
			n=n/2;
		}
		j=i/2;l=((1<<j)+1);
		if(i%2==0 && k%l==0) printf("%d\n",k/l);
		else printf("Not Lovely\n");
	}
	return 0;
}