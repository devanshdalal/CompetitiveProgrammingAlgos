#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

// const int MAXN1 = 50000;
// const int MAXN2 = 50000;
// const int MAXM = 150000;

// int n1, n2, edges, last[MAXN1], mprev[MAXM], head[MAXM];
// int matching[MAXN2], dist[MAXN1], Q[MAXN1];
// bool used[MAXN1], vis[MAXN1];

// void init(int _n1, int _n2) {
//     n1 = _n1;
//     n2 = _n2;
//     edges = 0;
//     fill(last, last + n1, -1);
// }

// void addEdge(int u, int v) {
//     head[edges] = v;
//     mprev[edges] = last[u];
//     last[u] = edges++;
// }

// void bfs() {
//     fill(dist, dist + n1, -1);
//     int sizeQ = 0;
//     for (int u = 0; u < n1; ++u) {
//         if (!used[u]) {
//             Q[sizeQ++] = u;
//             dist[u] = 0;
//         }
//     }
//     for (int i = 0; i < sizeQ; i++) {
//         int u1 = Q[i];
//         for (int e = last[u1]; e >= 0; e = mprev[e]) {
//             int u2 = matching[head[e]];
//             if (u2 >= 0 && dist[u2] < 0) {
//                 dist[u2] = dist[u1] + 1;
//                 Q[sizeQ++] = u2;
//             }
//         }
//     }
// }

// bool dfs(int u1) {
//     vis[u1] = true;
//     for (int e = last[u1]; e >= 0; e = mprev[e]) {
//         int v = head[e];
//         int u2 = matching[v];
//         if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
//             matching[v] = u1;
//             used[u1] = true;
//             return true;
//         }
//     }
//     return false;
// }

// int maxMatching() {
//     fill(used, used + n1, false);
//     fill(matching, matching + n2, -1);
//     for (int res = 0;;) {
//         bfs();
//         fill(vis, vis + n1, false);
//         int f = 0;
//         for (int u = 0; u < n1; ++u)
//             if (!used[u] && dfs(u))
//                 ++f;
//         if (!f)
//             return res;
//         res += f;
//     }
// }

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
	int t,p,n,m,q;
	io;

	cin >> n >> m ;
	while(n!=0 or m!=0){
		nodes=n+2;
		for (int i = 0; i < nodes; ++i)
		{
			g[i].clear();
		}
		for (int i = 1; i <=n; ++i)
		{
			cin >> p;
			if(p==0)addEdge(0,i,1);
			else addEdge(i,n+1,1);
		}
		for (int i = 0; i < m; ++i)
		{
			cin  >> p >> q;	
			addEdge(p,q,1);
		}
		cout << maxFlow(0,n+1) << "\n";

	    // cerr << "------------" << endl;
		cin >> n >> m ;
	}
}