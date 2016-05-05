#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
// #define max(a,b) a>b?a:b
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    ll i,j,k,l,c1,c2,x,y;
    cin >> c1 >> c2 >> x >> y;

    ll low=c1+c2,high=10+10*max(c1,c2);
    // cerr << low << " " << high << endl;
    while(low<=high){
    	l=(low+high)/2;
    	ll sur=l/(x*y);
    	i=l/x - sur;
    	j=l/y - sur;
    	// cerr << sur << j  << i << endl;
    	sur = sur + (j<=c1?0:j-c1) + (i<=c2?0:i-c2) ;
    	// cerr<< l <<  " " << sur << " "  << endl;  
    	if (l-sur<c1+c2)
    	{
    		low=l+1;
    	}else{
    		high=l-1;
    	}
    }
    cout << low << endl;
    
    return 0;
}