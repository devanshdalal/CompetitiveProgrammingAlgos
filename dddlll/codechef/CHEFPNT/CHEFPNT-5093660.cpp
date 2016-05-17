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
#define P pair<int,int>
const ll mod = 1000000007;

int a[101][101],b[101][101];

int main(){
    int i,j,k,l,n,m,p,q;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < k; ++i)
    {
    	scanf("%d %d",&p,&q);
    	a[p][q]=b[p][q]=-1;
    }
    std::vector<P> v,w;
    for (i = 1; i <=n; ++i)
    {
    	if (a[i][1]!=-1)
    	{
    		v.push_back(make_pair(i,1));
    	}
    	for (j = 1; j <m; ++j)
    	{
    		if (a[i][j]==-1 and a[i][j+1]!=-1)
    		{
    			v.push_back(make_pair(i,j+1));
    		}
    	}
    }

    for (i = 1; i <=m; ++i)
    {
    	if (a[1][i]!=-1)
    	{
    		w.push_back(make_pair(1,i));
    	}
    	for (j = 1; j <n; ++j)
    	{
    		if (a[j][i]==-1 and a[j+1][i]!=-1)
    		{
    			w.push_back(make_pair(j+1,i));
    		}
    	}
    }

    if (v.size()>w.size())
    {
    	printf("%d\n", j=w.size() );
	    for (i = 0; i <j ; ++i)
	    {
	    	printf("%d %d 1\n", w[i].first, w[i].second );
	    }
    }else{
	    printf("%d\n", j=v.size() );
	    for (i = 0; i <j ; ++i)
	    {
	    	printf("%d %d 0\n", v[i].first, v[i].second );
	    }
    	
    }
    return 0;
}