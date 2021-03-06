#include<cstdio>
#include<cstring>
using namespace std; 
int r,c,ans=0; bool win=false;
char a[101][101];
bool visited[101][101];bool isinque[101][101];

struct node{ int x,y; int count; };

node que[500];  int b=0,e=1;

int safe(int x,int y){
	return (x<r && x>=0 && y<c && y>=0) && visited[x][y]==false && a[x][y]=='0' && isinque[x][y]==false;
}

void enque(int x,int y,int co){
	isinque[x][y]=true;
	que[e].x=x;
	que[e].y=y;
	que[e].count=co;
	if(e==9999) e=0;
	else e++;
}
 
node deque(){
	node zx=que[b];
	if(b==9999) b=0;
	else b++;
	isinque[zx.x][zx.y]=false;
	return zx;
}

int main(){
	int i,j,k;
	scanf("%d",&r);
	for(i=0;i<r;i++){
		scanf("%s",&a[i]);
	}
	c=strlen(a[0]);    //printf("%d\n",c);
	for(j=0;j<r;j++){
		for(k=0;k<c;k++){
			//printf("%c",a[j][k]);
			visited[j][k]=false;
			isinque[j][k]=false;
		}
		//printf("\n");
	}
	que[0].x=0;que[0].y=0;que[0].count=1;
	int level=1;
	while(b!=e){
		node zz=deque();
		if(zz.x==r-1 && zz.y==c-1) { win=true;  ans=zz.count;   break;}
		else{
			if( safe(zz.x,zz.y-1) ){ enque(zz.x,zz.y-1,zz.count+1);      }
			if( safe(zz.x,zz.y+1) ){ enque(zz.x,zz.y+1,zz.count+1);      }
			if( safe(zz.x-1,zz.y) ){ enque(zz.x-1,zz.y,zz.count+1);      }
			if( safe(zz.x+1,zz.y) ){ enque(zz.x+1,zz.y,zz.count+1);      }
			if( safe(zz.x+1,zz.y+1) ){ enque(zz.x+1,zz.y+1,zz.count+1);      }
			if( safe(zz.x+1,zz.y-1) ){ enque(zz.x+1,zz.y-1,zz.count+1);      }
			if( safe(zz.x-1,zz.y+1) ){ enque(zz.x-1,zz.y+1,zz.count+1);      }
			if( safe(zz.x-1,zz.y-1) ){ enque(zz.x-1,zz.y-1,zz.count+1);      }
		}
		visited[zz.x][zz.y]=true;
		level++;
	}
	printf("%d",ans); 
	return 0;
}