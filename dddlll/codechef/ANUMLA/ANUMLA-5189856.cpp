#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define maxx 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

class comp1 {
    public:
    bool operator()(int  t1, int t2) // Returns true if t1 is earlier than t2
    {
       return t1>t2;
    }
};

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int a[100001],b[100001],ans[100];
    while(t--){
        scanf("%d",&n);
        m=1<<n;
        for (i = 0; i <m; ++i)
        {
        	scanf("%d",&a[i]);
        }
        sort(a,a+m);
        ans[0]=a[1];
        ans[1]=a[2];
        priority_queue< int , vector< int > , comp1 > pq;
        b[0]=0;
        b[1]=a[1];
        b[2]=a[2];
        b[3]=a[2]+a[1];

        // pq.push(10);
        // pq.push(1);
        // pq.push(9);
        // pq.push(19);
        // for (i = 0; i < 4; ++i)
        // {
        // 	cerr << pq.top() << endl;
        // 	pq.pop();
        // }

        pq.push(a[1]+a[2]);
        k=4;
        for (i = 1,j=3; i < n-1 and j<m; j++ )
        {
        	// while(!pq.empty() and pq.top()<a[j])pq.pop();
        	if (!pq.empty() and pq.top()==a[j])
        	{
        		pq.pop();
        	}else
        	{
        		ans[++i]=a[j];
        		b[k]=ans[i];
        		for (l= 1; l<k ; ++l)
        		{
        			b[l+k]=b[l]+ans[i];
        			pq.push(b[l+k]);
        		}
        		k=k*2;        		
        	}
        }

        for (i = 0; i < n-1; ++i)
        {
        	printf("%d ", ans[i] );
        }
        	printf("%d\n", ans[i] );

    }
    return 0;
}