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
	int n,m,q;
	ll ans=0,mostwins=-1;
	
	std::cin >> n >> m;
	
	int winner[n+1];
	std::fill(winner,winner+n+1,0);

	// std::cerr << m << "\n";
	for (int i = 0; i < m; ++i)
	{
		int max=-1,id=0;
		for (int j = 0; j < n; ++j)
		{
			std::cin >> q;
			if (q>max)
			{
				max=q;
				id=j+1;
			}
		}
		// std::cerr << id << " ggg\n";
		winner[id]++;
	}
	for (int i = 1; i <=n; ++i)
	{
		// std::cerr << winner[i] << "\n";
		if (winner[i]>mostwins)
		{
			mostwins=winner[i];
			ans=i;
		}
	}

	std::cout << ans << "\n";



	return 0;
}