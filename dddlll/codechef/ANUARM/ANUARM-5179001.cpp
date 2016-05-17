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

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int a[100001];
    while(t--){
        scanf("%d %d",&n,&m);
        // for (i = 0; i < n; ++i)
        // {
        // 	scanf("%d",&a[i]);
        // }
        int max1=-1,min1=n;
        for (i = 0; i < m; ++i)
        {
        	scanf("%d",&p);
        	if (p<min1)
        	{
        		min1=p;
        	}
        	if(p>max1){
        		max1=p;
        	}
        }
        for (i = 0; i < n-1 ; ++i)
        {
        	printf("%d ", max(abs(i-min1),abs(i-max1)) );
        }
        printf("%d\n", max(abs(i-min1),abs(i-max1)) );
    }
    return 0;
}