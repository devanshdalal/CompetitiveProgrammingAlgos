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
    int t,i,j,k,l,n,m,a,b;
    scanf("%d %d%d%d",&n,&m,&a,&b);
    
    if ( d(b)/d(m) <= d(a) )
    {
    	i=n/m ;
    	t=b*i + min(b,(n%m)*a);
    }else{
    	t=a*n;
    }

    printf("%d\n", t);
    return 0;
}