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

int level(int p){
	return 1+log2(p);
}

int lca(int p,int q){
	while(p!=q){
		if (p>q)
		{
			p/=2;
		}else{
			q/=2;
		}
	}
	return p;
}

int main(){
    int t,i,j,k,l,n,m,p,q;
    // cerr << level(5) << endl;
    scanf("%d",&t);
    char qury[100];
    bool status=true;
    while(t--){
        scanf("%s",qury);
        if (qury[1]=='i'){
        	status=!status;
        }else{
    		scanf("%d %d",&p,&q);
    		// while()
    		int count=1,clca=lca(p,q),black=level(p)&1;
    		while(p!=clca){
    			p/=2;
    			count++;
    		}
    		while(q!=clca){
    			q/=2;
    			count++;
    		}
    		black=black?(count+1)/2:count/2;
    		// cerr <<"p " << p <<" "<<  level(p) << endl;
    		if (qury[1]=='b')
    		{
    			// cerr << black << " " << status << endl;
    			printf("%d\n", status?black:count-black   );
    		}else{
    			printf("%d\n", status?count-black:black   );
    		}
        }
    }
    return 0;
}