/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h> 

#define N_max 800001
#define MAX  2100011 // Why? :D
#define inf 0x7fffffff

int arr[N_max],*rot,n;
int **tree;

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
	if(node>=MAX){
		cerr << "exceeded" << endl;
		exit(0);
	}
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
		int w=arr[a];
		int fac=w==0?-1:pow(10,(int)log10(w));
		if (fac==0)
		{
			exit(0);
		}
    	// cout << "fac " << fac<< " "<< a<< " " << log10(a) << endl;
        for (int k = 0; k<12; ++k)
        {
        	tree[node][k]=w;
        	w=(fac==-1?0:(w/fac)+ (w-(w/fac)*fac)*10);
        } // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	for (int k = 0; k<12; ++k)
    {
		tree[node][k] = max(tree[node*2][k], tree[node*2+1][k]); // Init root value
    }
}

/**
 * Increment elements within range [i, j] with value value
 */
inline int md(int dd){
	if (dd>12)return dd-12;
	return dd;
}

inline void update_tree(int node, int a, int b, int i, int j, int value) {
    
	// if(a > b || a > j || b < i) // Current segment is not within range [i, j]
	// 	return;
    
  	if(a==i and b==j) {
		rot[node] = (rot[node]+value)%12;
		// rot[node] = (rot[node]+value)%12;
		return;
	}

	int mid = (a+b)>>1,left=node<<1,right=1|(node<<1);
	if (j<=mid)
	{
		update_tree(left, a, mid, i, j, value); // Updating left child
		// update_tree(node*2, a, mid, i, j, (value+rot[node])%12 ); // Updating left child
	}else if (i>mid)
	{
		update_tree( right, 1+mid, b, i, j, value); // Updating right child
		// update_tree(1+node*2, 1+mid, b, i, j, (value+rot[node])%12); // Updating right child
	}else{	
		// update_tree(node*2, a, mid, i, j, (value+rot[node])%12 ); // Updating left child
		// update_tree(1+node*2, 1+mid, b, i, j, (value+rot[node])%12); // Updating right child
		update_tree(left, a, mid, i, mid, value ); // Updating left child
		update_tree(right, 1+mid, b, mid+1, j, value); // Updating right child
	}


	for (int k = 0; k<12; ++k)
    {
		tree[node][k] = max(tree[left][(k+rot[left])%12], tree[right][(k+rot[right])%12]); // Init root value
		// tree[node][k] = max(tree[left][md(k+rot[left])], tree[right][md(k+rot[right])]); // Init root value
    } // Updating root with max value
    // rot[node]=0;
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j,int value) {
	
	// if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node][(value+rot[node])%12];

	int mid = (a+b)/2,q1=-inf,q2=-inf;
	if (j<=mid)
	{
		q1 = query_tree(node*2, a, mid, i, j,(value+rot[node])%12); // Query left child
		// q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	}else if (i>mid)
	{
		q2 = query_tree(1+node*2, 1+mid, b, i, j,(value+rot[node])%12); // Query right child
		// q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
	}else{	
		q1 = query_tree(node*2, a, mid, i, j,(value+rot[node])%12); // Query left child
		q2 = query_tree(1+node*2, 1+mid, b, i, j,(value+rot[node])%12); // Query right child
		// q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
		// q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
	}

	int res = max(q1, q2); // Return final result
	
	return res;
}

int main() {
	scanf("%d", &n);
    clock_t start=clock();

    rot=new int[MAX];
    tree=new int*[MAX];
    for (int i = 0; i < MAX; ++i)
    {
    	tree[i]=new int[12];
    }
	// cerr<<"init: " <<(double(clock()-start)/CLOCKS_PER_SEC) << " sec " << endl;
	start=clock();


    //initialize the input array (square root array)
    for(int i = 0 ; i < n ; i++){
            scanf("%d", &arr[i]);
    }
	
    clock_t st1=clock();
	build_tree(1, 0, n-1);
	double process=(double(clock()-st1)/CLOCKS_PER_SEC);

    double t1=0,t2=0;

    char c;
    int st, en, x,q;
	scanf("%d", &q);
    int begin, end;
    while(  q-- ){
    	c='-';
        while(c!='0' and c!='1'  )
        	c=getchar();
        if(c == '0'){
            scanf("%d %d %d", &st, &en, &x);
            st1=clock();
            update_tree(1, 0, n-1, st, en, x%12);
            t1+=(double(clock()-st1)/CLOCKS_PER_SEC);
			// cerr<<"upadte: " <<(double(clock()-st1)/CLOCKS_PER_SEC) << " sec " << endl;
        }else{
        	scanf("%d %d", &st, &en);
            st1=clock();
        	printf("%d\n", query_tree(1, 0, n-1, st, en,0) );
            t2+=(double(clock()-st1)/CLOCKS_PER_SEC);
			// cerr<<"query: " <<(double(clock()-st1)/CLOCKS_PER_SEC) << " sec " << endl;
        }
    }

	// update_tree(1, 0, n-1, 0, 3, 5); // Increment range [0, 6] by 5

	// update_tree(1, 0, n-1, 2, 2, 0); // Incremenet range [7, 10] by 12
	// update_tree(1, 0, n-1, 1, n-1, 1); // Increment range [10, N-1] by 100

	// cout << query_tree(1, 0, n-1, 0, n-1) << " "<<query_tree(1, 0, n-1, 1, n-1)<<" "<<query_tree(1, 0, n-1, 2, n-1)<< endl; // Get max element in range [0, N-1]
	// cout << query_tree(1, 0, n-1, 0, n-1) << " "<<query_tree(1, 0, n-1, 0, n-2)<<" "<<query_tree(1, 0, n-1, 0, n-3)<< endl; // Get max element in range [0, N-1]
	// cerr<<"time: " <<(double(clock()-start)/CLOCKS_PER_SEC) << " sec " << endl;
	// cerr<<"process: " << process << " sec " << endl;
	// cerr << "upd: " << t1 << endl << "query: " << t2 << endl;
}