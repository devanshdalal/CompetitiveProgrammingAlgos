#include<cstdio>
#include<algorithm>
using namespace std;
#define BUF 4096
int fi[101];
int le[101];
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
	int t,n,i,j,l,max,te;
	t=readInt();
	//printf("fdesds");
	while(t--){
		n=readInt();
		for(i=0;i<n;i++) fi[i]=readInt();
		for(i=0;i<n;i++) le[i]=readInt();
		sort(fi,fi+n);
		sort(le,le+n);
		te=1;max=1;
		for(i=1,j=0;i<n;i++){
			while(le[j]<=fi[i]) {te--; j++;  }
			te++;
			if(te>max) max=te;
		}
		printf("%d\n",max);
	}
	return 0;
}