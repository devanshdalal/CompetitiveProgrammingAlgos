#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
typedef long long ll;
#define MAX 1000010
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;
int MaxVal;

int *tree;
inline void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

inline ll read(int idx){
    ll sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}


int main(){
    int t,i,j,k,l,n,d;
    int *a,*c1,*c2;
    scanf("%d",&n);
    a=new int[n+1];
    c1=new int[n+1];
    c2=new int[n+1];
    tree=new int[n+1];
    map<int,int> ma;
    MaxVal=n;
    tree[0]=0;
    for (i = 1; i <=n; ++i)
    {
        c1[i]=c2[i]=tree[i]=0;
        scanf("%d",&a[i]);
        if(ma[a[i]]){
            int te=ma[a[i]];
            c1[i]=c1[te]+1;
        }else{
            c1[i]=1;
        }
        ma[a[i]]=i;
    }
    ma.clear();
    for (i = n; i>0; --i)
    {
        if(ma[a[i]]){
            int te=ma[a[i]];
            c2[i]=c2[te]+1;
        }else{
            c2[i]=1;
        }
        ma[a[i]]=i;
    }

    update(c2[n],1);
    ll ans=0;
    for (i = n-1; i >0; --i)
    {
        ans=ans+read(c1[i]-1);
        update(c2[i],1);
    }

    cout << ans << endl;

    return 0;
}