#include<cstdio>
using namespace std;
int r,c; bool win=false,jf;
//int getchar_unlocked()  {return getchar();}
//inline void fastRead_int(int &x) {
//	register int c = getchar_unlocked();
//	x = 0;
//	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
//	for(; c>47 && c<58 ; c = getchar_unlocked()) {
//		x = (x<<1) + (x<<3) + c - 48;
//	}
//}

int main(){
	int i,j;
	scanf("%d",&r);  scanf("%d",&c);
	char maze[r][c];
	for(i=0;i<r;i++) scanf("%s",&maze[i]); 
	char ma[r][c];
	int count=0;
	while(true){
		count++;
		jf=false;                   ////check
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(maze[i][j]=='J'){jf=true;
					if(i==0 || i==r-1 || j==c-1 || j==0) { win=true; goto label;     }
				}
			}
		}
		if(!jf){win=false; goto label;   }
		for(i=0;i<r;i++){                 //copy
			for(j=0;j<c;j++){
				ma[i][j]=maze[i][j];
			}
		}
		for(i=0;i<r;i++){                 //movej
			for(j=0;j<c;j++){
				if(ma[i][j]=='J'){
					if(j!=0 && ma[i][j-1]=='.') maze[i][j-1]='J';
					if(i!=r-1 && ma[i+1][j]=='.') maze[i+1][j]='J';
					if(i!=0 && ma[i-1][j]=='.') maze[i-1][j]='J';
					if(j!=c-1 && ma[i][j+1]=='.') maze[i][j+1]='J';
					maze[i][j]='K';	
				}
				else if(ma[i][j]=='F'){                 //movef
					if(j!=0 && (ma[i][j-1]=='.' || ma[i][j-1]=='J' || ma[i][j-1]=='K')) maze[i][j-1]='F';
					if(j!=c-1 && (ma[i][j+1]=='.' || ma[i][j+1]=='J' || ma[i][j+1]=='K')) maze[i][j+1]='F';
					if(i!=r-1 && (ma[i+1][j]=='.' || ma[i+1][j]=='J' || ma[i+1][j]=='K')) maze[i+1][j]='F';
					if(i!=0 && (ma[i-1][j]=='.' || ma[i-1][j]=='J' || ma[i-1][j]=='K')) maze[i-1][j]='F';		
				}
			}
		}
	}
	label: {if(win) {printf("%d",count);  }   else printf("IMPOSSIBLE");   }
	return 0;
}