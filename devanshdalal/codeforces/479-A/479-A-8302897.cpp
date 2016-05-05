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
    int t,i,j,k,a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d=max(a*b,a+b),e=max(b*c,b+c);
    d=max(d*c,d+c);
    e=max(e*a,e+a);
    printf("%d\n",max(d,e) );

    
    return 0;
}