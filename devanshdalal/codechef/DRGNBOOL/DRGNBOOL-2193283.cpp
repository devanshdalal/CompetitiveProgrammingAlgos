#include<stdio.h>

//int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
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
        putchar_unlocked(buf[i]);
     } while (buf[i++] != '\n');
}

int main(){
	int t,n,m,i,cha,level,bal;
	fastRead_int(t);
	while(t--){
		int ta[101]={0};
		bal=0;
		fastRead_int(n); fastRead_int(m);
		for(i=1;i<=n;i++){
			fastRead_int(cha); fastRead_int(level);
			ta[level]+=cha;
		}
		for(i=1;i<=m;i++){
			fastRead_int(cha); fastRead_int(level);
			ta[level]-=cha;
		}
		for(i=1;i<101;i++){
			if(ta[i]<0) bal-=ta[i];
		}
		writeInt(bal);
	}
	return 0;
}