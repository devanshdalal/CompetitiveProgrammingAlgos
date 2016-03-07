#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
#define moD 1000000007
using namespace std;
typedef long long ll;
const int limit=1000010;




//int getchar_unlocked() { return getchar(); }
void r(int &x){
	register unsigned int c = getchar_unlocked();
	x = 0;int neg=0;
	for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
	if(c=='-'){neg=1; c=getchar_unlocked(); }
	for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg)x=-x;
}


int main(){
int t,i,j,k,l,b,q,n;
	r(t);
	while(t--){
		r(n);
		r(q);
		int a[n+1],co[n+1];
		for(i=0;i<n;i++){
			r(a[i]);
			co[i]=0;
		}
		sort(a,a+n);

		for(i=0;i<q	;i++){
			r(l);
			r(b);
			l--;
			co[l]++;
			co[b]--;
		}
		for(i=1;i<n;i++){
			co[i]+=co[i-1];
		}
		sort(co,co+n);

		ll ans=0;
		for(i=n-1;i>=0;i--){
			ans+=ll(co[i])*ll(a[i]);
		}
		printf("%lld\n",ans);
	}

    return 0;
}