#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

ll mod=1000000007;
/*
	ok , this was an easy problem , but it appears to be difficult.
*/

// inline char getchar_unlocked(){return getchar();}

void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

inline ll mpow(ll b, ll e)
{
    ll result = 1;
    while (e )
    {
        if (e&1)
            result = (result * b) % mod;
        e = e >> 1;
        b = (b * b) % mod;
    }
    return result;
}

ll cou[101],rem[101][199];

int main(){
	 ios_base::sync_with_stdio(false);
	int t,i,j,n,ai;
	cin>>t;
	while(t--){
		ll c_t=0;
		cin >> n;
		for (i = 0; i < 101; ++i)
		{
			cou[i]=0;
			for (j = 0; j < 199; ++j)
			{
				rem[i][j]=0;
			}
		}
		for (i = 0; i < n; ++i)
		{
			cin>>ai;
			for (j = 1; j < 101; ++j)
			{
				if (cou[j]==0)continue;
				int d=99+ai-j;

				c_t+=rem[j][d];

				rem[ai][d]+=rem[j][d];

				rem[ai][d]+=cou[j];
				if(rem[ai][d]>mod)rem[ai][d]%=mod;

				c_t+=cou[j];
			}	

			cou[ai]++;
			c_t++;
			if(c_t>mod)c_t%=mod;
		}
		
		ll ans= (mod+mpow(2,n) - c_t-1) % mod;
		cout<< ans <<endl;
	}
	return 0;
}