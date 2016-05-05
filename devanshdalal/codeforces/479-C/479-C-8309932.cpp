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
    int a[10001],n;

// int findmin(){
// 	int cmin=1000000;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cmin=min(cmin,a[i]);
// 	}
// 	return cmin;
// }

// int findmax(){
// 	int cmin=-1;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cmin=max(cmin,a[i]);
// 	}
// 	return cmin;
// }

bool pairCompare(const pair<int,int>& firstElem,const pair<int,int>& secondElem) {
  return firstElem.first < secondElem.first or (firstElem.first==secondElem.first and firstElem.second < secondElem.second);
}


int main(){
    int t,i,j,k,l,m,p,q;
    scanf("%d",&n);
    pair<int,int> a[n+1];
    for (i = 0; i < n; ++i)
    {
    	scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a,a+n,pairCompare);
    int min1=a[0].second;
    for (i = 1; i < n; ++i)
    {
    	if (a[i].second<min1)
    	{
    		min1=a[i].first;
    	}else{
    		min1=a[i].second;
    	}
    }
    printf("%d\n", min1 );
    return 0;
}