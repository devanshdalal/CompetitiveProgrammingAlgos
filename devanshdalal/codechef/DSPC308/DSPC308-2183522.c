#include<stdio.h>
//int a,b,j,max,maxi,te;
//int main(){
//	scanf("%d",&a);/
//	while(a--){
//		scanf("%d",&b);
//		scanf("%d",&max);maxi=1;
//		for(j=2;j<(b+1);j++){
//			scanf("%d",&te);
//			if(max<=te){max=te; maxi=j;  }
//		}
//		printf("%d\n",maxi);
//	}
//	return 0;
//}
typedef long long ll;
int p[40];

int main(){
	register int i,j,k; ll t;
	scanf("%lld",&t);
	while(t){
		for(i=0;t;i++){
			p[i]=t%2;
			t=t/2;
		}
		j=1;k=1;
		for(i=i-2;i>=0;i--){
			if(p[i])  j=j+k;
			else k=k+j;
		}
		printf("%d/%d\n",j,k);
		scanf("%lld",&t);
	}
	return 0;
}