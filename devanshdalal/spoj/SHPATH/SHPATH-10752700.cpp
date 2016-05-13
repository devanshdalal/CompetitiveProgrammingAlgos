#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include <climits>
#include<map>
#include<cmath>
#define DD ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int maxnodes = 10001;
const int maxedges = 500000;

// graph
int edges;
int last[maxnodes], head[maxedges], previous[maxedges], len[maxedges];
int prio[maxnodes], pred[maxnodes];

void graphClear() {
    fill(last, last + maxnodes, -1);
    edges = 0;
}

void addEdge(int u, int v, int length) {
    head[edges] = v;
    len[edges] = length;
    previous[edges] = last[u];
    last[u] = edges++;
}

// heap
int h[maxnodes];
int pos2Id[maxnodes];
int id2Pos[maxnodes];
int hsize;

void hswap(int i, int j) {
    swap(h[i], h[j]);
    swap(pos2Id[i], pos2Id[j]);
    swap(id2Pos[pos2Id[i]], id2Pos[pos2Id[j]]);
}

void moveUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) >> 1;
        if (h[pos] >= h[parent]) {
            break;
        }
        hswap(pos, parent);
        pos = parent;
    }
}

void add(int id, int prio) {
    h[hsize] = prio;
    pos2Id[hsize] = id;
    id2Pos[id] = hsize;
    moveUp(hsize++);
}

void increasePriority(int id, int prio) {
    int pos = id2Pos[id];
    h[pos] = prio;
    moveUp(pos);
}

void moveDown(int pos) {
    while (pos < (hsize >> 1)) {
        int child = 2 * pos + 1;
        if (child + 1 < hsize && h[child + 1] < h[child]) {
            ++child;
        }
        if (h[pos] <= h[child]) {
            break;
        }
        hswap(pos, child);
        pos = child;
    }
}

int removeMin() {
    int res = pos2Id[0];
    int lastNode = h[--hsize];
    if (hsize > 0) {
        h[0] = lastNode;
        int id = pos2Id[hsize];
        id2Pos[id] = 0;
        pos2Id[0] = id;
        moveDown(0);
    }
    return res;
}

void dijkstra(int s) {
    fill(pred, pred + maxnodes, -1);
    fill(prio, prio + maxnodes, INT_MAX);
    prio[s] = 0;
    hsize = 0;
    add(s, 0);

    while (hsize) {
        int u = removeMin();
        for (int e = last[u]; e >= 0; e = previous[e]) {
            int v = head[e];
            int nprio = prio[u] + len[e];
            if (prio[v] > nprio) {
                if (prio[v] == INT_MAX)
                    add(v, nprio);
                else
                    increasePriority(v, nprio);
                prio[v] = nprio;
                pred[v] = u;
            }
        }
    }
}

void PartialDijkstra(int s,int tar) {
    fill(pred, pred + maxnodes, -1);
    fill(prio, prio + maxnodes, INT_MAX);
    prio[s] = 0;
    hsize = 0;
    add(s, 0);
	int u=0;
    while (hsize and u!=tar) {
        u = removeMin();
        for (int e = last[u]; e >= 0; e = previous[e]) {
            int v = head[e];
            int nprio = prio[u] + len[e];
            if (prio[v] > nprio) {
                if (prio[v] == INT_MAX)
                    add(v, nprio);
                else
                    increasePriority(v, nprio);
                prio[v] = nprio;
                pred[v] = u;
            }
        }
    }
}


int main(){
	DD;
	int t,i,j,k,l,x,y,z,n,m,u,q;
	cin>> t;
	while(t--){
		map<string,int> ind;
		graphClear();
		cin>>n;
		for(i=1;i<=n;i++){
			string city("");
			cin>>city;
			ind[city]=i;
			cin>>x;
			for(;x--;){
				cin>>y>>z;
				addEdge(i, y, z);
			}
		}
		cin>>q;
		for(i=0;i<q;i++){
			string te(""),tr("");
			cin>>te>>tr;
			x=ind[te];
			y=ind[tr];
			PartialDijkstra(x,y);
			cout<<prio[y]<<endl;
		}
	}
	return 0;
}
