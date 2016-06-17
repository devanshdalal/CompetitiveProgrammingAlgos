#include<stdio.h>

int main(){
	register int a,b,c,j,max,m1,m2,t,N,i;
	bool pr[N]; int primes[9592];
    	for(i=2;i<N;i++)  pr[i]=true;
    	for(i=2;i<N;i++){
        if(pr[i]){
            for(j=2*i;j<N;j=j+i){
                pr[j]=false;
            }
        }
    	}
	for(i=2,j=0;i<N;i++){
        	if(pr[i]){  primes[j++]=i;  }
    	}
	delete pr;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a); scanf("%d",&b);scanf("%d",&c);
		if(a>b) {max=b; b=a; a=max;    }
		int max=9*a/100;
		for(j=max;;j++){
			if(primes[j]>a){m1=j; break; }
		}
		for(j=m1;primes[j]<b;j++);
		m2=j-1;
		if(m2<m1){printf("-1\n");  }
		else{
		c=c%(m2-m1+1);
		if(c==0) printf("%d\n",primes[m2]);
		else printf("%d\n",primes[m1+c-1]);
		}
	}
	return 0;
}