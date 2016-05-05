#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    int a[200100];
    scanf("%d",&n);
    for (i = 0; i < n; ++i)
    {
       scanf("%d",&a[i]);
    }
    
    sort(a,a+n);
    for (i = 0; i < n; ++i)
    {
        if (a[i]!=a[0])break;
    }

    for (j = n-1; j>0; --j)
    {
        if (a[j]!=a[n-1])break;
    }

    if (a[0]==a[n-1])
    {
        cout << "0 "<< ll(n)*ll(n-1)/2 <<endl;
    }else{
        cout << a[n-1]-a[0] << " " << ll(i)*ll(n-1-j) << endl;
    }
    return 0;
}