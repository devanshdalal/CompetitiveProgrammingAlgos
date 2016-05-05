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

ll gcd(ll a, ll b){
	if (b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main(){
    ll t,i,j,k,l,r,a,b,c;
    cin >> l >> r;
    bool done =false;
    for (i = l;!done and i <r ; ++i)
    {
    	for (j = i+1; !done and j <=r; ++j)
    	{
    		for (k = j+1;k <=r; ++k)
    		{
    			if (gcd(i,j)==gcd(j,k)==1 and gcd(i,k)!=1)
    			{
    				done=true;
    				goto here;
    			}
    		}
    	}
    }

    here:
    if (done)
    {
    	cout << i << " " << j << " " << k << endl;
    }else{
    	cout << "-1" << endl;
    }
    return 0;
}