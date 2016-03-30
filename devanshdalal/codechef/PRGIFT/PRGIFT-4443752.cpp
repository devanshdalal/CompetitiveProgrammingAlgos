#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
const ll mod = 1000000007;
using namespace std;

int main(){
    int t,i,n,m,p,q,k;
    scanf("%d",&t);
    while(t--){
        p=0;
        scanf("%d%d",&n,&k);
        for (i = 0; i < n; ++i){
            scanf("%d",&q);
            if(q%2==0)p++;
        }

        
        printf(p>=k and not(k==0 and p==n) ? "YES\n":"NO\n");

    }
    return 0;
}