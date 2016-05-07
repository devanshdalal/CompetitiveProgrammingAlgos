#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
#define ma 100100
char a[ma];
 
int main(){
	ios_base::sync_with_stdio(false);
	int t,i,j,k,l,p,q,x1,x2,y1,y2,n,m;
	cin>>n>>m;
	char fa[n+1][m+1];
	int mem[m+1][m+1];
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++)mem[i][j]=0;
	}
	for(i=1;i<n+1 and m!=0;i++){
		cin>>fa[i];
		int ct=0;
		for(j=1;j<=m;j++){
			if(fa[i][j-1]=='0')ct=0;
			else ct++;
			mem[ct][j]++;
		}
	}
	//~ 
	//~ for(i=1;i<=n;i++){
		//~ for(j=1;j<=m;j++){
			//~ cout<<mem[i][j]<<" ";
		//~ }	
		//~ cout<<endl;
	//~ }
	//~ 
	int maxz=0;
	for(i=1;i<=m;i++){
		int ct=0;
		for(j=m;j>0;j--){
			ct+=mem[j][i];
			if(maxz<j*ct)maxz=j*ct;
		}
	}
	
	
	//~ for(i=1;i<=m;i++){
		//~ for(j=m;j>=i;j--){
			//~ if(maxz>=(j-i+1)*n)break;
			//~ int co=0;
			//~ for(k=1;k<=n;k++){
				//~ if(mem[k][j]-mem[k][i-1]==j-i+1)co++;
			//~ }
			//~ if(maxz<(j-i+1)*co)maxz=(j-i+1)*co;
		//~ }
	//~ }
	
	
	//~ maxz=0;
	//~ for(i=1;i<=m;i++){
		//~ set<int> temp;
		//~ for(j=1;j<=n;j++){
			//~ if(fa[j][i]=='1')temp.insert(j);
		//~ }
		//~ set<int> ot; 
		//~ for(j=i+1;j<=m;j++){
			//~ for(set<int>::iterator it=temp.begin();it!=temp.end();it++){
				//~ if(fa[j][*it]=='1')ot.insert(*it);
			//~ }
		//~ }
		//~ temp=ot;
		//~ if(maxz<(j-i+1)*ot.size())maxz=(j-i+1)*ot.size();
	//~ }

	//~ cout<< x1 <<" "<<y1<<" "<<x2<<" "<<y2 <<endl;
	cout<< maxz <<endl;
	return 0;
}