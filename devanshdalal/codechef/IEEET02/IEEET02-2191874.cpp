#include<cstdio>
#include<algorithm>
typedef long long ll;
#define M 1000000007
using namespace std;
#define BUF 4096
char ibuf[BUF];
int ipt = BUF;
int al[]={220, 1184, 2620, 5020, 6232, 10744, 12285, 17296, 63020, 66928, 67095, 69615, 79750, 100485, 122265, 122368, 141664, 142310};
int all[]={284,1210,2924,5564,6368,10856,14595,18416,76084,66992,71145,87633,88730,124155,139815,123152,153176,168730};
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
	int t,n,i,j;bool don;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		don=false;
		for(i=0;i<13;i++){
			 if(al[i]==n)   {don=true; printf("Yes, amicable with %d\n", all[i]);  }
			 else if(all[i]==n) {don=true; printf("Yes, amicable with %d\n",al[i]); }
		}
		if(!don) printf("No\n");
	}
	return 0;
}