#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    bool a[3002];
    int b[2000];
    while(t--){
        scanf("%d %d",&n,&k);
        m=0;
        memset(a,0,sizeof(a));
        // memset(a,0,sizeof(taken));
        for (i = 1; i <=n; ++i)
        {
    		scanf("%d",&b[i]);
    		// a[b[i]]=true;
        }
        a[0]=1;
        for (i = 1; i <=n; ++i)
        {
        	p=b[i];
        	for (j = 0; j<1024; ++j)
        	{
        		if(a[j])a[j^p]=1;
        	}
        }


        // while(true){
        // 	for (i = 0; i <1024; ++i)
        // 	{
        // 		if (a[i] and !taken[i])
        // 		{
        // 			for (j=i+1; j<1024; ++j)
        // 			{
        // 				if (!a[j])continue;
        // 				a[j^i]=1;
        // 			}
        // 			taken[i]=true;
        // 			break;
        // 		}
        // 	}
        // 	// cerr << i << endl;
        // 	if(i>=1024)break;
        // }

        for (i = 0; i <1024; ++i)
        {
        	if (a[i])
        	{
        		m=max(i^k,m);
        	}
        }
        printf("%d\n",m );

    }
    return 0;
}