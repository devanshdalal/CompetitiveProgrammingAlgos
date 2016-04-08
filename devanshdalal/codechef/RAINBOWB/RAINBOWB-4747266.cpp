#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    int t,i,n,m,p,q;
    scanf("%d",&n);
    if (n<13)
        printf("0\n");
    else{
        ll *fact=new ll[n],*inv=new ll[n],*finv=new ll[n],ans=0;
        finv[0]=finv[1]=inv[1]=fact[0]=fact[1]=1;
        for(i=2;i<n;i++){
            inv[i]=mod-inv[mod%i]*(mod/i)%mod;
            fact[i]=(fact[i-1]*i)%mod;
            finv[i]=(finv[i-1]*inv[i])%mod;
        }
        n-=13;
        for (p = 0; p <= n; ++p)
        {
            ll ncr=((fact[p+6]*finv[6])%mod)*finv[p];
            ncr%=mod;
            ll n2=((fact[n-p+5]*finv[5])%mod)*finv[n-p];
            n2%=mod;
            if ((n-p)&1)
                ans-=(ncr*n2)%mod;
            else
                ans+=(ncr*n2)%mod;
        }
        printf("%lld\n", (mod+(ans%mod))%mod );
    }

    return 0;
}