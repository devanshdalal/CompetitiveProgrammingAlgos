#include<stdio.h>
#include<cstring>
int tt[]={1,2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int putchar_unlocked(char ch) { return putchar(ch);  }
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
        putchar_unlocked(buf[i]);
     } while (buf[i++] != '\n');
}

int main(){
	int lis[60];char a[201];
	register int i,t,l,ans;
	scanf("%d",&t);
	for(i=0;i<60;i++) lis[i]=0;
	while(t--){
		scanf("%s",&a);
		l=strlen(a);ans=0;
		for(i=0;i<l;i++){
			lis[a[i]-'A']++;
		}
		for(i=0;i<60;i++){
			ans+=(lis[i]>>1);
			ans+=(1&lis[i]);
			lis[i]=0;
		}
		writeInt(ans);
	}
	return 0;
}