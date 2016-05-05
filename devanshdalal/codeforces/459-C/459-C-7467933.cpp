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
    int t,i,j,k,l,n,d;
    int a[1001][1001];
    scanf("%d%d%d",&n,&k,&d);
    ll res=ll(k);
    bool done=false;
    for (i = 1; i <=d; ++i)
    {
        if (res>=ll(n))
        {
            done=true;
            break;
        }
        res=res*ll(k);
    }
    if (done)
    {
        for (i = 0; i < d; ++i)
        {
            a[i][0]=0;
        }
        for ( i = 1; i < n; ++i)
        {
            int carry=1;
            for (j = d-1; j>=0; --j) {
                a[j][i]=(a[j][i-1]+carry)%k;
                // cout<< i << " "<<j << " "<< a[i][0] <<";" << a[i-1][j]<<" "<<carry <<" "<< (a[i-1][j]+carry)%k << endl; 
                carry=(a[j][i-1]+carry)/k;
                // cout<< ";" << a[i-1][j]<<" "<<carry <<" "<< (a[i-1][j]+carry)/k << endl; 
            }
        }
        for (i = 0; i < d; ++i)
        {
            for (j = 0;j < n; ++j)
            {
                printf("%d ",a[i][j]+1);
            }
            printf("\n");
        }
    }else{
        printf("-1\n");
    }


    return 0;
}