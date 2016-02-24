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
#include<stdio.h>
int t,num,m=-210000000,n=-210000000,c=-210000000;
 
int main(){
while (scanf("%d", &num) != EOF){
	if(num>=m){c=n;n=m;m=num;     }
	else if(num>=n){c=n;n=num;   }
	else if(num>c){c=num;    }
  
}
if(c!=-210000000)printf("%d\n",c);
return 0;
}