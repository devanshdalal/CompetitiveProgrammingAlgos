#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
typedef long long ll;
using namespace std;
int n,m;

//int getchar_unlocked()  {return getchar();}
inline void f(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}


int main(){
	int t,i,j,k,te;
	f(t);
	while(t--){
		f(n);f(m);
		int a[n][m],table[n][m];ll dist[n][m];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				f(a[i][j]);
				dist[i][j]=(ll)1e18;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				f(table[i][j]);
			}
		}
		for(i=0;i<m;i++){dist[0][i]=(ll)a[0][i];}
		for(i=0;i<n-1;i++){
			int mi,m_ind;
			for(j=0;j<m;j++){
				mi=a[i+1][j]-table[i][j]; mi=mi>0?mi:0;
				for(k=0;k<m;k++){
					dist[i+1][k]=min(dist[i+1][k],dist[i][j]+(k==j?mi:a[i][k]));
				}
			}
		}
		ll ans=dist[n-1][0];
		for(k=0;k<m;k++){
			if(dist[n-1][k]<ans)ans=dist[n-1][k];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*
#define BUF 4096
char ibuf[BUF];
int ipt = BUF; 
int readInt() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}
*/