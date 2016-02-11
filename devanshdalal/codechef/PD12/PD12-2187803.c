#include<stdio.h>
//int a,b,j,max,maxi,te;
//int main(){
//	scanf("%d",&a);/
//	while(a--){
//		scanf("%d",&b);
//		scanf("%d",&max);maxi=1;
//		for(j=2;j<(b+1);j++){
//			scanf("%d",&te);
//			if(max<=te){max=te; maxi=j;  }
//		}
//		printf("%d\n",maxi);
//	}
//	return 0;
//}
 
int i,j,T,n,m,dir;
char Cell[201][201];
int dx[] = { 1,-1,0,0,1,-1,-1,1 };
int dy[] = { 0,0,1,-1,-1,-1,1,1 };
 
int isSafe(int x, int y)
{
    return ( (x>=0 && y>=0 && x<n && y<m) && Cell[x][y]=='#' );
}
 
void Dfs(int x,int y)
{
    Cell[x][y] = '.';
    for(dir=0; dir<8; dir++)
    {
        int xx = x+dx[dir], yy = y+dy[dir];
        if( isSafe(xx,yy) )   Dfs(xx, yy);
    }
}
 
int main() 
{ 
    scanf("%d",&T);
    while(T--)
    {
        int Count = 0;
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++) scanf("%s",Cell[i]);
        for(i=0; i<n; i++)
          for(j=0; j<m; j++)
          {
             if( Cell[i][j]=='#' )   {  Count++;  Dfs(i,j);  }
          }
        printf("%d\n",Count);
    }
  return 0;
}