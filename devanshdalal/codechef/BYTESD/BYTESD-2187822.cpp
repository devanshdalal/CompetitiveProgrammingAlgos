#include<stdio.h>
 
int n,m;
char Cell[1001][1001];
char visited[1001][1001];
int dx[] = { 1,-1, 0, 0 };
int dy[] = { 0, 0, 1,-1 };
 
int isSafe(int x, int y)
{
    return ( (x>=0 && y>=0 && x<n && y<m)  &&  visited[x][y]==0  &&  Cell[x][y]!='w' );
}
 
int Dfs(int x,int y)
{
    int dir,xx,yy;
    visited[x][y] = 1;
    if(Cell[x][y] == 'f')  return 1;
    for(dir=0; dir<4; dir++)
    {
        xx = x+dx[dir], yy = y+dy[dir];
        if( isSafe(xx,yy) && Dfs(xx,yy) )   {  Cell[x][y] = 'x';  return 1;  }
    }    
   return 0;
}
 
int main() 
{ 
    int i,j,x,y,T;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d%d",&n,&m);
       for(i=0; i<n; i++)  for(j=0; j<m; j++)  visited[i][j] = 0;
       for(i=0; i<n; i++)  scanf("%s",&Cell[i]);
       for(i=0; i<n; i++)  for(j=0; j<m; j++)  if(Cell[i][j] == 's')  {  x=i;  y=j;  break;  }
       //visited[x][y] = 1;
       if( Dfs(x,y) )
       {
           for(i=0; i<n; i++)
              for(j=0; j<m;j++)
               {  
                   if( Cell[i][j] == 'x')  Cell[i][j] = 'b' ;
                   else if( Cell[i][j] == 'w' || Cell[i][j] == 'b' )  Cell[i][j] = '-' ;
               }
           Cell[x][y] = 's';
           for(i=0; i<n; i++)  printf("%s\n",Cell[i]);
       }
       else  printf("The path doesn't exist.\n");
    }
  return 0;
}