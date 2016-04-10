#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

int main(){
    int t,i,j,n,m,p,q=0;
    scanf("%d%d",&n,&m);
    int a[n];
    for (i = 0; i <n; ++i)
        scanf("%d",&a[i]);
    char mych;
    while( m--){
        do{
            mych=getchar_unlocked();
        }while(mych!='R' and mych!='C' and mych!='A');
        scanf("%d",&p);
        switch(mych){
            case 'A': q=(q-p+n)%n;break;
            case 'C': q=(q+p)%n;break;
            default : printf("%d\n", a[(q+p-1)%n] );
        }
    }
    return 0;
}