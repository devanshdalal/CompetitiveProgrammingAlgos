#include<cstring>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<queue>
#include<bitset>
#include<cassert>
#define dbg(x) {cerr<<#x << " = " << x << endl;}
typedef long long ll;
typedef long double ld;
using namespace std;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = ll(inf) * ll(inf);
#define pb push_back

vector<int> pr;
const int maxp = 50000;
bool prime[maxp];
int fprime[maxp];
void get_primes(){
	memset(prime, true, sizeof prime);
	prime[1]=prime[0]= false;
	for(int i = 2; i*i<=maxp; ++i)
		if(prime[i])
			for(int j = i*i; j < maxp; j += i)
				if(prime[j]){
					prime[j] = false;
					fprime[j] = i;
				}
	for(int i = 0; i < maxp; ++i)
	 	if(prime[i])pr.pb(i);
}

vector<int> factor(int num){
	vector<int> pr1;
	while(num > 1){
		int r = prime[num] ? num : fprime[num];
		pr1.pb(r);
		while(num % r == 0)
			num /= r;
	}
	return pr1;
}

vector<int> factor_big(int num){
	if(num < maxp)return factor(num);
	vector<int> res;
	for(int i = 0; i < pr.size() && pr[i] * pr[i] <= num; ++i){
		int prz = pr[i];
		if(num % prz == 0){
			res.pb(prz);
			while(num % prz == 0)num /= prz;
		}
	}
	if(num > 1)res.pb(num);
	return res;
}

int gcdI(int a,int b){
	while (b) {
		a %= b;
		swap(b, a);
	}
	return a;
}

struct Dinitz_t
{
	struct edge_t
	{
		int v, f;
		edge_t() {}
		edge_t(int v, int f) : v(v), f(f) {}
	};
	vector< vector<int> > g;
	vector< edge_t > edges;
	vector<int> last;
	vector<int> d;
	
	void init(int n){
		edges.clear();
		g.clear();
		g.resize(n);
	}

	int add_edge(int u, int v, int cap){
		edges.push_back(edge_t(v, cap));
		edges.push_back(edge_t(u, 0));
		g[v].push_back(edges.size() - 1);
		g[u].push_back(edges.size() - 2);
		return edges.size() - 2;
	}

	bool bfs(int s, int t){
		d.assign(g.size(), -1);
		d[s] = 0;
		queue<int> q;
		q.push(s);
		while(q.size()){
			int u = q.front(); q.pop();
			for(int i = 0; i < g[u].size(); ++i){
				edge_t &e = edges[g[u][i]];
				if(e.f > 0 && d[e.v] == -1){
					d[e.v] = d[u] + 1;
					q.push(e.v);					
				}
			}
		}
		return d[t] != -1;
	}

	int dfs(int s, int t, int u, int my1){
		if(u == t)return my1;
		for(int &i = last[u]; i < g[u].size(); ++i){
			int id = g[u][i];
			edge_t &e = edges[id];
			if(e.f > 0 && d[e.v] == d[u] + 1){
				int r = dfs(s, t, e.v, min(my1, e.f));
				if(r > 0){
					e.f -= r;
					edges[id ^ 1].f += r;
					return r;
				}
			}
		}
		d[u] = -1;
		return 0;
	}

	int find(int s, int t){
		int flow = 0;
		while(bfs(s, t)){
			last.assign(g.size(), 0);
			while(int add = dfs(s, t, s, inf))flow += add;
		}
		return flow;
	}
};

vector<int> a, b;
int n,m;
Dinitz_t dinitz;

void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
}

char buf[11];int ix; 
inline void writeInt(int x) {
     ix = 10;
     buf[10] = '\n';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[++ix] != '\0');
}

int main(){
	int t;
	ios_base::sync_with_stdio(false);
	// cin>> t;
	r(t);
	get_primes();
	while(t--){
		int partial=0;
		int precal[maxp],lmt=maxp/1.85;
		for (int i = 0; i < lmt; ++i)precal[i]=0;
		int ar[400],br[400],k=0,l=0;
		// cin>> n;
		r(n);
		a.clear();
		b.clear();
		// for (int i = 0; i < n; ++i)cin >> ar[i];
		for (int i = 0; i < n; ++i)r(ar[i]);
		// for (int i = 0; i < n; ++i)cin >> br[i];
		for (int i = 0; i < n; ++i)r(br[i]);
		for (int i=0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				int gc=gcdI(ar[i],br[j]);
				if(gc==1 or ar[i]==br[j] )continue;
				bool temp=ar[i]>br[j];
				if (gc<lmt and prime[gc]){
					if (temp ){
						if (precal[gc]<0)partial++;
						precal[gc]++;
					}else{
						if (precal[gc]>0)partial++;
						precal[gc]--;
					}
				}else{
					if(temp){
						a.push_back(gc);
						k++;
					}
					else {
						b.push_back(gc);
						l++;
					}
				}
			}
		}

		for (int i=1; i<lmt ; i++ ){
			while (precal[i]>0){
				a.push_back(i);
				k++;
				precal[i]--;
			}
			while (precal[i]<0){
				b.push_back(i);
				l++;
				precal[i]++;
			}
		}
		n=k;
		m=l;

		int cap1[n],cap2[m];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());	
		vector<int> apr,bpr;
		for (int i = k=0,j; i < n; i=j){
			j=i+1;
			for ( ; j< n and a[j]==a[i]; ++j);
			apr.push_back(a[i]);
			cap1[k++]=j-i;
		}
		for (int i = l=0,j; i < m; i=j){
			j=i+1;
			for ( ; j< n and b[j]==b[i]; ++j);
			bpr.push_back(b[i]);
			cap2[l++]=j-i;
		}
		n=k;
		m=l;
		swap(b,bpr);
		swap(a,apr);
		vector<int> primes;// = pr;
		vector< vector<int> > pa(n), pb(m);
		lmt=100000;
		bitset<100000> bitp;
		for(int z = 0; z < 2; ++z){
			for(int num = 0; num < n; ++num){
				pa[num] = factor_big(a[num]);
				int sije=pa[num].size();
				for (int i = 0; i < sije; ++i){
					if (pa[num][i]<lmt){
						bitp[pa[num][i]]=1;
					}else{
						primes.push_back(pa[num][i]);
					}
				}
			}
			swap(pa, pb);
			swap(a, b);
			swap(n, m);
		}
		for (int i = 0; i < lmt; ++i)
			if (bitp[i]==1)
				primes.push_back(i);

		sort(primes.begin(), primes.end());
		primes.erase(unique(primes.begin(), primes.end()), primes.end());
		int N = m+ n + primes.size() + 2;
		dinitz.init(N);
		int source = N - 2;
		int tink = N - 1;
		int pr_start = n;
		int a_start = 0;
		int b_start = n + primes.size();
		for(int i = 0; i < n; ++i)dinitz.add_edge(source, a_start + i, cap1[i]);
		for(int i = 0; i < m; ++i)dinitz.add_edge(b_start + i, tink, cap2[i]);		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < pa[i].size(); ++j){
				int pos = lower_bound(primes.begin(), primes.end(), pa[i][j]) - primes.begin();
				dinitz.add_edge(a_start + i, pr_start + pos, cap1[i]);
			}
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < pb[i].size(); ++j){
				int pos = lower_bound(primes.begin(), primes.end(), pb[i][j]) - primes.begin();
				dinitz.add_edge(pr_start + pos, b_start + i, cap2[i]);
			}
		ll ans = dinitz.find(source, tink);
		cout << partial+ ans << endl;
	}
	return 0;
}