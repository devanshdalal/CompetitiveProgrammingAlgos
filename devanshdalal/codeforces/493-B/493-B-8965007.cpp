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


struct data
{
	int p,q;
	char team[2],card[2];
};

bool comp(data a, data b){
	return a.p < b.p ;
}

int main(){
    int t,i=0,j=0,k,l,n,m,p,q;    
    scanf("%d",&t);
    int a[200000],b[200000];
    ll s1=0,s2=0;
    while(t--){
   		scanf("%d",&p);
   		if (p>0)
   		{
   			a[i++]=p;
   			s1+=p;
   			q=0;
   		}else{
   			b[j++]=-p;
			s2+=(-p);
			q=1;   			
   		}
    }
    n=i;
    m=j;
    if (s1>s2)
    {
    	printf("first\n");
    }else if (s1<s2)
    {
    	printf("second\n");
    }else{
    	if (n>m)
    	{
    		for (i = 0; i < m; ++i)
    		{
    			if (a[i]==b[i])continue;
    			if (a[i]<b[i])break;
    			if (a[i]>b[i]){
    				i=m;
    				break;
    			}
    		}
    		if (i==m)
    		{
    			printf("first\n" );
    		}else{
    			printf("second\n" );
    		}
    	}else if(m>n){
    		for (i = 0; i < n; ++i)
    		{
    			if (a[i]==b[i])continue;
    			if (a[i]>b[i])break;
    			if (a[i]<b[i]){
    				i=n;
    				break;
    			}
    		}
    		if (i==n)
    		{
    			printf("second\n" );
    		}else{
    			printf("first\n" );
    		}
    	}else{
    		for (i = 0; i <n; ++i)
    		{
    			// if (a[i]==b[i])break;
    			if (a[i]>b[i])
    			{
    				printf("first\n" );
    				break;
    			}
    			if (a[i]<b[i])
    			{
    				printf("second\n" );
    				break;
    			}
    		}
    		if (i==n)
    		{
    			printf(q==0? "first\n":"second\n");
    		}
    	}	
    }

    return 0;
}