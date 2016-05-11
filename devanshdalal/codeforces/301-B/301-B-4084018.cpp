#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<math.h>
#define inf 2000000000
typedef long long ll;
using namespace std;
int n,d,a[120];
int cost[120],time[120];
int inheap[120];

struct node{
	int x,y,no;
};

node heap[200]; int last=1;
set<int> unvisit;

void swap(int i,int j){
	node temp=heap[i];
	heap[i]=heap[j];
	heap[j]=temp;
	inheap[heap[i].no]=i;
	inheap[heap[j].no]=j;
}

bool compare(int il,int jl){
	if(cost[heap[jl].no] > cost[heap[il].no]) return true;
	if(cost[heap[jl].no] == cost[heap[il].no] and time[heap[il].no]>=time[heap[jl].no]) return true;
	return false;
}

void upheap(int i){
	int j=i/2;
	while(j){
		if(compare(i,j)) { swap(i,j); i=j; j=i/2;  }
		else break;
	}
}
void add(int xx,int yy,int co,int ti,int no){
	heap[last].x=xx; heap[last].y=yy; heap[last].no=no;  cost[no]=co; time[no]=ti;
	inheap[no]=last;
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
	inheap[ta.no]=-1;
	unvisit.erase(ta.no);
	heap[1]=heap[--last];
	downheap(1);
	return ta;
}

struct dd{
	int x,y;
}data[300];

int dis(int i,int k){
	return d*(abs(data[i].x-data[k].x) + abs(data[i].y-data[k].y));
}

set<int>::iterator it;node te;
int main(){
	int t,i,j,k,l,xx,xy,dx,dy,c,di;
	scanf("%d%d",&n,&d);
	memset(inheap,-1,sizeof(inheap) );
	memset(cost,inf,sizeof(cost) );
	memset(time,0,sizeof(cost) );
	for(i=2;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[i]=0;
	//scanf("%d%d",&data[1].x,&data[1].y);
	for(i=1;i<=n;i++){
		scanf("%d%d",&data[i].x,&data[i].y);
		unvisit.insert(i);
		add(data[i].x,data[i].y,dis(i,1),a[i],i);
	}
	//for(i=1;i<=n+1;i++)cout<<data[i].x<<" "<<data[i].y<<"\t"; cout<<endl;
	//add(data[0].x,data[0].y,0,0,1);
	te=del();
	while(te.no!=n){
		//for(i=1;i<last;i++)cout<<heap[i].no<<" "; cout<<endl;
		//cout<<"x:" <<te.x<<" y:"<<te.y<<" c:"<<cost[te.no]<<" t:"<<time[te.no]<<" last:"<<last<<endl;
		unvisit.erase(te.no);
		l=te.no;
		for(it=unvisit.begin();it!=unvisit.end();it++){
			k= *it;
			di=dis(te.no,k);
			if(time[l]>di and (cost[k]>cost[l] || (cost[k]==cost[l] and time[l]-di+a[k]>time[k]) )){
					cost[k]=cost[l];
					time[k]=a[k]+time[l]-di;
					upheap(inheap[k]);
			}
			else if( time[l]<=di and cost[k]>cost[l]+di-time[l] ){
					cost[k]=cost[l]+di-time[l];
					time[k]=a[k];
					upheap(inheap[k]);
			}
		}
		te=del();
	}
	cout<<cost[n];
	label:;
	return 0;
}