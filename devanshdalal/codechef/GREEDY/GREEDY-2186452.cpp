#include<cstdio>
using namespace std;
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
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		fastRead_int(n);fastRead_int(m);
		if(m|n)
		      printf("%d\n",(n>>1)+(m>>1)+1);
		else  printf("0\n");
	}
	return 0;
}