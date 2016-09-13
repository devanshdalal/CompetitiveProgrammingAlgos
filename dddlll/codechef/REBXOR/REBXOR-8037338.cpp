#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
// using namespace std;
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

struct Node
{
	Node * left,*right;
	int num;
};

#define BTS 31

void add(Node *root,ll n)
{
    for(int i=BTS;i>=0;i--)
    {
        if (root->right==NULL and root->left==NULL)
        {
        	assert(root->num>=0);
        	if ((root->num>>i)&1)
        	{
        		root->right=new Node();
        		root->right->num=root->num-(1<<i);
        	}else{
        		root->left=new Node();
        		root->left->num=root->num;
        	}
        	root->num=-1;
        }
        ll x= (n>>i) & 1;
        if(x)
        {
        	n-=(1<<i);
            if(root->right == NULL){
                root->right = new Node();
                root->right->num=n;
                return;
            }
            root = root->right;
        }else
        {
            if(root->left== NULL){
                root->left = new Node();
                root->left->num=n;
                return;
            }
            root = root->left;
        }
    }
}

ll query(Node *root,unsigned long long n)
{
    ll res = 0;
    for(int i=BTS;i>=0;i--)
    {
    	if (root->right==NULL and root->left==NULL)
        {
        	assert(root->num>=0);
        	return res+root->num;
        }
        bool x=(n>>i) & 1;
        if(!x )
        {
        	if (root->right!=NULL)
        	{
	        	res+=(ll(1)<<i);
	        	root=root->right;
        	}else{
        		//assert(root->left!=NULL);
	        	root=root->left;
        	}
        }else if(x){
        	if (root->left!=NULL)
        	{
        		root=root->left;
        	}else{
	        	res+=(ll(1)<<i);
        		//assert(root->right!=NULL);
            	root = root->right;
        	}
        }
    }
    return res;
}

void freeTrie(Node * root){
	if(root==NULL)return;
	freeTrie(root->left);
	freeTrie(root->right);
	free(root);
}

ll a[400001],b[400001],c[400001];
ll d[400001],e[400001];

int main(){
    ll t,n,k,l,p,q;
    std::ios_base::sync_with_stdio(0);
    clock_t start=clock();

    std::cin >> n ;
    // if (n>400000)
    // {
    // 	int j = n/0;
    // }
    for (int i = 0; i <n; ++i)
    {
    	std::cin >> a[i] ;
    }

    b[0]=a[0];
    for (int i = 1; i < n; ++i)
    {
    	b[i]=b[i-1]^a[i];
    }

    c[n-1]=a[n-1];
    for (int i = n-2 ; i>=0 ; --i)
    {
    	c[i]=c[i+1]^a[i];
    }

    Node *tree=new Node();
    tree->num=0;
    // add(tree,0);
    d[0]=a[0];
    for (int i = 1; i < n ; ++i)
    {
    	add(tree,b[i-1]);
    	ll best = query(tree, (unsigned ll) b[i]);
    	d[i]=std::max(d[i-1],best^b[i]);
    }
    // freeTrie(tree);
    
    tree=new Node();
    tree->num=0;
    // add(tree,0);

    e[n-1]=a[n-1];
    for (ll i = n-2; i>=0 ; --i)
    {
    	add(tree,c[i+1]);
    	ll best = query(tree,(unsigned ll) c[i]);
    	e[i]=std::max(e[i+1],best^c[i]);
    }

    ll ans =0;
    for (int i = 1; i < n; ++i)
    {
    	ans = std::max(ans,d[i-1]+e[i]);
    }

    std::cout << ans  << "\n";

    std::cerr << double(clock()-start)/CLOCKS_PER_SEC << "\n";

    return 0;
}