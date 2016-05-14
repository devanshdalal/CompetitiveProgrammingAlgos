#include<unordered_map>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;

const ll mod = 1000000007;

int main(){
    ll t,i,j,k,l,n,y;
    scanf("%lld%lld",&n,&k);
    ll b[n+2];
    for (i = 0; i < n; ++i)
		scanf("%lld",&b[i]); 

    ll cmax=0,a0=mod,cd=mod;
    if (n<101)
    {
    	ll na,nd;
    	for (i = 0; i < n; ++i)
    		for (j = i+1; j < n; ++j)
    		{
    			nd=(b[j]-b[i])/(j-i);
    			if(nd*(j-i)!=b[j]-b[i])continue;
    			na=b[j]-j*nd;
    			if (na<a0 or (na==a0 and nd<cd))
    			{
	    			for (l=y=0; l <n ; ++l)
	    				if (b[l]!=na+l*nd)
	    					y++;
	    			if (y<=k)
	    			{
	    				a0=na;
	    				cd=nd;
	    			}
    			}
    		}
    }else{
    	unordered_map<ll,ll> mem;
    	ll diff[n+1];
    	for (i = 1; i < n; ++i)
    	{
    		j=diff[i]=b[i]-b[i-1];
			mem[j]=mem[j]+1;
    	}
    	for (unordered_map<ll,ll>::iterator it = mem.begin(); it!=mem.end() ; ++it)
    		if (it->second > cmax )
    		{
    			cmax=it->second;
    			cd=it->first;
    		}
    	mem.clear();
    	for (i= 1; i < n-1; ++i)
    		if (diff[i]==cd and diff[i+1]==cd)
    		{
    			j=b[i]-i*cd;
				mem[j]=mem[j]+1;
    		}
    	cmax=0;
    	for (unordered_map<ll,ll>::iterator it = mem.begin(); it!=mem.end() ; ++it)
    	{
    		if (it->second > cmax )
    		{
    			cmax=it->second;
    			a0=it->first;
    		}
    	}
    }
	for (i = 0; i < n; ++i)
	{
		printf("%lld ",a0+i*cd );
	}printf("\n");

    return 0;
}