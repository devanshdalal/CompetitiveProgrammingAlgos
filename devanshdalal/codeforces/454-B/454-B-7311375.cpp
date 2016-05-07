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
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n; ++i)
    {
	    scanf("%d",&a[i]);
    }
    int inv=0,invind=-1;
    for (i = 1; i < n; ++i)
    {
    	if(a[i-1]>a[i]){
    		invind=i;
    		inv++;
    	}
    }
    if (inv>1)
    {
    	printf("-1\n");
    }else if(inv==0){
    	printf("0\n");
    }else{
    	for (i = 0; i < n; ++i)
    	{
    		if (a[(invind+i)%n]>a[(invind+i+1)%n])
    		{
    			break;
    		}
    	}
    	if(i==n-1)printf("%d\n",n - invind );
    	else printf("-1\n");
    	// printf("%d\n",n - invind );
    }


    return 0;
}