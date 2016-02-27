#include <stdio.h>
typedef long long ll;
#define max(a,b) a>b?a:b
int n,a[10000]; ll mi,ma,maxb[10000],maxe[10000],minb[10000],mine[10000];

ll max_so_far = 0, max_ending_here = 0;
ll min_so_far = 0, min_ending_here = 0;

bool neg;
//int getchar_unlocked()  {return getchar();}
inline void Read(int &x) {
	register int c= getchar_unlocked();
	x = 0;neg=0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	if(c=='-') {neg=1; c = getchar_unlocked(); }
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
	if(neg) x=-x;
}

ll absval(ll xy){
	if(xy<0) return -1*xy;
	else return xy; 
}

int main(){
	int t,i;ll mn,j,mx;ll ans;
	scanf("%d",&t);
	while(t--){
		Read(n);
		max_ending_here=max_so_far=min_ending_here=min_so_far=0;
		mi=1000000000; ma=-mi;
		for(i=0;i<n;i++){
			Read(a[i]);
			if(mi>a[i]) mi=a[i];
			if(ma<a[i]) ma=a[i];
			
			max_ending_here = max_ending_here + a[i];
			if(max_ending_here <0)	max_ending_here = 0;
			else if (max_so_far < max_ending_here)	max_so_far = max_ending_here;
			maxb[i]=max_so_far==0?ma:max_so_far;
			
			min_ending_here=min_ending_here + a[i];
			if(min_ending_here >0)	min_ending_here=0;
			else if(min_so_far > min_ending_here)	min_so_far=min_ending_here;
			//printf("mi= %lld\n",mi);
			minb[i]=min_so_far==0?mi:min_so_far;
		}
		//for(i=0;i<n;i++) printf("%lld %lld\n",maxb[i],minb[i]);cout<<endl;
		//cout<<endl;
		mi=1000000000;ma=-mi;
		max_ending_here=max_so_far=min_ending_here=min_so_far=0;
		for(i=n-1;i>=0;i--){
			if(mi>a[i]) mi=a[i];
			if(ma<a[i]) ma=a[i];
			
			max_ending_here = max_ending_here + a[i];
			if(max_ending_here <0)	max_ending_here = 0;
			else if (max_so_far < max_ending_here)	max_so_far = max_ending_here;
			maxe[i]=max_so_far==0?ma:max_so_far;
			
			min_ending_here=min_ending_here + a[i];
			if(min_ending_here >0)	min_ending_here=0;
			else if(min_so_far > min_ending_here)	min_so_far=min_ending_here;
			mine[i]=min_so_far==0?mi:min_so_far;
		}
		//for(i=0;i<n;i++) printf("%lld %lld\n",maxe[i],mine[i]);cout<<endl;
		ans=0;
		for(i=1;i<n;i++){
			//printf("%lld\t%lld\t%lld\t",absval(maxb[i-1]-mine[i]),absval(maxe[i]-minb[i-1]),ans);
			j=max(absval(maxb[i-1]-mine[i]),absval(maxe[i]-minb[i-1])); //printf("%lld\n",j);
			ans=max(ans,j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}