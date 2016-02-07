#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

//inline int getchar_unlocked(){return getchar();       }
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main(){
	int t,i,j,m,s;
	scanf("%d",&t);
	while(t--){
		fastRead_int(m);
		m>>=1;
		i=m>>1;
		printf("%d\n",i*(m-i));
	}
	return 0;
}