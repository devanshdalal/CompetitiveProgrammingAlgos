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
int tt[]={1,2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
//int getchar_unlocked()  {return getchar();}
inline int fastRead_int() {
	register int c= getchar();
	int x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar());
	for(; c>47 && c<58 ; c = getchar()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
	return x;
}

//int putchar_unlocked(char ch) { return putchar(ch);  }
inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     buf[10] = '\n';
     do 
     {
        buf[--i] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do 
     {
        putchar(buf[i]);
     } while (buf[i++] != '\n');
}

int msb(unsigned int v) {
  static const int pos[32] = {0, 1, 28, 2, 29, 14, 24, 3,
    30, 22, 20, 15, 25, 17, 4, 8, 31, 27, 13, 23, 21, 19,
    16, 7, 26, 12, 18, 6, 11, 5, 10, 9};
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v = (v >> 1) + 1;
  return pos[(v * 0x077CB531UL) >> 27];
}

int main(){
	int t,a;
	scanf("%d",&t);
	while(t--){
		int count=1;
		a=fastRead_int();
		writeInt( ( (a^tt[msb(a)])<<1)+1);
	}
	return 0;
}