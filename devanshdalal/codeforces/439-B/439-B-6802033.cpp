#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef unsigned long long ll;
typedef double d;
using namespace std;



int main(){
    register int t,i,j,n,m , d;
    cin >> n >> d;
    int a[100000];
    for ( i = 0; i < n; ++i)
    {
        cin >> a[i]; 
    }
    sort(a,a+n);
    ll ans=0;
    for ( i = 0; i < n; ++i )
    {
        ans+=ll(a[i])*ll(d);
        d=max(d-1,1);
    }
    cout << ans << endl;


    return 0;
}