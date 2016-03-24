#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
// #define DD ios_base::sync_with_stdio(false)
#define maxx 10001
using namespace std;
typedef long long ll;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline putchar_unlocked(char ch) { return putchar(ch);  }
#endif
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

char buf[11];int ix; 
inline void writeInt(int x) {
     ix = 10;
     buf[10] = '\0';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[++ix] != '\0');
}

struct pr
{
	ll i,val;
};

bool compare(pr a, pr b){
	return a.i<=b.i;
}

int main(){
	register ll t,l,n,m,p,a,b;
	int i,j;
	scanf("%lld%lld%lld",&n,&m,&p);
	// printf("%lld %lld%lld\n",n,m,p );

	map< ll,ll > v[n+1];

	while(p--){
		scanf("%lld%lld",&a,&b);
		// printf("%lld %lld\n",a,b );
		v[a][b]=v[a][b]+1;
	}

	ll ans[n+1];

	for (i = 1; i <= n; ++i)
	{
		pr temp[m+1];
		map<ll,ll>::iterator iii=v[i].begin();

		j=1;
		for (map<ll,ll>::iterator it=v[i].begin(); it!=v[i].end(); ++it,j++){
			temp[j].i=it->first;
			temp[j].val=it->second;
		}
		sort(temp+1,temp+(v[i].size()+1),compare);

		bool g=true;
		// cout<<" "<<i;;
		j = v[i].size();
		if(j>0){
			if(temp[j].i==m or temp[j].val<=1){j--;}
			else {j=0; g=false; }
		}
		for (  ; j >0 ; j--)
		{
			// cout<<" cdsfds: "<<j<<" "<<temp[j].i << " " << temp[j].val <<" "<< (temp[j].i!=temp[j+1].i-1 and temp[j].val>1); 
			if((temp[j].i!=temp[j+1].i-1 and temp[j].val>1) or 
				(temp[j].i==temp[j+1].i-1 and temp[j].val-temp[j+1].val>1) ) {g=false; break; }
		}
		// cout<<endl;
		int tel=0;
		if(v[i][m]){tel+=v[i][m]; }
		if(v[i][1]){tel-=v[i][1]; }
		ans[i]=g?(m-1+(v[i].size()>0?tel:0)):-1;


	}
	

	for (i = 1; i <= n; ++i)
	{
		printf("%lld\n",ans[i] );
	}
	
	return 0;
}