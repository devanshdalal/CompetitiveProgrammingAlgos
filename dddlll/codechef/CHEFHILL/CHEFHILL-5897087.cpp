#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define io ios_base::sync_with_stdio(0)
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x > y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index){
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return -1;
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe){
    if (qs < 0 || qe > n-1 || qs > qe){
        printf("Invalid Input");
        return -1;
    }
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int main(){
    int t,j,k,l,p,q,n;
    io;

    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    int *st = constructST(a, n);
    cin >> q;
    while(q--){
    	cin >> j >> k ;
    	j--; k--;
    	// cerr << j << " " << k-1 << " " <<  RMQ(st, n, j, k-1) << endl;
    	if( RMQ(st, n, j, k-1)<=a[j] ){
    		cout << "YES\n";
    	}else{
    		cout << "NO\n";
    	}
    }
    return 0;
}