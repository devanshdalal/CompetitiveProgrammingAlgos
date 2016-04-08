#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
typedef long long ll;
using namespace std;

const ll mymod = 1000000007;

int main(){
    ll t,i,j,k,l,n,y,cmax=0,a0=mymod,cd=mymod;
    scanf("%lld%lld",&n,&k);
    ll b[n+2];
    for (i = 0; i < n; ++i)
        scanf("%lld",&b[i]); 

    if (n<102)
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
	    			for (l=y=0; l <n ; ++l)if (b[l]!=na+l*nd)y++;
	    			if (y<=k)a0=na,cd=nd;
    			}
    		}
    }else{
    	unordered_map<ll,ll> rem;
    	ll darray[n+1];
    	for (i = 1; i < n; ++i)
    	{
    		j=darray[i]=b[i]-b[i-1];
			rem[j]=rem[j]+1;
    	}
    	for (unordered_map<ll,ll>::iterator it = rem.begin(); it!=rem.end() ; ++it)
    		if (it->second > cmax )cmax=it->second,cd=it->first;
    	rem.clear();
    	for (i= 1; i < n-1; ++i)
    		if (darray[i]==cd and darray[i+1]==cd)j=b[i]-i*cd,rem[j]=rem[j]+1;
    	cmax=0;
    	for (unordered_map<ll,ll>::iterator it = rem.begin(); it!=rem.end() ; ++it)
    	{
    		if (it->second > cmax )
    		{
    			cmax=it->second;
    			a0=it->first;
    		}
    	}
    }
	for (i = 0; i < n; ++i)
		printf("%lld ",a0+i*cd );
	printf("\n");

    return 0;
}