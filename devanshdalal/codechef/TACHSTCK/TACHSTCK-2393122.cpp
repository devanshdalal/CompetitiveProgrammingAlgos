#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
#define MAXN 100100
typedef double d;
int n,D,a[MAXN];

int main(){
	int i,j,cp=0;
	cin>>n>>D;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n-1;){
		if(a[i+1]-a[i]<=D)cp++,i+=2;
		else i++;
	}
	cout<<cp;
	return 0;
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