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

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    char a[1001];
    while(t--){
        scanf("%d",&n);
        scanf("%s",a);
        bool indian=false,noni=false;
        for (i = 0; i < n; ++i)
        {
        	if (a[i]=='Y')
        	{
        		noni=true;
        		break;
        	}else if(a[i]=='I'){
        		indian=true;
        		break;
        	}
        }
        if (indian or noni)
        {
        	printf(indian? "INDIAN\n":"NOT INDIAN\n");
        }else{
        	printf("NOT SURE\n");
        }
    }
    return 0;
}