#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

int n,m;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

const int maxnodes = 5000;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, cap};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

int main() {
    // int n = 3;
    // nodes = n;

    // int capacity[][3] = { { 0, 3, 2 }, { 0, 0, 2 }, { 0, 0, 0 } };
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         if (capacity[i][j] != 0)
    //             addEdge(i, j, capacity[i][j]);
    // cout << (4 == maxFlow(0, 2)) << endl;

	int p;
	io;
	cin >> n ;
	nodes=n+2;
	for (int i = 1; i <=n; ++i)
	{
		cin >> p;
		if (p>0)addEdge(0,i,p);
	}
	for (int i = 1; i <=n; ++i)
	{
		cin >> p;
		if (p>0)addEdge(i,n+1,p);
	}
	for (int i = 1; i <=n; i++)
        for (int j =1; j <=n; j++){
        	cin >> p;
        	if(i<=j)continue;
        	if (p>0)addEdge(i,j,p);
        }
    cout << maxFlow(0,n+1) << endl;
}