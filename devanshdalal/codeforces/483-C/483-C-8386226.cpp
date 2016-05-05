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
    scanf("%d %d",&n,&k);

    p=0;
    int top=n,bot=1;
    for (i = 1; i<n ; ++i)
    {
    	if (i&1)
    	{
    		cout << (top--) << " " ;
    	}else{
    		cout << (bot++) << " " ;
    	}
    	p++;
    	if (p==k)
    	{
    		break;
    	}
    }

    if (i&1)
    {
    	for ( ; top>=bot ; )
    	{
    		cout << (top--) << " " ; 		
    	}
    }else{
    	for ( ; top>=bot ; )
    	{
    		cout << (bot++) << " " ; 		
    	}
    }
    return 0;
}