typedef long long ll;
#include<stdio.h>
#include<iostream>
using namespace std;
typedef double ld;
/*

Devansh Dalal - application of dp and linearity of expectation and probability. 


*/

ll max(ll a , ll b){ return a>b? a:b;}

ll a[100],c[100],it[100];
ll fact[21],n,k,rem[21][201][21];

inline ll gcd(ll n1, ll n2) {
    ll tmp;
    while (n2 ){
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

double find(int s1,int s2){
	double ans=0;
	ll i,j=1,kk,nn=n-2,sum=0;
	for (i = 0; i < n; ++i){
		if(i==s1 or i==s2)continue;
		it[j++]=a[i];
		sum+=a[i];
	}
	for ( i = 0; i <= n; ++i)
		for (j = 0; j <= sum+a[s1]+a[s2]; ++j)
			for (int l = 0; l<= n; ++l)
				rem[i][j][l]=0;
	rem[1][it[1]][1]=1;
	for ( i=2; i <= nn ; ++i){
		for (j = 1; j <= sum ; j++)
			for (int l = 1; l <=i-1 ; l++)
				rem[i][j][l]=rem[i-1][j][l];
		rem[i][it[i]][1]+=1;
		for (j = 1; j <= sum ; j++)
			for (int l = 1; l <=i ; l++)
				rem[i][j+it[i]][l+1]+=rem[i-1][j][l];
	}
	for (j =max(0,k-a[s1]-a[s2]); j < k ; j++){
		for (int l = 0; l <= nn ; l++){
			ll num=fact[l]*(k-j- max(k-a[s1]-j,0) - max(k-a[s2]-j,0) )*(nn-l+1)*fact[nn-l]*2; 
			ll gc=gcd(num,fact[n]);
			double res=double(num/gc)/double(fact[n]/gc);
			ans+=(l==0 and j==0?res:rem[nn][j][l]*res);
		}
	}
	return ans;
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    for (i =fact[0]=1; i < 21; ++i)
    	fact[i]=ll(i)*fact[i-1];
    while(t--){
        double ans=0;
        scanf("%lld%lld",&n,&k);
        for (i = 0; i < n ; ++i){
            scanf("%lld%lld",&a[i],&c[i]);
            ans+=max(0,a[i]-k);
        }
        for (i = 0; i <n ; ++i)
        	for (j = i+1; j < n; j++)
        		if ( c[i]==c[j] )
        			ans+=find(i,j);
        printf("%0.7lf\n", ans );
    }
    return 0;
}