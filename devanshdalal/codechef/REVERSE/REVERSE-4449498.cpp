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

class myComp {
    public:
    bool operator()(P t1, P t2)
    {
       return t1.second>t2.second;
    }
};


int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d%d",&n,&m);
    vector< P > v[n+1];
    bool visited[n+1];
    int arr[100000];
    memset(visited,0,sizeof(visited));
    for (i = 0; i < m; ++i){
    	scanf("%d%d",&p,&q);
    	if(p==q)continue;
    	v[q].push_back(make_pair(p,1));
        v[p].push_back(make_pair(q,0));
    }
    priority_queue< P , vector< P > , myComp > heap;

    heap.push(make_pair(1,0));
    P top=heap.top();
    while(top.first!=n and !heap.empty()){
    	top=heap.top();
    	heap.pop();
    	visited[k=top.first]=1;
    	l=top.second;
    	for (vector<P >::iterator it = v[k].begin() ; it != v[k].end(); ++it){
    		P node=*it;
    		if (!visited[node.first])
    		{
    			heap.push(make_pair(node.first,l+node.second));
    		}
    	}
    }

    printf("%d\n",top.first==n?top.second:-1 );


    return 0;
}