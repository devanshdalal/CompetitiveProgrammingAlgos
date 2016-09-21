#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

/////  This is completely written by me: devansh dalal .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tr: build_tr(1, 0, N-1)
 * Update tr: update_tr(1, 0, N-1, i, j, value)
 * Query tr: query_tr(1, 0, N-1, i, j)
 */

struct data
{
	ll l[3],m[3],r[3],sum;
};

int arr[101010];
data *tr=new data[100110*5];

/**
 * Build and init tr
 */
void build_tr(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	tr[node].m[arr[a]] = tr[node].l[arr[a]] = tr[node].r[arr[a]] = 1;
    	tr[node].sum=arr[a];
		return;
	}
	
	int c1=node*2,c2=c1|1;

	build_tr(c1, a, (a+b)/2); // Init left child
	build_tr(c2, 1+(a+b)/2, b); // Init right child
	
	int s1=tr[c1].sum,s2=tr[c2].sum;
	for (int i = 0; i < 3; ++i){
		tr[node].l[i]=tr[c1].l[i];
		tr[node].m[i]=tr[c1].m[i] + tr[c2].m[i] ;
		tr[node].r[i]=tr[c2].r[i];
	}
	for (int i = 0; i < 3; ++i){
		tr[node].l[(s1+i)%3]+=tr[c2].l[i];
		tr[node].r[(s2+i)%3]+=tr[c1].r[i];
	}
	for (int i = 0; i < 3; ++i){
		for (int j= 0; j < 3; ++j){
			tr[node].m[(i+j)%3] += tr[c1].r[i]*tr[c2].l[j];
		}
	}
	tr[node].sum=(s1+s2)%3;
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tr(int node, int a, int b, int i ) {
  
	if(a > b || a > i || b < i) // Current segment is not within range [i, j]
		return;
  	if(a == i && b == i) { // Segment is fully within range
  		for (int i = 0; i < 3; ++i)
  		{
  			tr[node].l[i]=tr[node].m[i]=tr[node].r[i]=0;
  		}
    	tr[node].m[arr[a]] = tr[node].l[arr[a]] = tr[node].r[arr[a]] = 1;
    	tr[node].sum=arr[a];	
		return;
	}
	int mid=(a+b)/2;
	int c1=node*2,c2=c1|1;
	if (i<=mid){
		update_tr(c1, a, mid , i); // Updating left child
	}else{
		update_tr(c2, 1+mid, b, i); // Updating right child
	}

	int s1=tr[c1].sum,s2=tr[c2].sum;
	for (int i = 0; i < 3; ++i){
		tr[node].l[i]=tr[c1].l[i];
		tr[node].m[i]=tr[c1].m[i] + tr[c2].m[i] ;
		tr[node].r[i]=tr[c2].r[i];
	}
	for (int i = 0; i < 3; ++i){
		tr[node].l[(s1+i)%3]+=tr[c2].l[i];
		tr[node].r[(s2+i)%3]+=tr[c1].r[i];
	}
	for (int i = 0; i < 3; ++i){
		for (int j= 0; j < 3; ++j){
			tr[node].m[(i+j)%3] += tr[c1].r[i]*tr[c2].l[j];
		}
	}
	tr[node].sum=(s1+s2)%3;
}

data query_tr(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return tr[0]; // Out of range
	if(a == i && b == j) // Current segment is totally within range [i, j]
		return tr[node];
	int c1=node*2,c2=c1|1;
	int mid=(a+b)/2;
	if (j<=mid)
	{
		return query_tr(c1, a, mid, i, j);
	}else if (i>mid)
	{
		return query_tr(c2, mid+1, b, i, j);
	}
	data q1 = query_tr(c1, a, mid, i, mid ); // Query left child
	data q2 = query_tr(c2, 1+mid, b, 1+mid, j); // Query right child
	data t;

	int s1=q1.sum,s2=q2.sum;
	for (int i = 0; i < 3; ++i){
		t.l[i]=q1.l[i];
		t.m[i]=q1.m[i] + q2.m[i] ;
		t.r[i]=q2.r[i];
	}
	for (int i = 0; i < 3; ++i){
		t.l[(s1+i)%3]+=q2.l[i];
		t.r[(s2+i)%3]+=q1.r[i];
	}
	for (int i = 0; i < 3; ++i){
		for (int j= 0; j < 3; ++j){
			t.m[(i+j)%3] += q1.r[i]*q2.l[j];
		}
	}
	t.sum=(s1+s2)%3;
	return t;
}

// int main() {
// 	for(int i = 0; i < N; i++) arr[i] = 1;

// 	build_tr(1, 0, N-1);

// 	memset(lazy, 0, sizeof lazy);

// 	update_tr(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
// 	update_tr(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
// 	update_tr(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100

// 	cout << query_tr(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
// }


int main(){
    int n,m,p,q,t;
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    char a[n+1];
    cin >> a ;
    for (int i=0; i < n; ++i)
    {
    	arr[i]=int(a[i]-'0')%3;
    }
	build_tr(1, 0, n-1);
	for (; m--;)
	{
		cin >> t >> p >> q;
		p--;
		if (t==1)
		{
			arr[p]=q%3;
			update_tr(1,0,n-1,p);
		}else{
			q--;
			cout << (query_tr(1,0,n-1,p,q).m[0]) << "\n";
		}

	}
    

    return 0;
}