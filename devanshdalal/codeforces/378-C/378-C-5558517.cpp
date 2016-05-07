#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int r,c,k;
char a[501][501];
bool visited[501][501];

int safe(int x,int y){
	return (x<r && x>=0 && y<c && y>=0) && visited[x][y]==false && a[x][y]=='.';
}

void dfs(int x,int y){
	visited[x][y]=true;
	//~ if(a[x][y]=='#' or a[x][y]=='X'){
		//~ return ;
	//~ }
	//~ else{
		if(safe(x-1,y)) dfs(x-1,y);  
		if(safe(x,y-1)) dfs(x,y-1); 
		if(safe(x+1,y)) dfs(x+1,y); 
		if(safe(x,y+1)) dfs(x,y+1);
	//~ }
	if(k>0){
		a[x][y]='X';
		k--;
	}
}

int main(){
	int t,i,j,xx,yy;
	scanf("%d%d%d",&r,&c,&k);
	for(i=0;i<r;i++){
		scanf("%s",a[i]);
	}
	bool fo=0;
	for(i=0;i<r;i++) for(j=0;j<c;j++) {visited[i][j]=false; if(!fo && a[i][j]=='.'){ xx=i; yy=j; fo=1; }  }
	dfs(xx,yy);
	for(i=0;i<r;i++){
		printf("%s\n",a[i]);
	}
	return 0;
}