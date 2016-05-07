#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
// #define max(a,b) a>b?a:b
#define mod 1000000007
// #define DD ios_base::sync_with_stdio(false)
#define maxx 10001
using namespace std;
typedef long long ll;


int main(){
	register int t,l,n,k,d,a,b;
	int i,j;
	cin >> n  >> k>>d;

	int as[200],bs[200];
	for (i = 0; i <= n; ++i)
	{
		as[i]=bs[i]=0;
	}
	bs[0]=1;
	bs[1]=1;
	as[d]=1;
	
	for (i = 2; i <= n; ++i)
	{
		for (j = i-1; j >= max(i-k,0); j--)
		{
			bs[i]=(bs[i]+bs[j])%mod;
			// cout << bs[i] << " ";
		}
	}


	for (i = d+1; i <= n; ++i)
	{
		for (j = max(i-k,0); j <= i-d ; ++j)
		{
			as[i]=(as[i]+bs[j])%mod;
			// cout << "ans:" << as[i] << endl ;

		}
		for (j = i-d+1; j < i ; ++j)
		{
			as[i]=(as[i]+as[j])%mod;
			// cout << "ans" << as[j] << endl ;
		}
	}

	// for (i = 0; i <= n; ++i)
	// {
	// 	cout << bs[i] << "endl";
	// }cout<< endl;

	cout << as[n] << endl;





	// printf("%lld %lld%lld\n",n,m,p );

	return 0;
}