#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

int N,K,B,F[10101],mem[10001][101],dis[10001][101],parent[10001],G[10101];
vector<int> tr[10001];
bool vis[10101];

void dfs(int root){
    for (vector<int>::iterator i = tr[root].begin(); i != tr[root].end(); ++i)
    {
        if (!vis[*i])
        {
            vis[*i]=true;
            parent[*i]=root;
            G[*i]=G[root]+1;
            dfs(*i);
        }
    }
}

void dfs2(int root){
    dis[root][F[root]]=G[root];
    mem[root][F[root]]=root;
    for (vector<int>::iterator i = tr[root].begin(); i != tr[root].end(); ++i)
    {
        if (!vis[*i])
        {
            int v=*i;
            vis[v]=true;
            dfs2(v);
            // cerr << "here ?? " << root << endl;
            for (int i = 1; i <=K; ++i)
            {
                if (dis[v][i]>0){
                    // cerr << i<< ":"<<mem[v][i]<< " ";
                    if (dis[root][i]>=0){
                        if ( mem[root][i]>mem[v][i])
                            mem[root][i]=mem[v][i]; 
                    }
                    else{
                        dis[root][i]=G[root];
                        mem[root][i]=mem[v][i];
                        // cerr << mem[root][i] << endl;
                    }
                }
            }
            // cerr << endl;
        }
    }
}

void dfs3(int root){

    for (int i = 1; i <=K; ++i)
    {
        if (dis[root][i]<dis[parent[root]][i])
        {
            dis[root][i]=dis[parent[root]][i];
            mem[root][i]=mem[parent[root]][i];
        }
    }

    for (vector<int>::iterator i = tr[root].begin(); i != tr[root].end(); ++i)
    {
        if (!vis[*i])
        {
            int v=*i;
            vis[v]=true;
            dfs3(v);
        }
    }
}

int main(){
    int t,i,j,l,m,p,a,q;
    scanf("%d %d",&N,&K);
    scanf("%d",&B);
    for (i = 1; i < N; ++i)
    {
        scanf("%d %d",&p,&q);
        tr[p].push_back(q);
        tr[q].push_back(p);
    }
    for (i = 1; i <=N; ++i)
    {
        scanf("%d",&F[i]);
    }

    // cerr << "B " << B << endl;

    memset(vis,0,sizeof(vis));
    parent[B]=B;
    vis[B]=true;
    G[B]=0;
    dfs(B);

    for (i = 1; i<=N; ++i)
    {
        // memset(dis[i],0,sizeof(dis[i]));
        // memset(mem[i],B,sizeof(mem[i]));
        for (j = 0; j <=K; ++j)
        {
            dis[i][j]=-1;
            mem[i][j]=N+1;
        }
    }

    // for (i = 0; i <=N; ++i)
    // {
    //  for (j = 1; j<=K ; ++j)
    //  {
    //      cerr << mem[i][j] << " ";
    //  }cerr << endl;
    // }

    memset(vis,0,sizeof(vis));
    vis[B]=true;
    dfs2(B);

    // cerr << "here " << endl;
    // for (j = 1; j <=N; ++j)
    // {
       //  for (i = 1; i <=K; ++i)
       //  {
       //   cerr << mem[j][i] << ","<< dis[j][i] << "   ";
       //  }cerr << endl;
    // }


    memset(vis,0,sizeof(vis));
    vis[B]=true;
    dfs3(B);

    // cerr << "after 3 " << endl;
    // for (j = 1; j <=N; ++j)
    // {
       //  for (i = 1; i <=K; ++i)
       //  {
       //   cerr << mem[j][i] << ","<< dis[j][i] << "   ";
       //  }cerr << endl;
    // }

    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&p);
        printf("%d\n", mem[a][p]==N+1?-1:mem[a][p] );
    }
    return 0;
}