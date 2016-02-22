#include<cstdio>
#include<algorithm>
typedef long long ll;
#define M 1000000007
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
	int t,n,i,j;ll ar[3];
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&ar[0]);
		scanf("%lld",&ar[1]);
		scanf("%lld",&ar[2]);
		sort(ar,ar+3);
		ar[0]%=M; ar[1]=(ar[1]-1)%M; ar[2]=(ar[2]-2)%M;
		printf("%lld\n",(((ar[0]*ar[1])%M)*ar[2])%M);
	}
	return 0;
}