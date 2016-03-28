#include<stdio.h>
// #include<iostream>
// #include<algorithm>
// #include<iomanip.h>
#define LIMIT 501
typedef long long ll;
const ll mod = 1000000007;
// using namespace std;

ll mem[LIMIT][500*250];
ll fact[LIMIT],ifac[LIMIT];

/*
zmd<VDJSF djc dsjC vdsNv dfmzv fdvfdv fnJ
devansh dalal's solution SEAEQ
*/

inline ll findE(ll n,ll e){
    if (e>n*(n-1)/2)
        return mem[n][n*(n-1)/2];
    return mem[n][e];
}

inline ll ncr(ll n ,ll r){
    if (n==r || r==0)return 1;
    ll tmp=(fact[n]*ifac[n-r])%mod;
    return (tmp*ifac[r])%mod;
}

inline ll doMod(ll x){
    if (x>=mod)
        return x-mod;
    return x;
}

inline ll m2(ll x){
    if (x>=mod)
        return x-mod;
    else if (x<0)
        return x+mod;
    return x;
}

inline ll mpow(ll base, ll exponent)
{
    ll result = 1;
    while (exponent ){
        if (exponent&1)result = (result * base)%mod;
        exponent = exponent >> 1;
        base = (base * base)%mod;
    }
    return result;
}

int main(){
    int t,i,j,k,n,E;
    // ios_base::sync_with_stdio(false);
    for (i = fact[0]=1; i < LIMIT; ++i){
        fact[i]=(i*fact[i-1])%mod;
        ifac[i]=mpow(fact[i],mod-2);
        // mem[i]=new ll[i*i/2 + 1];
        mem[i][0]=1;
    }
    mem[2][1]=2;
    mem[3][1]=3;mem[3][2]=5;mem[3][3]=6;
    mem[4][1]=4;mem[4][2]=9;mem[4][3]=15;mem[4][4]=20;mem[4][5]=23;mem[4][6]=24;

    for (i = 5; i<LIMIT; ++i)
    {
        int prange=(i-1)*(i-2)/2,range=i*(i-1)/2;
        for (j = 1; j <i ; ++j)
            mem[i][j]=doMod(mem[i][j-1]+mem[i-1][j]);
        for (j = i; j <prange ; ++j)
            mem[i][j]=m2(mem[i][j-1]+mem[i-1][j]-mem[i-1][j-i]);
        for (j = prange; j <= range ; ++j)
            mem[i][j]=m2(mem[i][j-1]+mem[i-1][prange]-mem[i-1][j-i]);
    }

    scanf("%d",&t);
    while(t--){
        ll ans=0;
        scanf("%d %d",&n, &E);
        for ( k = 1; k <= n; ++k)
        {
            ll v1=ncr(n,k);
            ll term1=(fact[n-k]*v1)%mod;
            ll term2=(fact[n-k+1]*v1)%mod;
            term1=(term1*term2)%mod;
            ans+=(term1*findE(k,E))%mod;
        }

        printf("%d\n", (int)(ans%mod) );
    }
    return 0;
}