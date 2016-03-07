#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
#define moD 1000000007
using namespace std;
const int limit=1000;


//int getchar_unlocked() { return getchar(); }
void r(int &x){
	register unsigned int c = getchar_unlocked();
	x = 0;int neg=0;
	for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
	if(c=='-'){neg=1; c=getchar_unlocked(); }
	for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
	if(neg)x=-x;
}

struct data{
	int x,l,ind,ans;
} arr[limit];

bool comp(data a,data b){
	return a.x<b.x;
}

bool co2(data a,data b){
	return a.ind <= b.ind;
}

int main(){
int t,i,j,k,l,a,b,n;
	r(t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			r(arr[i].x);
			r(arr[i].l);
			arr[i].ind=i;
			arr[i].ans=0;
		}
		sort(arr+1,arr+n+1,comp);
		for(i=n-1;i>=0;i--){
			int val=arr[i].x+arr[i].l;
			for(j=i+1;j<=n and val>arr[j].x;j++){
				arr[i].ans++;
				val=max(val,arr[j].x+arr[j].l);
			}
		}
		sort(arr+1,arr+n+1,co2);
		for(i=1;i<=n;i++){
			//cout<<arr[i].x<<" "<<arr[i].ind<<"             ";
			printf("%d\n",arr[i].ans+1);
		}

	}

    return 0;
}