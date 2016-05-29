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

int readInt() {
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
int ta[11][101];

int main(){
	int t,n,i,j,k;
	for(i=0;i<11;i++) ta[i][0]=1;
	for(i=0;i<=14;i++) ta[1][i]=1;
	for(;i<101;i++) ta[1][i]=0;
	for(i=1;i<101;i++){
		for(j=2;j<11;j++){
			ta[j][i]=0;
			for(k=i;k>=0 && i-k<=14;k--){
				ta[j][i]+=ta[j-1][k];
			}
		}
	}
	ta[0][0]=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);scanf("%d",&k);
		printf("%d\n",ta[n][k]);
	}
	printf("***\n");
	return 0;
}
