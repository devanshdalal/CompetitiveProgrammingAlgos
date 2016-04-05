#include<stdio.h>
typedef long long ll;
const ll mod = 1000000009;
#define N 1000005

int main(){
    int t,i,j,k,l,n,p;
    scanf("%d",&t);    
    int accu[N],a[N];
    int *c=new int[N],*preI=new int[8*N];
    while(t--){
        scanf("%d %d",&n,&a[1]);
        for ( i = 2; i <= n; ++i){
            scanf("%d",&a[i]);
            preI[c[i]=4*N+a[i]-a[i-1]]=1;
        }
        accu[1]=1;
        accu[0]=0;
        for (i = 2; i <= n; ++i){
            accu[i]= (accu[i-1]<<1) - accu[preI[c[i]]-1];
            preI[c[i]]=i;
            if(accu[i]>mod)accu[i]-=mod;
            else if(accu[i]<0)accu[i]+=mod;
        }

        printf("%lld\n", ( ll(accu[n])-1+mod)%mod );
    }
    return 0;
}