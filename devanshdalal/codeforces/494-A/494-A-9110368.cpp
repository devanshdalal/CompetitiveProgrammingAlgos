#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<cassert>
#include<ctime>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll base, ll exponent)
{
	if (base==1)return 1;
    ll result = 1;
    while (exponent ){
        if (exponent&1)result = (result * base)%mod;
        exponent = exponent >> 1;
        base = (base * base)%mod;
    }
    return result;
}

inline void multiply(ll F[2][2], ll M[2][2]){
  ll x =  ((F[0][0]*M[0][0])%mod) + ((F[0][1]*M[1][0])%mod);
  ll y =  ((F[0][0]*M[0][1])%mod) + ((F[0][1]*M[1][1])%mod);
  ll z =  ((F[1][0]*M[0][0])%mod) + ((F[1][1]*M[1][0])%mod);
  ll w =  ((F[1][0]*M[0][1])%mod) + ((F[1][1]*M[1][1])%mod);
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = y>=mod?y-mod:y;
  F[1][0] = z>=mod?z-mod:z;
  F[1][1] = w>=mod?w-mod:w;
}

inline void multiply2(ll F[2][2]){
  ll x =  F[0][0] + F[0][1];
  ll y =  F[0][0];
  ll w =  F[1][0];
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = F[1][0] = y;
  F[1][1] = w;
}

void power(ll F[2][2], ll n){
  if( n == 0 || n == 1)
      return;
  power(F, n/2);
  multiply(F, F);
  if (n%2 != 0)multiply2(F);
}

ll fib1(ll n){
  ll FF[2][2] = {{1,1},{1,0}};
  if (n<=2)return 1;
  power(FF, n-1);
  return FF[0][0];
}

ll gcd(ll a,ll b){
	while(b){
		ll temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int main(){
    ll t,i,j,l;
    fastio;
    char a[100021];
    cin >> a;
    l=strlen(a);
    bool done=false;
    ll left=0,right=0,p=0,tl=0,tr=0,lastj;
    for (j = l-1; j>=0 ; --j)
    {
    	if(a[j]=='(')tl++;
    	else if(a[j]==')')tr++;
    	else p++;
    	if(!done and a[j]=='#'){
    		lastj=j;
    		done=true;
    	}
    }
    if(tl-tr>=p){
	    for (i = 0; i < l; ++i)
	    {
	    	if(a[i]=='('){
	    		left++;
	    	}else{
	    		if(i==lastj)right+=(tl-tr-p+1);
	    		else right++;
	    		if(left<right){
	    			break;
	    		}
	    	}
	    }
	    if( i==l ){
	    	for (i = 0; i < p-1; ++i)
	    	{
	    		cout << 1 << endl;
	    	}
	    	cout << (tl - tr - p + 1) << endl;
	    }else{
	    	cout << -1 << endl;
	    }
    }else{	
	    	cout << -1 << endl;
    }
    return 0;
}