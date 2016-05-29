#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;
int t,j,i;
ifstream infile;
int N=80;
bool visit[100][100]={{0}};
int dist[100][100];
int inheap[100][100];
int a[100][100];

struct node{
	int x,y;
};

node heap[250001]; int last=1;

void swap(int i,int j){
	int tex=heap[i].x; heap[i].x=heap[j].x; heap[j].x=tex;
	int tey=heap[i].y; heap[i].y=heap[j].y; heap[j].y=tey;
	inheap[heap[i].x][heap[i].y]=i;
	inheap[heap[j].x][heap[j].y]=j;
}

void upheap(int i){
	int j=i/2;
	while(j){
		if(dist[heap[j].x][heap[j].y] > dist[heap[i].x][heap[i].y]) { swap(i,j); i=j; j=i/2;  }
		else break;
	}
}
void add(int xx,int yy,int dis){
	inheap[xx][yy]=last;
	heap[last].x=xx; heap[last].y=yy; dist[xx][yy]=dis;
	upheap(last++);
}
void downheap(int i){
	int j=2*i,k=j+1;
	while(j<last){
		//cout<<i<<endl;
		if(dist[heap[j].x][heap[j].y] < dist[heap[i].x][heap[i].y] && dist[heap[j].x][heap[j].y] <= dist[heap[k].x][heap[k].y]) {swap(i,j);  i=j;}
		else if(k<last && dist[heap[k].x][heap[k].y] < dist[heap[i].x][heap[i].y] && dist[heap[j].x][heap[j].y] >= dist[heap[k].x][heap[k].y]) {swap(i,k); i=k;}
		else break;
		j=2*i;k=j+1;
	}
}

node del(){
	node ta=heap[1];
	inheap[ta.x][ta.y]=-1;
	visit[ta.x][ta.y]=true;
	heap[1]=heap[--last];
	downheap(1);
	return ta;
}

inline void Read(int &x) {
	register char c;
	while (infile.good()){
		c= (char) infile.get();
		if(c>47 && c<58) break;
	}
	x = 0;
	for(; c>47 && c<58 ; c = (char) infile.get()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main(){
	int num;
	infile.open("matrix.txt");
	if(infile.fail())
	{
	cerr << "Cannot open input file numbers.dat \n";
	abort();
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Read(a[i][j]);
			//printf("%d\t",a[i][j]);
		}
		//cout<<endl;
	}
	for(i=0;i<N;i++){ for(j=0;j<N;j++) {visit[i][j]=false;  inheap[i][j]=-1; dist[i][j]=10000000;}}
	add(0,0,a[0][0]);
	int xi,yj;
	node jj=del();
	//cout<< jj.x<< ", " <<jj.y<<endl;
	while(jj.x!=N-1 || jj.y!=N-1){
		//printf("%d\t %d\t%d\n",jj.x,jj.y,dist[jj.x][jj.y]);
		xi=jj.x; yj=jj.y;
		int ci[4]={xi+1,xi};int ch[4]={yj,yj+1};
		//if(a[xi][yj]==342) cout<<a[xi-1][yj]<<"and"<<visit[xi-1][yj]<<"and" << inheap[xi-1][yj]<<endl;
		for(int m=0;m<4;m++){
			if(ch[m]>=N or ch[m]<0) continue;
			if(visit[ci[m]][ch[m]]==false && inheap[ci[m]][ch[m]]==-1) add(ci[m],ch[m],dist[xi][yj]+a[ci[m]][ch[m]]);
			else if(inheap[ci[m]][ch[m]]!=-1 and dist[xi][yj]+a[ci[m]][ch[m]]<dist[ci[m]][ch[m]]){ dist[ci[m]][ch[m]]=dist[xi][yj]+a[ci[m]][ch[m]]; upheap(inheap[ci[m]][ch[m]]);}
		}
		//for(i=1;i<20;i++){   cout<< a[heap[i].x][heap[i].y] <<" "; }cout<<endl;
		jj=del();
	}
	printf("\n%d\t%d\t%d\n",jj.x,jj.y,dist[jj.x][jj.y]);
	return 0;
}
