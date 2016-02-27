#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100000];bool b[100000];

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
	int t,i,j,k,res,te;
	Read(n);
	for(i=0;i<n;i++) b[i]=true;
	for(k=0;k<n;k++) Read(a[k]);
	sort(a,a+n);
	int co=n;
	for(i=n-1;i>=0;i--){
		if(b[i]==false) continue;
		//if(i<n-1 and a[i+1]==a[i]) continue;
		for(j=0;j<i;j++){
			if(b[j]==false) continue;
			//if(j>0 and a[j-1]==a[j]) continue;
			if((a[i]+a[j])&1) continue;
			res=binarySearch((a[i]+a[j])/2);
			if(a[res]==(a[i]+a[j])/2 and b[res]){ b[res]=false; co--;}
			while(a[++res]==(a[i]+a[j])/2 and b[res]){ b[res]=false; co--;}
			while(a[--res]==(a[i]+a[j])/2 and b[res]){ b[res]=false; co--;}
		}
	}
	printf("%d\n",co);
	for(i=0;i<n;i++){
		if(b[i]) printf("%d ",a[i]);
	}
	return 0;
}