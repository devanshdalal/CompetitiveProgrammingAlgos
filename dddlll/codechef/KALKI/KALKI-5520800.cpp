#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<cassert>
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

struct point
{
	ll x,y;
};

struct edges
{
	int i,j;ll dist;
};

bool comp(edges a,edges b){
	return a.dist<b.dist;
}

point a[1001];
edges b[200000];
int parent[1001],csize[1001],n;

void init(){
	for (int i = 1; i <=n; ++i)
	{
		parent[i]=i;
		csize[i]=1;
	}
}

int find(int node){
	if(parent[node]!=node){
		return parent[node]=find(parent[node]);
	}
	return node;
}

bool unify(int t1,int t2){
	int p1=find(t1),p2=find(t2);
	if (p1==p2)return false;
	if (csize[p2]<csize[p1]){
		parent[p2]=p1;
		csize[p1]+=csize[p2];
	}else{
		parent[p1]=p2;
		csize[p2]+=csize[p1];
	}
	return true;
}

int main(){
    int t,i,j,k,l,m,p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        // cerr << n << " "<<n*(n-1)/2<< endl;
        for (i = 1; i<=n; ++i)
        {
            scanf("%lld %lld",&a[i].x,&a[i].y);
        }
        for (k=0,i=1; i<=n; ++i)
        {
            // cerr << k << endl;
        	for (j = i+1; j<=n; ++j)
        	{
                // k++;
        		b[k].i=i;
        		b[k].j=j;
        		b[k].dist=(a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y);
        		b[k].dist*=log(b[k].dist);
        		k++;
        		// cerr << (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y) << endl;
        	}
        }
        // cerr << k << endl;

        sort(b,b+k,comp);
        // for (i = 0; i <k; ++i)
        // {
        // 	cerr << b[i].i << ":" << b[i].j << ":" << b[i].dist << " 	";
        // }cerr << endl;
        init();
        // cerr << k << endl;
        for (i=j=0; j<n and i<k ; ++i)
        {
        	// cerr << "vdfv " << i << endl;
        	if (unify(b[i].i,b[i].j))
        	{
        		printf("%d %d\n",b[i].i,b[i].j);
        		j++;
                // if (j>n-1)
                // {
                //     cerr << "error " << endl;
                //     // break;
                // }
        	}

        }
        
    }
    return 0;
}