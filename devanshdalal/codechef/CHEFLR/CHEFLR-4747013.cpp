#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ul;
using namespace std;

int main(){
    const ll mod = 1000000007;
    int t,i,l;
    scanf("%d",&t);
    char a[100002];
    while(t--){
        scanf("%s",a);
        ll ans=1;
        l=strlen(a);
        for (i = 0; i < l; ++i)
            if (i&1)
                if (a[i]=='l')
                    ans=(-1 + ans*2)%mod;
                else
                    ans=(1 + ans*2)%mod;
            else
                if (a[i]=='l')
                    ans=(ans*2)%mod;
                else
                    ans=(2 + ans*2)%mod;
        printf("%lld\n", (ans+mod)%mod );
    }

    return 0;
}