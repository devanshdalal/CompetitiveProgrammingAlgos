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

/////  This is completely written by me:  .  

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

bool vov(char ch){
	return ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U' or ch=='Y';
}

int main(){
    int t,k,n,l,p,q;
    // ios_base::sync_with_stdio(0);

    char xc[500011];
    scanf("%s",xc);
    l =strlen(xc);
    ll d[l+1],f1[l+1];
    fill(d,d+l+1,0);
    fill(f1,f1+l+1,0);
    for (int i = 0; i < l; ++i)
    {
    	int mx=max(l-i,i+1),mn=min(l-i,i+1);
    	if (vov(xc[i])){
    		d[1]++;
    		d[mn+1]--;
    		d[mx+1]--;
    	}
    }
    double ans=0;
    for (int i = 1; i <=l ; ++i)
    {
    	d[i]+=d[i-1];
    }
    for (int i = 1; i <=l ; ++i)
    {
    	f1[i]=f1[i-1]+d[i];
    	ans+=double(f1[i])/i;
    }
    printf("%0.7lf\n", ans );

    // for (int i = 1; i <=l; ++i)
    // {
    // 	d[i]+=d[i-1];
    // 	cerr  << d[i] << " "; 
    // }
    // cerr << endl;
   	// for (int i =l-1; i>0; --i)
   	// {
   	// 	d2[i]+=d2[i+1];
   	// }
    // for (int i = 1; i <=l; ++i)
    // {
    // 	tab[i]+=tab[i-1];
    // 	cerr  << tab[i] << " ";	 
    // }
    // cerr << endl;
    // for (int i = 1; i <=l; ++i)
    // {
    // 	if(d[i]>0)f1[[i]=f1[i-1]+d[i-1];
    // 	else f1[i]=0;
    // 	tab[i]=tab[i]+d[i];
    // 	cerr  << tab[i] << " "; 
    // 	ans+=double(tab[i])/i;
    // }
    // for (int i = l; i>0 ; --i)
    // {
    // 	if(d2[i]>0)d2[i]+=d2[i+1];
    // 	else d2[i]=0;
    // 	tab[i]=tab[i]+d2[i];
    // }
    // cerr << endl;
    // cout  << ans;


    

    return 0;
}