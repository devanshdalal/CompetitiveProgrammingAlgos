#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int main(){
    int t,i,j,k,l,n,m,p,q;
    // ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    int a[n+1];
    for (i = 0; i <n; ++i)
    {
    	scanf("%d",&a[i]);
    }
    char ch;
    q=0;
    for (; m--; )
    {
    	do{
    		ch=getchar_unlocked();
    	}while(ch!='R' and ch!='C' and ch!='A');
    	scanf("%d",&p);
    	// cerr << ch << endl;
    	switch(ch){
    		case 'C': q=(q+p)%n;break;
    		case 'A': q=(q-p+n)%n;break;
    		case 'R':
    			// cout <<q << " "<<p << " "<< (q+p-1)%n << endl;
    			printf("%d\n", a[(q+p-1)%n] );
    	}

    }
    return 0;
}