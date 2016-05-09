#include<iostream>
# include<cstdio>
# include<algorithm>
# include<cstring>
# include<vector>
# include<queue>
# include<map>
# include<cmath>
# include<bitset>
using namespace std;
typedef double d;
typedef long long ll;
int n;map<int,vector<int> > ma;

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

 
int segTree[400000];

int querySum(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += segTree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void updateTree(int idx,int val)
{
    while (idx <= n)
    {
        segTree[idx]+=val;
        idx += (idx & -idx);
    }
    //for(int i=0;i<=5;i++)cout<<segTree[i]<<" ";cout<<endl;
}

char a[100001];
int t,sx,sy,ex,ey;
bool close(int x,int y,int dx,int dy){
	return abs(x+dx-ex)+abs(y+dy-ey)<abs(x-ex)+abs(y-ey);
}

int main(){
	int i,j,k,l,x,y;
	scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey);x=sx,y=sy;
	scanf("%s",&a);l=strlen(a);bool done =0;
	for(i=0;i<l;i++){
		if(a[i]=='S' ){
			if(close(x,y,0,-1))y--;
		}else if(a[i]=='W' ){
			if(close(x,y,-1,0))x--;
		}else if(a[i]=='N' ){
			if(close(x,y,0,1))y++;
		}else if(a[i]=='E' ){
			if(close(x,y,1,0))x++;
		}
		//cout<<x<<" "<<y<<endl;
		if(x==ex and y==ey){done=1; break;}
	}
	if(done)printf("%d",i+1);
	else printf("-1");
	return 0;
}