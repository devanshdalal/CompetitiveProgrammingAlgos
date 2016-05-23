#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<ctime>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

vector<int> g[1025];
bool vis[1025];
int degree[]={0,1,3,6,10,15,21,28,36,45,55},dis[1025],far[1025],n,rig[1025][7],last[10],st[10];

int dfs(int root){
	int count=1;
	for (vector<int>::iterator it = g[root].begin(); it != g[root].end(); ++it)
	{
		if (!vis[*it])
		{
			vis[*it]=true;
			count+=dfs(*it);
		}
	}
	return count;
}

int bfs(int root){
	memset(vis,0,sizeof(vis));
	memset(last,0,sizeof(last));
	queue<int> q;
	q.push(root);
	dis[root]=0;
	vis[root]=1;
	int top;
	while(!q.empty()){
		top=q.front();
		q.pop();
		for (vector<int>::iterator i = g[top].begin(); i != g[top].end(); ++i){
			if (!vis[*i]){
				vis[*i]=1;
				q.push(*i);
				dis[*i]=1+dis[top];
			}
		}
	}
	for (int i = 1; i <=n; ++i){
		if(dis[i]==dis[top])far[i]++;
		rig[i][dis[i]]++;
		last[dis[i]]++;
	}
	return dis[top];
}

vector<vector<int> >  genM(int n){
	vector< vector<int> > ans;
	if(n<2)return ans;
	ans.resize(2);
	ans[0].push_back(0); ans[0].push_back(1);
	ans[1].push_back(1); ans[1].push_back(0);
	for (int i = 2; i<n; i*=2)
	{
		for (int j= i; j <2*i; ++j)
		{
			vector<int> temp;
			for (int k= 0; k <i ; ++k)
			{
				if(k==j-i){
					temp.push_back(1);
					ans[j-i].push_back(1);
				}else{
					temp.push_back(0);
					ans[j-i].push_back(0);
				}
			}
			for (int k = i; k<2*i; ++k)
			{
				temp.push_back(ans[j-i][k-i]);
			}
			ans.push_back(temp);
		}
	}
	vector< vector<int>  > te;
	for (int i = 0; i < n ; ++i)
	{
		vector<int> nnn(n,0);
		te.push_back(nnn);
		for (int j = 0; j < n ; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(k!=i and ans[i][j] and ans[j][k])te[i][k]=1;
			}
		}
	}
	queue<int> qu;
	memset(vis,0,sizeof(vis));
	qu.push(1);
	map<int,int> mymap;
	int id=1;
	mymap[1]=id++;
	vector< pair<int,int> > adj;
	while(!qu.empty()){
		int top=qu.front(); qu.pop();
		vis[top]=1;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i] and te[top][i])
			{
				mymap[i]=id++;
				adj.pb(make_pair(mymap[top],mymap[i]));
				qu.push(i);
			}
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j< n; ++j)
	// 	{
	// 		cerr << te[i][j] << " " ;
	// 	}cerr << endl;
	// }
	// cerr << "-----------" << endl;
	// cout << "U" << endl;
	cout << n << endl;
	cout << adj.size() << endl;
	for (int i = 0; i < adj.size(); ++i)
	{
		cout << adj[i].first << " "<< adj[i].second  << endl;
	}
	return ans;
}

int main(){
    int t,i,j,k,l,m,p,q;
    scanf("%d",&t);
    // genM(t);
    // exit(0);
    while(t--){
        scanf("%d %d",&n,&m);
        for (i = 1; i <=n; ++i){g[i].clear();}
        for (i = 1; i <=m; ++i){
        	scanf("%d %d",&p,&q);
        	g[p].push_back(q);
        	g[q].push_back(p);
        }
        p=log2(n+1);
        if((1<<p)!=n){
        	printf("NO\n");
        	continue;
        }
        memset(vis,0,sizeof(vis));
		vis[1]=1;
        if(dfs(1)!=n){
        	printf("NO\n");
        	continue;
        }
        for (i = 1; i <=n; ++i){
        	if (g[i].size()!=degree[p]){
        		break;
        	}
        }
        if(i!=n+1){
        	// cerr << "this" << endl;
        	printf("NO\n");
        	continue;
        }

		memset(far,0,sizeof(far));
		memset(rig,0,sizeof(rig));
        q=bfs(n);
        // cerr << "q " << q << " " << far[n] << endl;
        memcpy(st,last,sizeof(last));
        // for (i = 1; i <=n; ++i)
        // {
        // 	cerr << "distance " << dis[i] << endl;
        // }
        // for (i = 0; i <7; ++i)
        // {
        // 	cerr << st[i] << " " ;
        // }cerr << endl;
        for (i = 1; i <n; ++i){
        	// cerr << " " <<  bfs(i) << endl;
        	if (bfs(i)!=q){
        		break;
        	}
        	// for (j = 0; j<7; ++j){
        	// 	if(st[j]!=last[j])break;
        	// }
        	// if(j!=7)break;
        }
        // cerr << q << endl;
        for (j = 1; j<n; ++j){
        	// cerr << far[j] << " " ;
        	if (far[j]!=far[n] or far[n]!=(p&1?1:p+1)){// or rig[j][1]!=rig[n][1] or rig[j][2]!=rig[n][2] or rig[j][3]!=rig[n][3] or rig[j][4]!=rig[n][4] or rig[j][5]!=rig[n][5] or rig[j][6]!=rig[n][6]){
        		break;
        	}
        }
        // cerr << endl;
        if((i!=n) or (q!=(1+p)/2) or (j!=n) ){
        	printf("NO\n");
        	continue;
        }
        if(n==2 ){
        	// printf("NO\n");
        	// continue;
        	// printf(solv(rgraphA,rgraphB)?"YES\n":"NO\n");
        }else{
        }

        printf("YES\n");
    }
    return 0;
}