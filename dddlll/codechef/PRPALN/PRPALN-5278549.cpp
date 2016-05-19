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
    bool one[100001],two[100001],three[100001];
    while(t--){
        scanf("%s",a);
        l=strlen(a);
        bool done=false;
        for (i = 0; i <l; ++i)
        {
        	one[i]=two[i]=three[i]=false;
        }
        if(l&1){
        	two[l/2]=true;
	    }
        for (i = l/2-1; i>=0; --i)
        {
        	if ((i==l/2-1 or one[i+1]) and a[i+1]==a[l-1-i])one[i]=true;
        	if ( (i==l/2-1 or two[i+1]) and a[i]==a[l-1-i])two[i]=true;
        	if ( (i==l/2-1 or three[i+1]) and a[i]==a[l-i-2] )three[i]=true;
        }
        for (i = 0; i<l/2 ; )
        {
        	if (two[i] or three[i] or one[i])
        	{
        		done=true;
        		break;
        	}
        	if (a[i]==a[l-i-1])
        	{
        		i++;
        	}else{
        		done=false;
        		break;
        	}
        }
        
        printf(done?"YES\n":"NO\n");
    }
    return 0;
}