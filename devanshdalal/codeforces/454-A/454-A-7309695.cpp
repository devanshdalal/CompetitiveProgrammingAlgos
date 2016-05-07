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
    char a[n][n];
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < abs(n/2 -i); ++j)
    	{
    		a[i][j]=a[i][n-1-j]='*';
    	}
    	for (j = abs(n/2-i); j <= n/2; ++j)
    	{
    		a[i][j]=a[i][n-1-j]='D';
    	}
    	a[i][n]='\0';
    	printf("%s\n", a[i] );

    }
    return 0;
}