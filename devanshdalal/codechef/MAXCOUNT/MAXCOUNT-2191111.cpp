#include<cstdio>
#include<algorithm>
using namespace std;
#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

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

int main(){
	int t,n,i,j,te;
	t=readInt();
	while(t--){
		int ar[10001]={0},in,val=0;
		//for(i=0;i<1000;i++) printf("%d\t",ar[i]);
		n=readInt();
		for(i=0;i<n;i++){
			j=readInt();
			ar[j]++;
			if(ar[j]>val) {val=ar[j]; in=j; }
			else if(ar[j]==val){ in=in<j?in:j; }
		}
		printf("%d %d\n",in,val);
	}
	return 0;
}