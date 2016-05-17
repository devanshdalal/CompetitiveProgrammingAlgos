#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int a[10001];
ll mem[10001],n;

int bsearch(int val,int low,int high){
	while(low<=high){
		int mid=(low+high)/2;
		if (a[mid]<val)
		{
			low=mid+1;
		}else if(a[mid]>val){
			high=mid-1;
		}else{
			int i=mid;
			while(i<=high and a[i]==a[mid]){
				i++;
			}
			return i-1;
		}
	}
	return low;
}
int main(){
    int t,i,j,k,l,f,p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %d",&n,&f);
        memset(mem,0,sizeof(mem) );
        for (i = 0; i < n; ++i){
        	scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (i = 0; i < n; ++i)
        {
        	if (i>0 and a[i]==a[i-1])
        	{
        		mem[i]=mem[i-1]+1;
        		continue;
        	}
        	int ht=a[i];
        	while(ht%f==0){
        		ht=ht/f;
        		int id=bsearch(ht,0,i-1);
        		if (a[id]==ht)
        		{
        			mem[i]=mem[id]+1;
        			break;
        		}
        	}
        }
        ll ans=0;
        for (i = 0; i < n; ++i)
        {
        	// cerr << mem[i] << " ";
        	ans+=(ll)mem[i];
        }
        printf("%lld\n", ans );
        
    }
    return 0;
}