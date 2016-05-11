#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,a[100000];
#define mod 1000000000;

int getchar_unlocked()  {return getchar();}
inline void Read(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int lo, hi, mi;
int binarySearch(int xx){
	// want: P(lo) is always false, and P(hi) always true
	lo=0; hi=n-1;
	while(lo+1<hi){
	mi=(lo+hi)/2;
	if(a[mi]>=xx) hi=mi; else lo=mi;
	}
	return hi;
}

int main(){
	int i,j,k;
	Read(n);Read(q);
	for(k=1;k<=n;k++) Read(a[k]);
	int te,lhs,rhs,fi,se,thi,re;
	while(q--){
		Read(te);
		if(te==1){
			Read(j);
			Read(a[j]);
		}
		else if(te==2){
			Read(lhs);Read(rhs);
			if(rhs==lhs) printf("%d\n",a[lhs]);
			else if(rhs-lhs==1) printf("%d\n",(a[lhs]+a[rhs])%1000000000);
			else{
				thi=a[rhs];se=a[rhs-1],fi=a[rhs-2];
				for(k=rhs;k>lhs+1;k--){
					re=se;
					se=(fi+thi)%mod;
					thi=(thi+re)%mod;
					fi=a[k-3];
					//cout<<fi<<" 	"<<se<<" 	"<<thi<<endl;
				}
				//if(rhs-lhs>)re=se; se=(fi+thi)%mod; thi=(thi+re)%mod;
				//cout<< fi <<" "<< se <<" thi:"<< thi <<endl;
				printf("%d\n",(thi+se)%1000000000);
			}
		}else{
			Read(lhs);Read(rhs);Read(re);
			for(;lhs<=rhs;lhs++)a[lhs]+=re;
		}
	}
	return 0;
}