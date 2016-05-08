#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
int n,k,m;char a[2000009],b[2000009];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int r,c;char g[1001][1001];int cou[1001][1001];bool vis[1001][1001];


struct pa{
	int x,y;
};

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool safe(int x,int y){
	return x<r && y<c && x>=0 && y>=0 && !vis[x][y] && g[x][y]!='T';
}

int main(){
	int t,i,j,x=0,y=0;bool di=0;int sx,sy,max,va;
	scanf("%d%d\n",&r,&c);
	pa tem;
	for(i=0;i<r;i++){
		scanf("%s",g[i]);
		for(j=0;j<c;j++){
			cou[i][j]=1e9;
			if(g[i][j]=='E')tem.x=i,tem.y=j;
			else if(g[i][j]=='S')sx=i,sy=j;
		}
	}
	cou[tem.x][tem.y]=1;
	queue<pa> Q;
	Q.push(tem);
	while(!Q.empty()){
		pa ls=Q.front();Q.pop();
		for(i=0;i<4;i++){
			x=ls.x+dx[i];
			y=ls.y+dy[i];
			if(safe(x,y)){
				cou[x][y]=1+cou[ls.x][ls.y];
				tem.x=x,tem.y=y;
				Q.push(tem);
				vis[x][y]=true;
			}
		}
	}
	//cout<<sx<<" "<<sy<<endl;
	max=cou[sx][sy];
	//cout<<max<<endl;
	int  ans=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			va=g[i][j]-'0';
			if(va<=9 && va>=0 && cou[i][j]<=max){
				ans+=va;
			}
		}
	}
	cout<<ans;
	return 0;
}