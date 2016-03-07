#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
#define ma 100100
int ans[ma],n;
bool visited[ma];
vector<vector<int> > graph;

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}
 
 
void dfs(int v){
	visited[v]=true;
	for(vector<int>::iterator it=graph[v].begin();it!=graph[v].end();++it){
		if(!visited[*it]){
			ans[*it]=v;
			dfs(*it);
		}
	}
}
 
int main(){
	int t,i,p,q,k;
	r(t);
	while(t--){
		r(n);r(p);r(q);
		memset(visited,0,sizeof(visited));
		memset(ans,0,sizeof(visited));
		graph.resize(n+1);
		for(i=1;i<=n;i++)graph[i].clear();
		
		for(i=1;i<=n;i++){
			if(i==p)continue;
			r(k);
			graph[k].push_back(i);
			graph[i].push_back(k);
		}
		dfs(q);
		for(i=1;i<=n;i++){
			if(i==q)continue;
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}