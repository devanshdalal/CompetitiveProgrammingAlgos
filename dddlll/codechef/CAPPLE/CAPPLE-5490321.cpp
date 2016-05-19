#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<cassert>
typedef long long ll;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    bool a[100001];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,false,sizeof(a));
        for (i = q = 0; i < n; ++i)
        {
        	scanf("%d",&p);
        	if (!a[p]){
				a[p]=true;
        		q++;
        	}
        }
        printf("%d\n", q);
    }
    return 0;
}