#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include <queue>
#include<stdio.h>
#include<vector>
#define P pair<int,int>
using namespace std;
typedef double d;

#define pb push_back

int point[500];
class myComp {
    public:
    bool operator()(int t1, int t2)
    {
       return point[t1]<point[t2];
    }
};


int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int a[500];
    bool vis[500];
    while(t--){
    	memset(vis,0,sizeof(vis));
	    scanf("%d%d",&n,&m);
	    int act=0;
	    for (i = 0; i < m; ++i)
	    {
	    	scanf("%d",&a[i]);
	    	point[i]=500;
	    }

	    for ( i = 0; i < m; ++i)
	    {
	    	for (j = i+1; j < m; ++j)
	    	{
	    		if(a[i]==a[j]){
	    			point[i]=j;
	    			break;
	    		}
	    	}
	    }
	    
	    priority_queue< int , vector< int > , myComp > heap;
	    
	    int tp,ans=0;
	    for (i = 0; i < m; ++i)
	    {
	    	if (vis[a[i]])
	    	{
	    		heap.push(i);
	    		continue;
	    	}
	    	else{
		    	if (act<n)
		    	{
		    		act++;
		    	}else{
		    		tp=heap.top();
		    		while(!vis[a[tp]]){
		    			tp=heap.top();
		    			heap.pop();
		    		}
		    		vis[a[tp]]=0;
		    	}
		    	vis[a[i]]=true;
		    	heap.push(i);
	    		ans++;
	    		
	    	}
	    }

    	printf("%d\n",ans );
    }


    return 0;
}