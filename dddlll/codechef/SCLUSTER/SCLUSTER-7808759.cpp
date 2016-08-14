#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>
#include<vector>
#define N 100001

typedef long long ll;

int a[61][61],b[2001],ans[61][61];

int main(){
	std::ios_base::sync_with_stdio(0);
	int t,n,k;

	std::cin >> t;

	while(t--){
		std::cin >> n >> k;
		std::fill(*ans,*ans + (61*61) ,0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cin >> a[i][j];
			}
		}
		for (int i = 0; i < k; ++i)
		{
			std::cin >> b[i];
		}

		for (int i = n-1; k>=0 and i>=0 ; --i)
		{
			for (int j = 0; k>0 and j < n; ++j)
			{
				ans[i][j]=k--;
			}	
		}


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << ans[i][j] << " ";
			}
			std::cout << "\n";
		}
	}



	return 0;
}