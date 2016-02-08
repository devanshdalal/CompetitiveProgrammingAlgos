#include<cstdio>
#include<algorithm>
using namespace std;
int val[5000];
//int a[20]={0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,7,6};

//int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}





int main(){
	int t,n,i,j,k,min;
	scanf("%d",&t);
	while(t--){
		fastRead_int(n);
		for(i=0;i<n;i++){
			fastRead_int(val[i]);
		}
		sort(val,val+n);
		min=val[1]-val[0];
		for(i=2;i<n;i++){
			k=val[i];
			j=val[i-1];
			if(k-j<min) min=k-j;
		}
		printf("%d\n",min);
	}
	return 0;
}