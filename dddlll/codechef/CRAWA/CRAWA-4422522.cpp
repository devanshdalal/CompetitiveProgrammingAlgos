#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include <queue>
#include<vector>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
#define P pair<int,int>
using namespace std;
const ll mod = 1000000007;


class comp1 {
    public:
    bool operator()(P t1, P t2) // Returns true if t1 is earlier than t2
    {
       return t1.second>t2.second;
    }
};

int main(){
    int t,i,j,k,l,x,y,p,q;
    scanf("%d",&t);
    bool done;
    while(t--){
    	done=0;
    	scanf("%d%d",&x,&y);
    	if ((x>0) and (x&1) and (y<=x+1 and y>=-x+1))
    	{
    		done=true;
    	}else if (x<0 and (x%2==0) and (abs(y)<=-x) )
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