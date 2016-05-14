#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<unordered_map>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 1000000
#define S    2000002
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int remx[S],remy[S];
vector<int> v[S];
vector<int>::iterator it,ed;

int main(){
    int t,i,j,k,l,n,m,p,q;
    DD;
    cin >> n;
    int a[n+1],b[n+1];

    for ( i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] ;
        a[i]+=maxx;
        b[i]+=maxx;
        v[a[i]].push_back(b[i]);
    }
    ll ans;
    if (n<=2)
    {
        ans=4-n;
    }else{
        ans=2;
        bool c1,c2,c3,c4;
        int rotx,roty,u1x,u1y,u2x,u2y,u3x,u3y,u4x,u4y;
        for (i = 0; i < n; ++i)
        {
            for (j = i+1; j < n; ++j)
            {
                rotx=a[j]-a[i], roty=b[j]-b[i];
                u1x=a[i]-roty , u1y= b[i]+rotx;
                u2x=a[j]-roty , u2y= b[j]+rotx;

                u3x=a[i]+roty , u3y= b[i]-rotx;
                u4x=a[j]+roty , u4y= b[j]-rotx;

                c1=c2=c3=c4=false ;
                if ((u1x>=0) and (u1x<S) and (u1y>=0) and (u1y<S))
                {
                    for (it=v[u1x].begin(),ed=v[u1x].end(); it!=ed ; ++it)
                    {
                        if(*it==u1y){
                            c1=true;
                            break;
                        }
                    }
                }

                if ((u2x>=0) and (u2x<S) and (u2y>=0) and (u2y<S))
                {
                    for (it=v[u2x].begin(),ed=v[u2x].end(); it!=ed ; ++it)
                    {
                        if(*it==u2y){
                            c2=true;
                            break;
                        }
                    }
                }

                if ((u3x>=0) and (u3x<S) and (u3y>=0) and (u3y<S))
                {
                    for (it=v[u3x].begin(),ed=v[u3x].end(); it!=ed ; ++it)
                    {
                        if(*it==u3y){
                            c3=true;
                            break;
                        }
                    }
                }

                if ((u4x>=0) and (u4x<S) and (u4y>=0) and (u4y<S))
                {
                    for (it=v[u4x].begin(),ed=v[u4x].end(); it!=ed ; ++it)
                    {
                        if(*it==u4y){
                            c4=true;
                            break;
                        }
                    }
                }

                if ( (c1 and c2) or (c4 and c3) )
                {
                    ans=0;
                    i=n+1;
                    break;
                }else if(c1 or c2 or c3 or c4 ){
                    ans=1;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}