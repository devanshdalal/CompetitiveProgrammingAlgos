#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

int f[200003],n,m;

int read(int idx){
	int val=0;
	while(idx>0){
		val+=f[idx];
		idx-=(idx & -idx);
	}
	return val;
}

int update(int idx,int val){
	while(idx<=n){
		f[idx]+=val;
		idx+=(idx & -idx);
	}
}

struct node
{
	int val,ind;
};

struct range
{
    int l,r,val;
};

bool comp(node i,node j){
	return i.val<j.val;
}

inline ll merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  ll inv_count = 0;
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)){
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else{
      temp[k++] = arr[j++];
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count += ll(mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
 
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  return inv_count;
}

inline ll _mergeSort(int arr[], int temp[], int left, int right)
{
  ll mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
 
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

ll mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
int main(){
    int i,j,k,l,p,q;
    scanf("%d %d",&n,&m);
    int b[n+1];
    node arr[n+1];
    for (i = 1; i <=n; ++i)
    {
        arr[i].ind=i;
        scanf("%d",&p);
        b[i-1]=arr[i].val=p;
    }

    sort(arr+1,arr+n+1,comp);
    // for ( i = 1; i <=n; ++i)
    // {
    //     cerr << arr[i].val << " ";
    // }cerr << endl;
    int a[n+1],prev=mod;
    for (i =1,j=0; i <=n; ++i)
    {
    	if (arr[i].val==prev)
    	{
    		a[arr[i].ind]=j;
    	}else{
    		a[arr[i].ind]=++j;
    	}
        prev=arr[i].val;
    }
    // for ( i = 1; i <=n; ++i)
    // {
    //     cerr << a[i] << " ";
    // }cerr << endl;
    ll curr=mergeSort(b,n);

    range store[m+1];
    vector<int> query[n+1];
    vector<int>::iterator it;
    for (i=0; i<m; i++)
    {
        scanf("%d%d",&store[i].l,&store[i].r);
        store[i].val=0;
        query[store[i].l].push_back(i);
        query[store[i].r].push_back(i);
    }
    for (k=1; k<=n;k++ )
    {
        for (it=query[k].begin();it!=query[k].end(); ++it)
        {
            q=*it;
            i=store[q].l;
            j=store[q].r;
            if(i>j)swap(i,j);
            if (i==k)
            {
                int ltai=read(a[i]-1);
                int ltaj=read(a[j]-1);
                int gtai=k-1-read(a[i]);
                int gtaj=k-1-read(a[j]);
                store[q].val=ltai - gtai + gtaj - ltaj;
                // cerr<<"["<< ltai<<" "<<gtai<<" "<<ltaj<<" "<<gtaj<<endl; 
            }else{
                int ltai=read(a[i]-1);
                int ltaj=read(a[j]-1);
                int gtai=k-1-read(a[i]);
                int gtaj=k-1-read(a[j]);
                store[q].val+=-ltai + gtai - gtaj + ltaj;
                // cerr<<']'<< ltai<<" "<< gtai<<" "<<ltaj<<" "<<gtaj<<endl;
            }
        }
        update(a[k],1);
        // cerr <<k << " "<<a[k] << " ?????????????????" << endl;
        // for (i = 1; i <=7; ++i)
        // {
        //     cerr<< f[i] << " ";
        // }cerr << endl;
        // cerr << "------------------" << endl;
    }

    for (i = 0; i < m; ++i)
    {
        // cerr << curr<<" "<<ll(store[i].val)<< endl;
        printf("%lld\n",curr+ll(store[i].val) );
    }
    return 0;
}