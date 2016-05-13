#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    char a[100011];
    while(t--){
        scanf("%s",a);
        l=strlen(a);
        ll ans=1;
        for (i = 0; i < l; ++i)
        {
            if (i&1)
            {
                if (a[i]=='l')
                {
                    ans=(-1 + ans*2)%mod;
                }else{
                    ans=(1 + ans*2)%mod;
                }
            }else{
                if (a[i]=='l')
                {
                    ans=(ans*2)%mod;
                }else{
                    ans=(2 + ans*2)%mod;
                }
            }
        }
        printf("%lld\n", (ans+mod)%mod );
    }

    return 0;
}