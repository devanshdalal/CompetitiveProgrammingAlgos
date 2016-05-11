#include<cstdio>
#include<fstream>
typedef long long ll;
#define M 1000000007
using namespace std;
#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

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

int r() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}


int main(){
	int t,i,j,l,k=0;
	scanf("%d",&t);
	int maxc=-1,cma1=0,cma0=0;
	for(i=0;i<t;i++){
		scanf("%d",&l);
		k+=l;
		if(l==0){cma0++;}
		else{
			cma1++;
		}
		if(cma0-cma1>maxc)maxc=cma0-cma1;
		if(cma0-cma1<=0){cma0=cma1=0;}
	}
	printf("%d\n",maxc+k);
	return 0;
}