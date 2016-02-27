#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

bool check(int &x1,int &y1,int &x2,int &y2,int & x3,int &y3){
	return (y2-y1)*(y3-y2)==(x1-x2)*(x3-x2);
}

int main(){
	int i,j,k,t,x1,x2,x3,y1,y2,y3;
	scanf("%d",&t);
	int ans=0;
	while(t--){
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(check(x1,y1,x2,y2,x3,y3) or check(x2,y2,x3,y3,x1,y1) or check(x3,y3,x1,y1,x2,y2))
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}