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
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000009;

int main(){
    int t,i,j,k,l,n,m,p,q,a,b;
    DD;
    cin>>t;
    char ar[100001],br[100001];
    int *f=new int[100000],*g=new int[100000],ans;
    while(t--){
        cin >> ar ;
        cin >> br;
        cin >> a  >> b >> k;
        n=strlen(ar);
        m=strlen(br);
        if (a==0)
        {
            ans=0;
        }else if (b==0)
        {
            ans=a*abs(m-n);
        }else if (a*abs(n-m)>k)
        {
        	ans=k+1;
        }else{
            for (i=0; i <=n; ++i)
                g[i]=i*a;

            for (i = 1; i <=m; ++i)
            {
                p=i-k;
                if (p<=1)
                {
                    j=1;
                    f[0]=i*a;
                }else{
                    f[(j=p)-1]=k+1;
                }

                int last=i+k+1;
                if (last<n)
                {
                    f[last+1]=k+1;
                }
                for (; j <=last; ++j)
                {
                    if (ar[j-1]==br[i-1])
                    {
                        f[j]=g[j-1];
                    }else{
                        f[j]=min(a+ min(g[j],f[j-1]) , g[j-1]+b );
                    }
                }
                swap(f,g);
            }
            ans=g[n];
        }
        cout << (ans>k?-1:ans) << endl;

    }
    return 0;
}