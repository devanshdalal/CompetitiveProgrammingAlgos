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
    scanf("%d%d",&m,&n);
    // d a[n+1];

    // a[1]=(m+1.0)/2.0;
    // for (i = 2; i <=n; ++i)
    // {
    // 	a[i]=(a[i-1]*(a[i-1]-1)/d(m-1)) + ((m-a[i-1])/d(m-1))*(m+a[i-1])/2.0;
    // }


    d ans=0;
    for (i = 1; i <=m; ++i)
    {
    	ans+=(pow(d(i)/d(m),n)-pow(d(i-1)/d(m),n))*i;
    }


	printf("%lf\n", ans );
	// printf("%lf\n", a[n] );


    return 0;
}