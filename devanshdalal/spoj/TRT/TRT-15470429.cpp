#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2000],s[2001],n;

ll dp[2000][2000];

ll sum(int i,int j){
	if(i>j)return 0;
	return s[j]-(i>0?s[i-1]:0);
}

int main() {
	
	// your code here
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	dp[0][0]=s[0]=a[0];
	for(int i=1;i<n;i++){
		s[i]= s[i-1]+a[i];
		dp[i][i]=a[i];
	}
	
	for(int len=1;len<n;len++){
		for(int i=0;i+len<n;i++){
			int j=len+i;
			dp[i][j]=max( a[i]+sum(i+1,j)+dp[i+1][j] , a[j]+sum(i,j-1)+dp[i][j-1] );
            //cerr <<  i <<  "," << j << "=" << dp[i][j] << " " << sum(j,j) <<  "    "; 
		 }
        //cerr << endl;
	}
	
	cout << dp[0][n-1] << endl;
	

	return 0;
}