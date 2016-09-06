#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
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

int n,m,k;
vector<int> tr[101];
int X[101][101],Y[101][101];
bool notRoot[101];

int main(){
    int t,i,j,l,p,q;
    scanf("%d %d %d",&n,&m,&k);
    memset(notRoot,0,sizeof(notRoot));
    for (i = 1; i <=n; ++i){
    	for (j = 1; j <=m; ++j){
    		scanf("%d",&X[i][j]);
    	}
    }
    
    for (i = 1; i <=k; ++i)
    {
	    scanf("%d %d",&p,&q);
	    tr[p].pb(q);
	    notRoot[q]=true;
    }

    ll ans=0;
	for (l=1; l<=n ; ++l)
	{
		if (tr[l].size()==0){
			Y[l][m]=X[l][m]==-1?-mod:X[l][m];
		}else{
			Y[l][m]=-mod;
		}
	}
	for (j = m-1; j>0; --j){
		for (l=1; l<=n ; ++l){
    		if(X[l][j]==-1){
    			Y[l][j]=Y[l][j+1];
    			continue;
    		}
    		q=0;
    		for (vector<int>::iterator it = tr[l].begin(); it != tr[l].end(); ++it){
    			if (Y[*it][j+1]<0)
    			{
    				q=-6734432;
    				break;
    			}
    			q+=Y[*it][j+1];
    		}
    		if (q==-6734432)Y[l][j]=Y[l][j+1];
    		else Y[l][j]=max(Y[l][j+1],X[l][j]+q);
    	}	
	}

	for (i = 1; i <=n; ++i){
		if (!notRoot[i]){
			ans+=Y[i][1];
			// cerr << i << " " << Y[i][1] << endl;
		}
	}

	// for (i =1; i <=n; ++i)
	// {
	// 	for (j= 1; j <=m; ++j)
	// 	{
	// 		cerr << Y[i][j] << " ";
	// 	}cerr << endl;
	// }

    printf("%0.2lf\n", dbl(ans)/dbl(n));
    return 0;
}