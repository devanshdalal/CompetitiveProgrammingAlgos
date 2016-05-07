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
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef unsigned long long ll;
typedef double d;
using namespace std;


int main(){
    register int t,i,j,N,M,K,Li,Hi,Q=0;
    scanf("%d%d",&N,&M);
    for (i = 0; i < N; ++i)
    {
        scanf("%d",&Li);
        Q+=Li;
    }
    int ma=(M-Q-10*(N-1));

    printf("%d\n",ma<0 ?-1:2*(N-1)+ ma/5 );
    return 0;
}