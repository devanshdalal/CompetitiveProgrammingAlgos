#include<stdio.h>
#include<iostream>

typedef long long ll;

ll a[1000001],mod = 1000000009;

int main(){
	std::ios_base::sync_with_stdio(0);
	int t,n,h,x,y;
	
	std::cin >> t;
	while(t--){
		std::cin >> n >> h;
		std::fill(a,a+n,0);
		for(int i=0;i<n;i++){
			std::cin >> x >> y;
			a[x]++;
			a[y+1]--;
		}
		for(int i=1;i<n;i++){
			a[i]+=a[i-1];
		}
		for(int i=0;i<n;i++){
			a[i]=n-a[i];
		}
		ll window=0;
		for(int i=0;i<h;i++){
			window+=a[i];
		}
		ll ans=window;
		for(int i=0;i<n-h;i++){
			window=window-a[i]+a[i+h];
			ans=std::min(window,ans);
		}
		std::cout << ans << "\n";
	}
	


	return 0;
}