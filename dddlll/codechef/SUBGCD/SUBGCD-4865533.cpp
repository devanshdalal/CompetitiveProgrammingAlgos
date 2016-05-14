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

inline int gcdI(int a,int b){
	while (b) {
		a %= b;
		swap(b, a);
	}
	return a;
}



int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
       	int a[n];
        scanf("%d",&a[0]);
        scanf("%d",&a[1]);
        int g1=gcdI(a[0],a[1]);
       	for (i = 2; i < n; ++i)
       	{
        	scanf("%d",&a[i]);
        	g1=gcdI(g1,a[i]);
       	}


        	printf("%d\n",g1==1? n:-1);
    }
    return 0;
}