#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
typedef double d;
int n,k,m;

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int a[100],b[1001];
bool vis[100];
vector< vector<int> > v;

int dfs(int x){
	vis[x]=1;
	int res=1;
	for(vector<int>::iterator it=v[x].begin();it!=v[x].end();it++){
		if(!vis[*it])
		res+=dfs(*it);
	}
	return res;
}

set<int> se;
int main(){
	int t,i,j=0,te;int pro=0,x,y,z;
	//memset(vis,0,sizeof(vis));
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	bool di=0;
	for(i=1;i<1001;i++){
		if(b[i]>ceil((d)n/2.0))di=1;
	}
	cout<<((di==1)?"NO":"YES");
	return 0;
}