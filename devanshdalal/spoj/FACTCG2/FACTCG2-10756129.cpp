#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
using namespace std;
typedef long long ll;
using namespace std;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char ch) { return putchar(ch);  }
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

int fact[maxx]={0};

inline void getPrimes(int n){
  fill(fact,fact+n,0);
  fact[1]=fact[0]=1;
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (register int i = 2; i * i <= n; i++)
    if (prime[i]) {
		for (register int j = i * i; j <= n; j += i){
			prime[j] = false;
			if(fact[j]==0)fact[j]=i;
		}
	}
}

int main(){
	DD;
	register int i,j,m,q,l,n;
	n=maxx-1;
	getPrimes(n);
	string tmp;
	//while(getline(cin, tmp)){
	while(scanf("%d",&m) > 0){
		//m=atoi(tmp.c_str());
		if(m<=0)break;
		vector<int> fa;vector<int> num;
		n=m;
		putchar_unlocked('1');
		for(i=0;m!=1;){
			l=0;
			q=m;
			if(fact[q]==0)fact[q]=q;
			while(m%fact[q]==0){
				l++;
				m/=fact[q];
			}
			while(l!=0){
				putchar_unlocked(' ');
				putchar_unlocked('x');
				putchar_unlocked(' ');
				writeInt(fact[q]);
				l--;
				//~ fa.push_back(fact[q]);
				//~ num.push_back(l);
			}
		}
		if(m!=1){
			putchar_unlocked(' ');
			putchar_unlocked('x');
			putchar_unlocked(' ');
			writeInt(fact[q]);
			//~ fa.push_back(m);
			//~ num.push_back(1);
		}
		//~ putchar_unlocked('1');
			//~ for(i=0;i<fa.size();i++){
			//~ while(num[i]>0){
				//~ putchar_unlocked(' ');
				//~ putchar_unlocked('x');
				//~ putchar_unlocked(' ');
				//~ writeInt(fa[i]);
				//~ num[i]--;
			//~ }
		//~ }
		putchar_unlocked('\n');
	}
	return 0;
}
