#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define MAX  N*5 // Why? :D
#define inf 0x7fffffff
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbg2(x,y) {cerr << #x << " = " << x << "  "<< #y << " = " << y << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
    if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
} 
 
ll arr[N];
ll tree[MAX];
ll la[MAX];
ll lb[MAX];
 
/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
        tree[node] = arr[a]; // Init value
        return;
    }
    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    
    tree[node] = (tree[node*2] + tree[node*2+1])%mod; // Init root value
}

void update_tree(int node, int a, int b, int i, int j, ll value) {

    if(la[node] != 1 or lb[node]!=0 ) { 
        tree[node]  = (tree[node]*la[node] + lb[node]*(b-a+1))%mod; 
        if(a != b) {
            lb[node*2] = (la[node]*lb[node*2]+lb[node])%mod; 
            la[node*2] = (la[node*2]*la[node])%mod; 

            lb[node*2+1] = (la[node]*lb[node*2+1]+lb[node])%mod; 
            la[node*2+1] = la[node*2+1]*la[node]%mod; 
        }
        la[node] = 1; 
        lb[node] = 0; 
    }

    if(a > b || a > j || b < i)
        return;
    
    if(a >= i && b <= j) {
        tree[node] = (tree[node] + (b-a+1)*value)%mod;
 
        if(a != b) {
            lb[node*2] = (lb[node*2]+value)%mod;
            lb[node*2+1] = (lb[node*2+1]+value)%mod;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b,i, j, value); 
    tree[node] = (tree[node*2] + tree[node*2+1])%mod;
}

void update_treeM(int node, int a, int b, int i, int j, ll value) {
    if(la[node] != 1 or lb[node]!=0 ) { 
        tree[node]  = (tree[node]*la[node] + lb[node]*(b-a+1))%mod; 
        if(a != b) {
            lb[node*2] = (la[node]*lb[node*2]+lb[node])%mod; 
            la[node*2] = la[node*2]*la[node]%mod; 

            lb[node*2+1] = (la[node]*lb[node*2+1]+lb[node])%mod; 
            la[node*2+1] = la[node*2+1]*la[node]%mod; 
        }
        la[node] = 1; 
        lb[node] = 0; // Reset it
    }
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] = tree[node]*value%mod;

        if(a != b) { // Not leaf node
            la[node*2] = la[node*2]*value%mod;
            lb[node*2] = lb[node*2]*value%mod;
            la[node*2+1] = la[node*2+1]*value%mod;
            lb[node*2+1] = lb[node*2+1]*value%mod;
        }
        return;
    }
    update_treeM(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_treeM(1+node*2, 1+(a+b)/2, b,i, j, value); // Updating right child
    tree[node] = (tree[node*2] + tree[node*2+1])%mod; // Updating root with sum
}

void update_treeV(int node, int a, int b, int i, int j, ll value) {
    if(la[node] != 1 or lb[node]!=0 ) { 
        tree[node]  = (tree[node]*la[node] + lb[node]*(b-a+1))%mod; 
        if(a != b) {
            lb[node*2] = (la[node]*lb[node*2]+lb[node])%mod; 
            la[node*2] = la[node*2]*la[node]%mod; 

            lb[node*2+1] = (la[node]*lb[node*2+1]+lb[node])%mod; 
            la[node*2+1] = la[node*2+1]*la[node]%mod; 
        }
        la[node] = 1; 
        lb[node] = 0; // Reset it
    }
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] = (b-a+1)*value%mod;

        if(a != b) { // Not leaf node
            la[node*2] = 0;
            lb[node*2] = value;
            la[node*2+1] = 0;
            lb[node*2+1] = value;
        }
        return;
    }
    update_treeV(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_treeV(1+node*2, 1+(a+b)/2, b,i, j, value); // Updating right child
    tree[node] = (tree[node*2] + tree[node*2+1])%mod; // Updating root with sum
}
 
/**
 * Query tree to get max element value within range [i, j]
 */
ll query_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return 0; // Out of range
    
    if(la[node] != 1 or lb[node]!=0 ) { // This node needs to be updated
        tree[node]  = (tree[node]*la[node] + lb[node]*(b-a+1))%mod; // Update it
        if(a != b) {
            lb[node*2] = (la[node]*lb[node*2]+lb[node])%mod; // Mark child as lazy
            la[node*2] = la[node*2]*la[node]%mod; // Mark child as lazy

            lb[node*2+1] = (la[node]*lb[node*2+1]+lb[node])%mod; // Mark child as lazy
            la[node*2+1] = la[node*2+1]*la[node]%mod; // Mark child as lazy
        }
        la[node] = 1; // Reset it
        lb[node] = 0; // Reset it
    }

    if(a >= i && b <= j){
        return tree[node];
    } // Current segment is totally within range [i, j]

    if (j<=(a+b)/2)
    {
        return query_tree(node*2, a, (a+b)/2, i, j);
    }else if ( (a+b)/2<i )
    {
        return query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
    }else{
        ll q1 = query_tree(node*2, a, (a+b)/2, i, (a+b)/2 ); // Query left child
        ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, (a+b)/2 , j); // Query right child

        ll res = (q1 + q2)%mod; // Return final result
        return res;
    }
}

void printTree(){
    for (int i = 1; i < 8; ++i)
    {
        cerr << "T " << i << " " << tree[i] << endl;
    }

}

int main(){
    int t,k,n,q,l,r,v;
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    fill(la,la+MAX,1);
    fill(lb,lb+MAX,0);
    build_tree(1, 0, n-1);
    //printTree();

    for(int j=0;j<q;j++){
        cin >> t;
        switch(t){
            case 1:
                cin >> l >> r >> v;
                update_tree(1, 0, n-1, l-1, r-1, ll(v) );  break;
            case 2:
                cin >> l >> r >> v;
                update_treeM(1, 0, n-1, l-1, r-1, ll(v) );  break;
            case 3:
                cin >> l >> r >> v;
                update_treeV(1, 0, n-1, l-1, r-1, ll(v) );  break;
            case 4:
                cin >> l >> r ;
                cout << query_tree(1, 0, n-1, l-1, r-1) << "\n"; break;
            default:
                assert(0); 
        }
        // cerr << j+1 << "______________________________________________________" << endl;
        // printTree();
    }

    return 0;
}