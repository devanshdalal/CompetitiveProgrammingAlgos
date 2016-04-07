#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h> 
#define MyN 800001
#define MAX  2099121

using namespace std;


int ar[MyN],rot[MAX],n;
int seg[MAX][12];

void make_seg(int node, int a, int b) {
    // if(a > b) return;
    if(a == b) {
        int w=ar[a];
        int fac=w==0?-1:pow(10,(int)log10(w));
        for (int k = 0; k<12; ++k)
        {
            seg[node][k]=w;
            w=(fac==-1?0:(w/fac)+ (w-(w/fac)*fac)*10);
        }
        return;
    }
    make_seg(node<<1, a, (a+b)/2);
    make_seg((node<<1)|1, 1+(a+b)/2, b);
    for (int k = 0; k<12; ++k)
        seg[node][k] = max(seg[node*2][k], seg[node*2+1][k]);
}

inline void update_seg(int node, int a, int b, int i, int j, int value) {
    if(a==i and b==j) {
        rot[node] = (rot[node]+value)%12;
        return;
    }
    int mid = (a+b)>>1,left=node<<1,right=1|(node<<1);
    if (j<=mid)
    {
        update_seg(left, a, mid, i, j, value);
    }else if (i>mid)
    {
        update_seg( right, 1+mid, b, i, j, value);
    }else{  
        update_seg(left, a, mid, i, mid, value );
        update_seg(right, 1+mid, b, mid+1, j, value);
    }
    for (int k = 0; k<12; ++k)
        seg[node][k] = max(seg[left][(k+rot[left])%12], seg[right][(k+rot[right])%12]); 
}

#define INF 0x7fffffff
inline int query(int node, int a, int b, int i, int j,int value) {
    if(a >= i && b <= j)
        return seg[node][(value+rot[node])%12];

    int mid = (a+b)/2,q1=-INF,q2=-INF;
    if (j<=mid)
        q1 = query(node*2, a, mid, i, j,(value+rot[node])%12);
    else if (i>mid)
        q2 = query(1+node*2, 1+mid, b, i, j,(value+rot[node])%12);
    else{ 
        q1 = query(node*2, a, mid, i, j,(value+rot[node])%12);
        q2 = query(1+node*2, 1+mid, b, i, j,(value+rot[node])%12);
    }   
    return max(q1, q2);;
}

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &ar[i]);
    make_seg(1, 0, n-1);

    int st, en, x,qer;
    char c;
    int begin, end;
    scanf("%d", &qer);
    while(  qer-- ){
        c='-';
        while(c!='0' and c!='1'  )
            c=getchar();
        if(c == '0'){
            scanf("%d %d %d", &st, &en, &x);
            update_seg(1, 0, n-1, st, en, x%12);
        }else{
            scanf("%d %d", &st, &en);
            printf("%d\n", query(1, 0, n-1, st, en,0) );
        }
    }
}