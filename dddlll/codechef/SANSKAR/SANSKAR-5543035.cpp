#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

ll a[1001],newa[100],n,k,c[5000000];

void allSets(int ind,int pos,ll sum){
	if (ind==n)
	{
		c[pos]=sum;
		return;
	}
	allSets(ind+1,pos,sum);
	allSets(ind+1,pos|(1<<ind),sum+a[ind]);
}

int main(){
    ll t,i,j,l,m,p,q;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        for (i=p=0; i <n; ++i)
        {
    		scanf("%lld",&newa[i]);
    		p+=newa[i];
    		// cerr << a[i] << endl;
        }
        // cerr << "p " << p << endl;
        if(n<k){
            printf("no\n" );
        }
        else if (p%k==0)
        {
        	q=p/k;
        	if (q==0 or k==1)
        	{
        		printf("yes\n");
        		continue;
        	}
        	memset(c,0,sizeof(c));
        	bool taken[100];
        	memset(taken,0,sizeof(taken));
            for (i = 0; i <n; ++i)
            {
                if(newa[i]==0)continue;
                if (newa[i]==q)
                {
                    taken[i]=true;
                    k--;
                    continue;
                }
                for (j= i+1; j<n; ++j)
                {
                    if(taken[j] or newa[j]==0)continue;
                    if (newa[i]+newa[j]==q){
                        taken[i]=taken[j]=true;
                        k--;
                    }
                }
            }
            for (i =j= 0; i < n; ++i)
            {
                if(!taken[i])a[j++]=newa[i];
            }
            n=j;
            sort(a,a+n);
        	allSets(0,0,0);
        	// for (i = 0; i < (1<<n); ++i)
        	// {
        	// 	cerr << i << "," << c[i] << " 	";
        	// }cerr << endl;
            memset(taken,0,sizeof(taken));
        	for (i=(1<<n)-1,m=0; i>0; --i)
        	{
        		if (c[i]==q)
        		{
        			for (j= 0; j<n ; ++j)
        			{
        				if ((1<<j)&i and taken[j])
        				{
        					break;
        				}
        			}
        			if (j!=n)continue;
        			for (j= 0; j<n ; ++j)
        			{
        				if ((1<<j)&i )
        				{
        					taken[j]=true;
        				}
        			}
        			m++;
        		}
        	}
        	// cerr << "m " << m << endl;
        	printf(m==k? "yes\n":"no\n");
        }else{
        	// cerr << "here " << endl;
        	printf("no\n" );
        }
    }
    return 0;
}