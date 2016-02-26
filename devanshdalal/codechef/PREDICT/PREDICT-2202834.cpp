#include <stdio.h>

int main(){
	int t;
	double pa,pb,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&pa);
		if(pa>0.5000) pb=1-pa;
		else {pb=pa; pa=1-pa;}
		ans=10000*((2*pa - 1)*pb) + 10000;
		printf("%lf\n",ans);
	}
	return 0;
}