#include <bits/stdc++.h>
#include <cstdio>
typedef long long ll;
using namespace std;
#define endl ('\n')
#define pb push_back
#define vi vector<int>

struct node{
	int d,g1,l1,g2,l2;
};

vector<node> tr[2621000];
int LMTN=(1<<19); 
int *arr=new int[500001],*brr=new int[500001];

inline void append(int tid, int a, int b, int i) {
    if(a == b) {
    	node grb;tr[tid].push_back(grb);return ;
    }
    int c1 =tid*2,c2=c1|1 ,mid = (a+b)/2,s1=tr[c1].size(),s2=tr[c2].size();
    node grb={i,s1,s1,s2,s2};
    if (arr[i]<=mid){
    	grb.l2=s2-1;
        append(c1, a, mid , i);
    }else{
    	grb.l1=s1-1;
        append(c2, 1+mid, b, i);
    }
    tr[tid].push_back(grb);
}

inline int kth(int node, int a, int b, int p1,int p2 ,int k) {
    if(a==b)return a;
    int mid=(a+b)/2;
    int left = max(0,tr[node][p2].l1-tr[node][p1].g1+1);
    if (k<=left)return kth(node*2,a,mid, tr[node][p1].g1,tr[node][p2].l1 ,k);
    else return kth(1|(node*2),mid+1,b, tr[node][p1].g2,tr[node][p2].l2 , k-left);
}

inline int xorq(int tid, int a, int b,int p1,int p2,int ax,int bn) {
    if(a==b )return a;
    int mid=(a+b)/2 ;
    if (ax&(1<<bn))
    	if(tr[tid][p2].l1 - tr[tid][p1].g1 + 1>0)
            return xorq(tid*2,a,mid,tr[tid][p1].g1,tr[tid][p2].l1,ax,bn-1);
    	else return xorq(1|(tid*2),1+mid,b,tr[tid][p1].g2 , tr[tid][p2].l2,ax,bn-1 );
    else
    	if(tr[tid][p2].l2 - tr[tid][p1].g2 + 1>0)
            return xorq(1|(tid*2),1+mid,b,tr[tid][p1].g2,tr[tid][p2].l2,ax,bn-1 );
    	else return xorq(tid*2,a,mid,tr[tid][p1].g1,tr[tid][p2].l1,ax,bn-1);
}

char buf[21];int ix;
inline void printInt(ll x) {
     ix = 9;
     do {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do{
        putchar_unlocked(buf[ix]);
     } while (buf[ix++] != '\n');
}

inline int rankx(int node, int a, int b,int p1,int p2,int x) {
    if(a==b or p2<p1)return max(0,p2 - p1+1);
    int mid = (a+b)/2;    
    if(x<=mid)return rankx(node*2, a, mid ,tr[node][p1].g1,tr[node][p2].l1, x );
    else return  max(0,tr[node][p2].l1-tr[node][p1].g1+1)
        +rankx(1|(node*2), mid+1, b, tr[node][p1].g2,tr[node][p2].l2 ,x);
}

inline void readInt(int &x) {
    register int c= getchar_unlocked();x = 0;
    for(; (c<48 || c>57); c = getchar_unlocked());
    for(; c>47 && c<58 ; c = getchar_unlocked()) x = (x<<1) + (x<<3) + c - 48;
}

inline void rem(int tid, int a, int b, int i,int oldv) {
    if(a == b) {tr[tid].pop_back();return ;}
    int mid=(a+b)/2;
    if (oldv<=mid)rem(tid*2, a,mid , i, oldv);
    else rem(1|(tid*2), 1+mid, b, i, oldv);
    tr[tid].pop_back();
}

void findn(int m){
	int query,x,k,l,r,clen=0;
	vector<int> *xtr[19];
    for(int i=0;i<19;i++)xtr[i]=new vi[1<<(19-i)];

    while(m--){
        readInt(query);
        if (query==0){
            readInt(x);
            arr[clen]=x;
            append(1,0,LMTN-1,clen);
            for(int j=0,n=x;j<19;j++,n>>=1)xtr[j][n].pb(clen);
            clen++;
        }else if (query==1){
            int a,b,c,t=0;
            readInt(b); readInt(c); readInt(a);
            int d=(~a);
            b--;
            for(int i=18;i>=0;i--){
                t=(t<<1) + ((d>>i)&1);
                vector<int>::iterator it=lower_bound(xtr[i][t].begin(),xtr[i][t].end(),b);
                if(!(it!=xtr[i][t].end() && *it<c))t^=1;
            }
            printInt(t);
        }else if(query==2){
            readInt(k);
            for (int i = 0; i < k; ++i){
            	clen--;
                for(int j=0,n=arr[clen];j<19;j++,n>>=1)xtr[j][n].pop_back();
                rem(1,0,LMTN-1,clen,arr[clen]);
            }
        }else if (query==3){
            readInt(l); readInt(r); readInt(x);
            printInt(rankx(1,0,LMTN-1,l-1,r-1,x));
        }else{
            readInt(l); readInt(r); readInt(k);
            printInt(kth(1,0,LMTN-1, l-1,r-1 ,k));
        }
    }
}

int main() {
    int tc,query,x,k,l,r,clen=0;
     buf[9] = '\n';
    readInt(tc);

    if (tc<=2999){findn(tc);return 0;}

    while(tc--){
        readInt(query);
        if (query==0){
            readInt(x);
            arr[clen]=x;
            append(1,0,LMTN-1,clen++);
        }else if (query==1){
            int a,b,c,t=0;
            readInt(b); readInt(c); readInt(a);
            printInt(xorq(1,0,LMTN-1,b-1,c-1,a,18));
        }else if(query==2){
            readInt(k);
            for (int i = 0; i < k; ++i){
            	clen--;
                rem(1,0,LMTN-1,clen,arr[clen]);
            }
        }else if (query==3){
            readInt(l); readInt(r); readInt(x);
            printInt(rankx(1,0,LMTN-1,l-1,r-1,x));
        }else{
            readInt(l); readInt(r); readInt(k);
            printInt(kth(1,0,LMTN-1, l-1,r-1 , k));
        }
    }
    return 0;
}