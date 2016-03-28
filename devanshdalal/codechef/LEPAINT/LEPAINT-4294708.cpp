#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#define d double
#define eps 0.0000001
using namespace std;
#define ll long long

int main(){
	int t,i,j,k,n,c,m,pr,qr;
	double mem[100][101],temp[101];
	int count[51];
	scanf("%d",&t);
	while(t--){
		d ans=0.0;
		scanf("%d%d%d",&n,&c,&k);
		for (i = 1; i <= n; ++i){
			for (j = 0; j < c; ++j)
				mem[i][j]=0.0;
			count[i]=0;
		}
		mem[0][1]=1.0;
		for(j=0;j<k;j++)
		{
			scanf("%d%d",&pr,&qr);
			for (i = pr; i <=qr; ++i)
				count[i]++;
		}
		for (i = 1; i <= k; ++i)
		{
			for (j= 0; j < c; ++j)
				mem[i][j]=mem[i-1][j]/2.0;
			for (j= 0; j <c ; ++j){
				d factor=(0.5/c)*mem[i-1][j];
				for (m = 0; m <c ; ++m)
					mem[i][(j*m)%c]+=factor;
			}
		}
		for (i = 1; i <= n; ++i)
		{
			d term=0.0;
			for (j = 0; j < c; ++j)
				term+=(j*mem[count[i]][j]);
			ans+=term;
		}
		printf("%.7lf\n", ans );
	}
	return 0;
}