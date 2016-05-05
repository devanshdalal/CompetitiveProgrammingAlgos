#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;


struct data
{
	int p,q;
	char team[2],card[2];
};

bool comp(data a, data b){
	return a.p < b.p ;
}

int main(){
    int t,i,j,k,l,n,m,p,q;
    char a[30],b[30],team[10];
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&t);
    int *foul1=new int[100],*foul2=new int[100];
    for (i = 0; i < 100; ++i)
    {
    	foul2[i]=foul1[i]=0;
    }
    data g[t+1];
    for(i=0;i<t;i++){
    	scanf("%d %s %d %s", &g[i].p ,g[i].team , &g[i].q , g[i].card  );
    }
    sort(g,g+t,comp);
    for (i = 0; i < t; ++i)
    {
    	if (g[i].team[0]=='h')
    	{
    		if (foul1[g[i].q]>=2)continue;
    		foul1[g[i].q]+=(g[i].card[0]=='y'?1:2);
    		if (foul1[g[i].q]>=2){
    			printf("%s %d %d\n", a , g[i].q , g[i].p );
    		}
    	}else{
    		if (foul2[g[i].q]>=2)continue;
    		foul2[g[i].q]+=(g[i].card[0]=='y'?1:2);
    		if (foul2[g[i].q]>=2){
    			printf("%s %d %d\n", b , g[i].q , g[i].p );
    		}
    	}  
    }

    return 0;
}