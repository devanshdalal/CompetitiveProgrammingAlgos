using namespace std;
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<string.h>
#include <queue>
#include<stdio.h>
#include<iostream>
int preference[401];

class classComp {
    public:
    bool operator()(int t1, int t2)
    {
       return preference[t1]<preference[t2];
    }
};

int main(){
    int t,i,j,k,l,n,m,p,q;
    scanf("%d",&t);
    int a[401],dp1[401];
    bool onTab[401];
    while(t--){
        memset(onTab,0,sizeof(onTab));
        for (i = 0; i < 401; ++i)dp1[i]=401;
        scanf("%d%d",&n,&m);
        for (i = 0; i < m; ++i){
            scanf("%d",&a[i]);
        }

        for ( i = m-1; i>=0; --i){
            preference[i]=dp1[a[i]];
            dp1[a[i]]=i;
        }
        
        
        priority_queue< int ,vector< int > , classComp > pq;
        int tp,ans=0,act=0;
        for (i = 0; i < m; ++i)
            if (onTab[a[i]]){
                pq.push(i);
                continue;
            }else{
                if (act<n)
                    act++;
                else{
                    tp=pq.top();
                    while(!onTab[a[tp]]){
                        tp=pq.top();
                        pq.pop();
                    }
                    onTab[a[tp]]=0;
                }
                onTab[a[i]]=true;
                pq.push(i);
                ans++;
            }
        printf("%d\n",ans );
    }
    return 0;
}