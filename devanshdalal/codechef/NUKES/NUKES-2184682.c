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
int p[100];

int main(){
	int i, A,N,K;
	scanf("%d",&A); scanf("%d",&N); scanf("%d",&K);
	for(i=0;i<K;i++){
		p[i]=A%(N+1);
		A=A/(N+1);
	}
	for(i=0;i<K;i++) printf("%d ",p[i]);
	return 0;
}