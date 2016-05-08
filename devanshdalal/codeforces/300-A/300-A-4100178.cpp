#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
int n,k,m;
set<int> fi,se,th;

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int a[1000];

int main(){
	int t,i,j=0,te;int pro=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)th.insert(0);
		else if(a[i]>0)fi.insert(a[i]);
		else se.insert(a[i]);
	}
	set<int>::iterator it;
	if(fi.empty()){
		it=se.begin();
		fi.insert(*it);
		se.erase(*it);
		it=se.begin();
		fi.insert(*it);
		se.erase(*it);
	}
	if(se.size()%2==0){
		it=se.begin();
		th.insert(*it);
		se.erase(*it);
	}
	for(printf("%d ",se.size()),it=se.begin();it!=se.end();it++)printf("%d ",*it);printf("\n");
	for(printf("%d ",fi.size()),it=fi.begin();it!=fi.end();it++)printf("%d ",*it);printf("\n");
	for(printf("%d ",th.size()),it=th.begin();it!=th.end();it++)printf("%d ",*it);printf("\n");
	return 0;
}