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
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef unsigned long long ll;
typedef double d;
using namespace std;

int vec[20000];

int main(){
    register int t,i,j,n,k,Li,Hi,Q;
    
    scanf("%d",&t);
    while(t--){
    	// map<int,int> my;
    	scanf("%d%d",&n,&k);
    	for ( i = 0; i < n; ++i)
    	{
    		scanf("%d",&vec[i]);
    	}
    	int mind=2000000000;
    	for (i = 0; i < n; ++i)
    	{
    		for (int j = i+1; j< n; ++j)
    		{
    			if(abs(vec[i]+vec[j]-k)<mind){
    				mind=abs(vec[i]+vec[j]-k);
    				// cout<< abs(vec[i]+vec[j]-k) << endl;
    			}
    		}
    	}
    	int ans=0;
    	for (i = 0; i < n; ++i)
    	{
    		for (int j = i+1; j< n; ++j)
    		{
    			if(abs(vec[i]+vec[j]-k)==mind ){
   					ans++;
   					// my[vec[i]]=vec[j];
    			}
    		}
    	}
    	printf("%d %d\n",mind,ans);
    }

    return 0;
}