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
    while(t--){
        scanf("%d",&n);
        char a[n][n];
        for (i = 0; i < n; ++i)
        {
        	scanf("%s",a[i]);
        }
        
        bool f1[n][n],f2[n][n];
        for (i = 0; i <n; ++i)
        {
        	f2[i][n-1]=a[i][n-1]=='.'?true:false;
        	f1[n-1][i]=a[n-1][i]=='.'?true:false;
        }
        p=0;
        for (i = n-2; i >=0; --i)
        {
        	for (j= 0; j<n; ++j)
        	{
	        	if (f1[i+1][j] and a[i][j]=='.')
	        	{
	        		f1[i][j]=true;
	        	}else{	
	        		f1[i][j]=false;
	        	}
        	}
        	for (j= 0; j<n; ++j)
        	{
	        	if (f2[j][i+1] and a[j][i]=='.')
	        	{
	        		f2[j][i]=true;
	        	}else{	
	        		f2[j][i]=false;
	        	}
        	}
        }
        p=0;
        for (i = 0; i < n; ++i)
        {
        	for (j = 0; j < n; ++j)
        	{
        		if (f1[i][j] and f2[i][j])
        		{
        			// cerr << i << " " << j << endl;
        			p++;
        		}
        	}
        }

        printf("%d\n", p);
    }
    return 0;
}