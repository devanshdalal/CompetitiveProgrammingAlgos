#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

// I needed some comments here ???????????///
// after a large number of trails I think I have finally solved it.

typedef long long ll;
int limit[100];
ll mod=1000000007;
ll pre[65][6000];

void init(){
    limit[2] =1000000000;
    limit[3] =1000000;
    limit[4] =31622;
    limit[ 5 ]= 3981 ;
    limit[ 6 ]= 1000 ;
    limit[ 7 ]= 372 ;
    limit[ 8 ]= 177 ;
    limit[ 9 ]= 100 ;
    limit[ 10 ]= 63 ;
    limit[ 11 ]= 43 ;
    limit[ 12 ]= 31 ;
    limit[ 13 ]= 24 ;
    limit[ 14 ]= 19 ;
    limit[ 15 ]= 15 ;
    limit[ 16 ]= 13 ;
    limit[ 17 ]= 11 ;
    limit[ 18 ]= 10 ;
    limit[ 19 ]= 8 ;
    limit[ 20 ]= 7 ;
    limit[ 21 ]= 7 ;
    limit[ 22 ]= 6 ;
    limit[ 23 ]= 6 ;
    limit[ 24 ]= 5 ;
    limit[ 25 ]= 5 ;
    limit[ 26 ]= 4 ;
    limit[ 27 ]= 4 ;
    limit[ 28 ]= 4 ;
    limit[ 29 ]= 4 ;
    limit[ 30 ]= 3 ;
    limit[ 31 ]= 3 ;
    limit[ 32 ]= 3 ;
    limit[ 33 ]= 3 ;
    limit[ 34 ]= 3 ;
    limit[ 35 ]= 3 ;
    limit[ 36 ]= 3 ;
    limit[ 37 ]= 3 ;
    limit[ 38 ]= 2 ;
    limit[ 39 ]= 2 ;
    limit[ 40 ]= 2 ;
    limit[ 41 ]= 2 ;
    limit[ 42 ]= 2 ;
    limit[ 43 ]= 2 ;
    limit[ 44 ]= 2 ;
    limit[ 45 ]= 2 ;
    limit[ 46 ]= 2 ;
    limit[ 47 ]= 2 ;
    limit[ 48 ]= 2 ;
    limit[ 49 ]= 2 ;
    limit[ 50 ]= 2 ;
    limit[ 51 ]= 2 ;
    limit[ 52 ]= 2 ;
    limit[ 53 ]= 2 ;
    limit[ 54 ]= 2 ;
    limit[ 55 ]= 2 ;
    limit[ 56 ]= 2 ;
    limit[ 57 ]= 2 ;
    limit[ 58 ]= 2 ;
    limit[ 59 ]= 2 ;
    limit[ 60 ]= 1 ;
}

ll bse(ll i, ll myval)
{
	ll Mid,Lbound=1,Ubound=limit[i];
	while(Lbound<=Ubound)
	{
		Mid=(Lbound+Ubound)/2;
		if(myval>pre[i][Mid])
			Lbound=Mid+1;
		else if(myval<pre[i][Mid])
			Ubound=Mid-1;
		else{
			return Mid;
		}
	}
	return Ubound;
}

inline ll mpow(ll base, int exponent)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base);
        exponent = exponent >> 1;
        base = (base * base);
    }
    return result;
}

inline ll nth(ll x,int n){
    ll midp,Ubound=limit[n],Lbound=1;
    while(Lbound<=Ubound){
        ll mid=(Ubound+Lbound)/2;
        midp=mpow(mid,n);
        if (midp<x)
        {
            Lbound=mid+1;
        }else if (midp>x)
        {
            Ubound=mid-1;
        }else{
            return mid;
        }
    }
    return Ubound;
}

int main(){
    register int t,i,j,n,q; 
    ios_base::sync_with_stdio(false);  
    init();
    ll arr[20000];
    ll b[20000];
    for (i = 5; i <= 60; ++i)
    {
    	for(j=1;j<=limit[i];j++){
			pre[i][j]=mpow(j,i);
		}
    }
    cin >> t;
    while(t--){
        cin>> n >> q;
        for (i = 1; i <=n ; ++i)
        {
            cin >> arr[i] ;
        }
        b[n+1]=0;
        for ( i= n; i >0; i--)
        {
            b[i]=(b[i+1]+arr[i]);
        }
        for (i = 0; i < q; ++i)
        {
            ll x;
            cin >> x;
            ll myval =((x%mod)*arr[1])%mod;
            for (j = 2; j <= n; j++)
            {
                ll root=(x==1?1:(j<=4? nth(x,j):bse((ll)j,x) ));
                if (root==1){
                    myval=myval+b[j];
                    break;
                }
                myval= myval + (root*arr[j])%mod;
            }
            myval%=mod;
            myval=(mod+myval)%mod;
            cout << myval << " ";
        }
        cout << endl;
    }
}