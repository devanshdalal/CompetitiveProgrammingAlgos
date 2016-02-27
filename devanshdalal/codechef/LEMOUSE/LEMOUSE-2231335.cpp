#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>

using namespace std;
int n,m;
bool visit[101][101];
int dist[101][101];
int inheap[101][101];
int a[101][101];

struct node{
	int x,y;bool up,left;
};

node heap[2000]; int last=1;
bool xs;
void swap(int i,int j){
	xs=heap[i].up;  heap[i].up=heap[j].up; heap[j].up=xs;
	xs=heap[i].left;  heap[i].left=heap[j].left; heap[j].left=xs;
	int tex=heap[i].x; heap[i].x=heap[j].x; heap[j].x=tex;
	int tey=heap[i].y; heap[i].y=heap[j].y; heap[j].y=tey;
	inheap[heap[i].x][heap[i].y]=i;
	inheap[heap[j].x][heap[j].y]=j;
}

bool compare(int il,int jl){
	if(dist[heap[jl].x][heap[jl].y] > dist[heap[il].x][heap[il].y]) return true;
	else if(dist[heap[jl].x][heap[jl].y] == dist[heap[il].x][heap[il].y] and heap[il].x+heap[il].y <= heap[jl].x+heap[jl].y) return true;
	else return false;
}

void upheap(int i){
	int j=i/2;
	while(j){
		if(compare(i,j)) { swap(i,j); i=j; j=i/2;  }
		else break;
	}
}
void add(int xx,int yy,int dis,bool tr,bool dow){
	inheap[xx][yy]=last;
	heap[last].x=xx; heap[last].y=yy; dist[xx][yy]=dis; heap[last].up=tr;heap[last].left=dow;
	upheap(last++);
}
void downheap(int i){
	int j=2*i,k=j+1;
	while(j<last){
		//cout<<"downheap:" << i << ","<< j<<"," << k <<","<<  compare(2,3)<<" " << compare(3,2) <<endl;
		if(compare(j,i) && compare(j,k) ) { swap(i,j);  i=j;}
		else if(k<last && compare(k,i) && compare(k,j) ) { swap(i,k); i=k;}
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

int get1(int fc,int hb){
	int cou=0;
	if( fc!=n-1 and a[fc+1][hb]==1) { cou++; }
	if( hb>0 and a[fc][hb-1]==1 ) { cou++; }
	if( hb!=m-1 and a[fc][hb+1]==1 ) { cou++; }
	return cou;
}

int get2(int fc,int hb){
	int cou=0;
	if( fc!=n-1 and a[fc+1][hb]==1) { cou++; }
	if( hb!=m-1 and a[fc][hb+1]==1 ) { cou++; }
	return cou;
}

int get3(int fc,int hb){
	int cou=0;
	if( fc!=n-1 and a[fc+1][hb]==1) { cou++; }
	if( fc>0 and a[fc-1][hb]==1) { cou++; }
	if( hb!=m-1 and a[fc][hb+1]==1 ) { cou++; }
	return cou;
}

//int getchar_unlocked()  {return getchar();}
inline void Read(int &x) {
	register int c= getchar_unlocked();
	for(; ((c<48 || c>50)); c = getchar_unlocked());
	x=c-'0';
}

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n); scanf("%d",&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				Read(a[i][j]);
				//printf("%d\t",a[i][j]);
			}
			//cout<<endl;
		}
		last=1;
		for(i=0;i<n;i++){ for(j=0;j<m;j++) {visit[i][j]=false;  inheap[i][j]=-1; dist[i][j]=10000000;  } }
		add(0,0,a[0][0]+get2(0,0),true,true);
		int xi,yj,di;
		node jj=del();
		while(jj.x!=n-1 || jj.y!=m-1){
			xi=jj.x; yj=jj.y;
			if(xi!=n-1 and visit[xi+1][yj]==false && inheap[xi+1][yj]==-1){           //coice 1
				if(jj.left==false) { add(xi+1,yj,dist[xi][yj]+ get1(xi+1,yj),true,false);  }
				else add(xi+1,yj,dist[xi][yj]+ get2(xi+1,yj),true,false);
			}
			else if(xi!=n-1 and inheap[xi+1][yj]!=-1){
				if(jj.left==false) di=get1(xi+1,yj);
				else di=get2(xi+1,yj); 
				if(dist[xi+1][yj]>di+dist[xi][yj]) { 
						dist[xi+1][yj]=di+dist[xi][yj];heap[inheap[xi+1][yj]].up=true;heap[inheap[xi+1][yj]].left=false; upheap(inheap[xi+1][yj]); }
				else if(dist[xi+1][yj]==di+dist[xi][yj]) {heap[inheap[xi+1][yj]].up=true; } 
			}
			
			if(yj!=m-1 and visit[xi][yj+1]==false && inheap[xi][yj+1]==-1){            //coice 2
				if(jj.up==false) { add(xi,yj+1,dist[xi][yj]+ get3(xi,yj+1),false,true );  }
				else add(xi,yj+1,dist[xi][yj]+ get2(xi,yj+1),false,true);
			}
			else if(yj!=m-1 and inheap[xi][yj+1]!=-1){
				if(jj.up==false) di=get3(xi,yj+1);
				else di=get2(xi,yj+1);
				if(dist[xi][yj+1]>dist[xi][yj]+di) {dist[xi][yj+1]=dist[xi][yj]+di;heap[inheap[xi][yj+1]].up=false;heap[inheap[xi][yj+1]].left=true; upheap(inheap[xi][yj+1]);  }
				else if(dist[xi][yj+1]==dist[xi][yj]+di) {heap[inheap[xi][yj+1]].left=true; }  
			}
			//for(i=1;i<last;i++) { cout<<heap[i].x<< ","<<heap[i].y<<","<<dist[heap[i].x][heap[i].y]<<"\t";  }cout<<endl;
			jj=del();
			//cout << jj.x<<","<<jj.y<<endl;
		}
		printf("%d\n",dist[n-1][m-1]);
	}
	return 0;
}