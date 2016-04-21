#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>
#include<vector>
#define N 100001

typedef long long ll;

int a[N],appear[N];

int main(){
	std::ios_base::sync_with_stdio(0);
	ll n,m,q,ans=0;
	
	std::cin >> n >> m;


	assert(m<=n);


	if (n-m>m-1)
	{
		ans=std::min(m+1,n);
	}else{
		ans=std::max(m-1,ll(1));
	}
	

	std::cout << ans << "\n";

	return 0;
}