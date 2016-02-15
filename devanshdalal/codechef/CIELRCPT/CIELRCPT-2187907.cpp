#include<stdio.h>
int i,j,T,n,k;
int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main() 
{
    scanf("%d",&T);
    while(T--)
    {
		k=0;
        fastRead_int(n);
        if(n>2048) {k=(n>>11); n=(n&2047); }
        for(i=0; n ; i++) {k+=(n&1); n=n>>1;   }
        printf("%d\n",k);
    }
  return 0;
}