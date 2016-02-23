#include <stdio.h>

int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main(){
	int i,t,n;
	int arr[10];
	scanf("%d",&t);
	while(t--){
		int min=0;
		for(i=0;i<10;i++){ scanf("%d",&arr[i]);  min=arr[min]<=arr[i]?min:i; }
		if(min==0){
			//printf("%d\t",arr[4]);
			for(i=1;i<10;i++) {if(arr[i]==arr[0]) { min=i; break; } }
			if(min==0) {printf("1"); while(arr[min]-->=0) printf("0");}
			else { while(arr[min]-->=0) printf("%d",min); }
		}
		else { while(arr[min]-->=0) printf("%d",min); }
		printf("\n");
	}
	return 0;
}