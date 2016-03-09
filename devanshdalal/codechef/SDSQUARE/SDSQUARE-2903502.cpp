#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
#define mod 1000000007
using namespace std;
typedef long long ll;

int a[100000];
ll n,m;

 
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

bool isgood(ll b){
	while(b>0){
		int p=b%10;
		if( !(p==0 or p==1 or p==4 or p==9) )return 0;
		b=b/10;
	}
	return 1;
}


int cou[200001];

int main(){
//cout<<sqrt(ll(1000000000)*ll(1000000000));
int t,i, x,y;
scanf("%d",&t);
cou[0]=1;
for(i=1;i<100001;i++){
	cou[i]=cou[i-1];
	if(isgood(ll(i)*ll(i)))cou[i]++;
}

while(t--){
	scanf("%lld%lld",&n,&m);
	x=sqrt(n);
	y=sqrt(m);
	int ans;
	if(ll(x)*ll(x)==n and isgood(n)){
		ans=cou[y]-cou[x]+1;
	}
	else{
		ans=cou[y]-cou[x];
	}
	printf("%d\n", ans);
}
return 0;
}