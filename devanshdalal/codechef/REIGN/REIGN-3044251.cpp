#include<iostream>
# include<cstdio>
# include<algorithm>
# include<cstring>
# include<vector>
# include<queue>
# include<map>
# include<cmath>
# include<bitset>
using namespace std;
typedef double d;
typedef long long ll;
int n,k;

void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

int main(){
	int t,i,j,x,y;ll l;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int arr[n];
		ll begin[n],end[n];
		for(i=0;i<n;i++){
			r(arr[i]);
		}
		begin[0]=(ll)arr[0];
		end[n-1]=(ll)arr[n-1];
		ll msum=0,mx=begin[0];
		for(i=0;i<n;i++){
			if(mx<msum+(ll)arr[i]){
				mx=msum+(ll)arr[i];
			}
			msum+=(ll)arr[i];
			if(msum<0){
				msum=0;
			}
			begin[i]=mx;
		}
		///from last
		msum=0,mx=(ll)end[n-1];
		for(i=n-1;i>=0;i--){
			if(mx<msum+(ll)arr[i]){
				mx=msum+(ll)arr[i];
			}
			msum+=(ll)arr[i];
			if(msum<0){
				msum=0;
			}
			end[i]=mx;
		}
		mx=-2090000000;
		for(i=0;i<n-k-1;i++){
			j=i+k+1;
			if(mx<begin[i]+end[j])mx=begin[i]+end[j];
		}
		
		printf("%lld\n",mx);
	}
	return 0;
}