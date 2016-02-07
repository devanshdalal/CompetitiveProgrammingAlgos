#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int getchar_unlocked(){ return getchar();}

inline void fastRead_int(int &x) {
   register int c = getchar_unlocked();
   x = 0;
   for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
   for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
   }
}


int main(){
	register int t,k,i,c=0;
	fastRead_int(t);  fastRead_int(k);
	while(t--){
		fastRead_int(i);
		c+=i%k?0:1;
	}
	printf("%d",c);
return 0;
}