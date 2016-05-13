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
    int t,i,j,k,l,n,m,p,q;
    scanf("%d%d",&n,&m);
    vector< P > v[n+1];
    bool vis[n+1];
    memset(vis,0,sizeof(vis));
    for (i = 0; i < m; ++i){
    	scanf("%d%d",&p,&q);
    	if(p==q)continue;
    	v[p].push_back(make_pair(q,0));
    	v[q].push_back(make_pair(p,1));
    }
    priority_queue< P , vector< P > , comp1 > pq;

    pq.push(make_pair(1,0));
    P top=pq.top();
    while(top.first!=n and !pq.empty()){
    	top=pq.top();
    	pq.pop();
    	vis[k=top.first]=1;
    	l=top.second;
    	for (vector<P >::iterator it = v[k].begin() ; it != v[k].end(); ++it){
    		P node=*it;
    		if (!vis[node.first])
    		{
    			pq.push(make_pair(node.first,l+node.second));
    		}
    	}
    }

    // cout << vis[3] << endl;
    // for (i = 0; i < v[2].size(); ++i)
    // {
    // 	cout << v[2][i].first << " " << v[2][i].second << endl;
    // }

    printf("%d\n",top.first==n?top.second:-1 );


    return 0;
}