#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<unordered_map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define N 3125
// #define N 18750
typedef long long ll;
// typedef unsigned long long ul;
// typedef unsigned long long ll;
typedef double d;
using namespace std;
ll mod=100*N;
unordered_map<ll,ll> memFib;

inline void multiply(ll F[2][2], ll M[2][2]){
  ll x =  ((F[0][0]*M[0][0])%mod) + ((F[0][1]*M[1][0])%mod);
  ll y =  ((F[0][0]*M[0][1])%mod) + ((F[0][1]*M[1][1])%mod);
  ll z =  ((F[1][0]*M[0][0])%mod) + ((F[1][1]*M[1][0])%mod);
  ll w =  ((F[1][0]*M[0][1])%mod) + ((F[1][1]*M[1][1])%mod);
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = y>=mod?y-mod:y;
  F[1][0] = z>=mod?z-mod:z;
  F[1][1] = w>=mod?w-mod:w;
  // F[0][0] = x%mod;
  // F[0][1] = y%mod;
  // F[1][0] = z%mod;
  // F[1][1] = w%mod;
}

inline void multiply2(ll F[2][2]){
  ll x =  F[0][0] + F[0][1];
  ll y =  F[0][0];
  ll w =  F[1][0];
  F[0][0] = x>=mod?x-mod:x;
  F[0][1] = y;
  F[1][0] = y;
  F[1][1] = w;
  // F[0][0] = x;
  // F[0][1] = y;
  // F[1][0] = z;
  // F[1][1] = w;
}

void power(ll F[2][2], ll n){
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply2(F);
}

