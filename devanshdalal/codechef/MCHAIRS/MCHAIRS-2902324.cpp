#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
#define mod 1000000007
using namespace std;
typedef long long ll;

int a[100000],n,m,k;

 
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


ll fp(int x,int m){
	int te=1<<msb((unsigned)m);
	ll acu=1;
	int xx=x;
	while(te){
		acu=m/te?((acu*acu)%mod)*((ll)xx):acu*acu;
		m=m%te;
		te=te/2;
		acu=acu%mod;
	}
return acu;
}


int main(){
int t,i, x,y;
scanf("%d",&t);
while(t--){
	scanf("%d",&n);
	cout<< fp(2,n)-1 <<endl;
}
return 0;
}