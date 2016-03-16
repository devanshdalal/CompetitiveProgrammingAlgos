#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
typedef double d;
int n,w;

ll *tree=new ll[1000000];


void update(int idx, int val)  // idx is the index of element that you have to update
{
        while (idx <= n)
        {
                 tree[idx] = (tree[idx]+(ll)val);   // for this you have update total tree
                 idx += (idx & -idx);  // generate indices to update in a tree.
        }
}

ll query(int idx)  // idx is the index of element 
 {
        ll sum=0;
        while (idx>0)
        {
              sum = sum+(ll)tree[idx];
              idx -= (idx & -idx); // change the index of tree .
        }
        return sum;
  }

int main(){
	int t,i,j,l,x=0,y=0;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		update(i,j);
	}	
	char arr[10];
	while(w--){
		scanf("%s",&arr);
		if(arr[0]=='S'){
			scanf("%d%d",&j,&l);
			j++;l++;
			ll ans=query(l)-(j>0?query(j-1):0);
			printf("%lld\n",ans);
		}else if(arr[0]=='G'){
			scanf("%d%d",&j,&l);
			update(j+1,l);
		}
		else{
			scanf("%d%d",&j,&l);
			update(j+1,-l);
		}
	}
	return 0;
}