ll pre,nxt;
ll fib1(ll n){
  ll FF[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(FF, n-1);
  pre=FF[1][1];
  nxt=FF[1][0];
  return FF[0][0];
}

ll fib2(ll n){
  // return fib1(n);
  if (memFib[n])
  {
    return memFib[n];
  }
  ll ans=fib1(n);
  memFib[n]=ans;
  memFib[n-2]=pre;
  memFib[n-1]=nxt;
  return ans;
}

inline ll lucas(ll b){
	if(b==0)return 2;
  return (fib2(b+1)+fib2(b-1))%mod;
	// return (fib1(b+1)+fib1(b-1))%mod;
}

// ll coef3(ll j){
//   if (j<0)return 0;
//   if (j==0)return 18750;
//   ll l=j%mod;
//   ll l2=((l+1)*(l+2)/2)%mod;
//   ll l3=((l+3)*(l+4)/2)%mod;
//   ll l4=(l2*l3)%mod;
//   ll le=((5*(l+5)*l4)%mod)*lucas(j+6) + ((5*21*6*(l+3)*l2)%mod)*lucas(j+4) + 6*126*((l+1)*lucas(j+2))%mod;
//   ll ri=150*(l4*fib2(j+5))%mod +30*56*(l2*fib2(j+3))%mod + 6*252*fib2(j+1);
//   return le+ri;
// }

// ll coef3(ll j){
//     if (j<0)return 0;
//     if (j==0)return ll(18750);
//     ll l=j%mod;
//     ll l2=(((j+1)*(j+2))>>1)%mod;
//     ll l3=(((j+3)*(j+4))>>1)%mod;
//     ll l4=(l2*l3)%mod;
//     ll le=5*((((l+5)*l4)%mod)*lucas(j+6))%mod + 210*((((l+3)*l2)%mod)*lucas(j+4))%mod + 6*126*((l+1)*lucas(j+2))%mod;
//     ll ri=150*(l4*fib2(j+5))%mod + 30*56*((l2*fib2(j+3))%mod) + 6*252*fib2(j+1);
//     return (le+ri)%mod;
// }

// ll coef3(ll j){
//     if (j<0)return 0;
//     if (j==0)return 9375;
//     ll l=j%mod;
//     ll l2=(((j+1)*(j+2))>>1)%mod;
//     ll l3=(((j+3)*(j+4))>>1)%mod;
//     ll l4=((l2*l3)>>1)%mod;
//     ll le=( ((5*(l+5)*l4)%mod)*lucas(j+6))%mod + (((105*(l+3)*l2)%mod)*lucas(j+4))%mod + (3*126*(l+1)*lucas(j+2))%mod;
//     ll ri=150*(l4*fib2(j+5))%mod + 15*56*((l2*fib2(j+3))%mod) + 3*252*fib2(j+1);
//     return (le+ri)%mod;
// }

ll coef3(ll j){
    if (j<0)return 0;
    if (j==0)return N;
    ll t1=j+1,t2=j+2,t3=j+3,t4=j+4;
    ll l2,l3;
    if (j%4==0)
    {
    	t2/=2;
    	t4/=4;
    }else if(j%4==1){
    	t1/=2;
    	t3/=4;
    }else if(j%4==2){
    	t2/=4;
    	t4/=2;
    }else{
    	t1/=4;
    	t3/=2;
    }

    if (j%3==0)
    {
    	t3/=3;
    }else if (j%3==1)
    {
    	t2/=3;
    }else{
    	t1/=3;
    }
    t1=t1%mod;
    t2=t2%mod;
    t3=t3%mod;
    t4=t4%mod;

    l2=(t1*t2)%mod;
	l3=(t3*t4)%mod;
    // cout <<"dbug " << l2 << " "<< l3 << endl;
    ll l4=(l2*l3)%mod;
    ll l=j%mod,sp;
	if (j%2==0)
	 {
	 	sp=(((j+1)%mod)*(((j+2)/2)%mod))%mod;
	 }else{
	 	sp=((((j+1)/2)%mod)*((j+2)%mod))%mod;
	 }
	ll le= 5*(( (((l+5)*l4)%mod)*lucas(j+6))%mod) + 35*(((((l+3)*sp)%mod)*lucas(j+4))%mod) + 126*(((l+1)*lucas(j+2))%mod);
	ll ri= 150*((l4*fib2(j+5))%mod) + 5*56*((sp*fib2(j+3))%mod) + 252*fib2(j+1);
    // ll le= 5*(( (((l+5)*l4)%mod)*lucas(j+6))%mod) + 35*(((((l+3)*l2)%mod)*lucas(j+4))%mod) + 126*(((l+1)*lucas(j+2))%mod);
    // ll ri=150*((l4*fib2(j+5))%mod) + 5*56*((l2*fib2(j+3))%mod) + 252*fib2(j+1);
    return (le+ri)%mod;
}

int main(){
    ll t,i,j,k,l,m;
    ll  n;
    clock_t start =clock();
    // mod=1748*N;
    // cerr <<  (coef3(-6)) << endl;
    // exit(0);
    // for (i = 2,fib[0]=0,fib[1]=1; i < 100; ++i)
    // {
    //   fib[i]=fib[i-1]+fib[i-2];
    // }

    scanf("%lld",&t);
    // for (i = 0; i < 30; ++i)
    // {
    //   cout << i << " " << coef3(i) <<" "<<  (coef3(i)/N)%100 << endl;
    // }

    while(t--){
      scanf("%lld %lld",&m,&n);
      memFib.clear();
      mod=m*ll(N) ;
      // mod=m*ll(18750) ;
      // cout << (coef3(n-3)+coef3(n-9)+3*coef3(n-5)+3*coef3(n-7))<< endl;
      // ll ans=(((coef3(n-3)+coef3(n-9)+3*coef3(n-5)+3*coef3(n-7))%mod)/N)%m; 
      ll ans=( ((coef3(n-3)+coef3(n-9)+3*coef3(n-5)+3*coef3(n-7))%mod)/N )%m;  
      	// cerr << "forffdsgfs "<< n << " " << m << endl;
      // cerr << coef3(n-3)<<" "<<coef3(n-9)<<" " <<coef3(n-5)<<" " <<coef3(n-7)<< endl;
      // ll ans=(((coef3(n-3)+coef3(n-9)+3*coef3(n-5)+3*coef3(n-7))%mod)/18750)%m;  
      printf("%lld\n", (m+((6*ans)%m))%m );
    }

    // for (int te = 3; te < 20; ++te)
    // {
	   //  ll ans=(coef(te-3)+coef(te-9)+3*coef(te-5)+3*coef(te-7));
	   //  cout<< "final " << te << " " << ans << endl;
    // }

    // while(t--){
    //     scanf("%d%d",&n,&m);

        

    //     printf("%d\n", n);
    // }
    // cerr <<"time: "<< double((clock()-start))/CLOCKS_PER_SEC << endl;
    return 0;
}