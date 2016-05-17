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
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    char a[100001];
    while(t--){
    	bool count[200];
    	for (i = 97; i < 123; ++i)
    	{
    		count[i]=0;
    	}
        scanf("%s",a);
        l=strlen(a);
        for ( i = 0; i <l; ++i)
        {
        	count[a[i]]=1;
        }
        int ans=0;
        for (i = 97; i < 123; ++i)
    	{
    		ans+=count[i];
    	}
        printf("%d\n", ans);
    }
    return 0;
}