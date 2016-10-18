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
	int n,k;
	ll ans=0;
	
	std::cin >> n >> k;
	std::fill(appear,appear+N,n);
	for (int i = 0; i < n; ++i)
	{
		std::cin>>a[i];
	}

	int latest=n,latestBiggerThank=n;
	for (int i = n-1; i>=0; --i)
	{
		int num = a[i]-k;
		if (num==0)
		{
			ans+=ll(latestBiggerThank-i);
			latest=latestBiggerThank;
		}else{
			for (int j = 1; j*j <=num; ++j)
			{
				int other=num/j;
				if(other<=k){break;}
				if (other*j==num)
				{
					if(j>k)latest=std::min(latest,appear[j]);
					if(other>k)latest=std::min(latest,appear[other]);
				}
			}
			ans+=ll(latest-i);
		}

		if(a[i]>k)latestBiggerThank=i;
		appear[a[i]]=i;
	}

	std::cout << ans << "\n";



	return 0;
}