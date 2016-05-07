#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
int n,k,a[200001],di[200001];ll b[200001],cum[200001],ma[200001];

int main(){
	int t,i,j,l,x=0,y=0;
	cin>>n;
	int te=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n/2;j++,te++){
			
			cout<<te<<" "<<n*n - te+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}