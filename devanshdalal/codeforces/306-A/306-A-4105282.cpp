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

int main(){
	int i,j;
	cin>>n>>m;
	k=n/m;
	int arr[m];
	for(i=0;i<m;i++)arr[i]=k;
	for(k=n%m,i=0;i<m;i++,k-=(k>0)?1:0){
		cout<<(arr[i]+(k>0?1:0))<<" " ;
	}
	
	
}

/*
const int MAXN=100010;
ll l[MAXN],r[MAXN],val[MAXN],a[MAXN],con[MAXN], tr[MAXN];

int main(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(l));
	memset(val,0,sizeof(l));
	memset(a,0,sizeof(l));
	memset(con,0,sizeof(l));
	memset(tr,0,sizeof(l));
	int i,j,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>val[i];
	}
	for(i=1;i<=k;i++){
		cin>>x>>y;
		con[x]++;
		con[y+1]--;
	}
	for(i=1;i<=m;i++){
		con[i]+=con[i-1];
		tr[l[i]]+=con[i]*val[i];
		tr[r[i]+1]-=con[i]*val[i];
	}
	for(i=1;i<=n;i++){
		tr[i]+=tr[i-1];
		cout<<tr[i]+a[i]<<" "; 
	}
	return 0;	
}*/