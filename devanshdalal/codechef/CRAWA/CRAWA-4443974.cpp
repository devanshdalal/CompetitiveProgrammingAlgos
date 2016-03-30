#include<cmath>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
#define PA pair<int,int>

int main(){
    int t,x,y,p,q;
    scanf("%d",&t);

    while(t--){
    	bool done=0;
    	scanf("%d%d",&x,&y);
    	if ((x>0) and (x&1) and (y<=x+1 and y>=-x+1))
    	{
    		done=true;
    	}
    	else if (x<0 and (x%2==0) and (abs(y)<=-x) )
    	{	
    		done=true;
    	}
    	else if (y>0 and (y%2==0) and (x<=y-1 and x>=-y) )
    	{
    		done=true;
    	}
    	else if (y<0 and (y%2==0) and (x<=-y+1 and x>=y) )
    	{
    		done=true;
    	}


    	printf(done or (x==0 and y==0)? "YES\n":"NO\n" );

    }
    



    return 0;
}