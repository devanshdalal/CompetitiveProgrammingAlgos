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
	int t,n;//,i,j,k,min;
	scanf("%d",&t);
	while(t--){
		fastRead_int(n);
		n--;
		printf("%d\n",4*n*n+5*n+1);
	}
	return 0;
}