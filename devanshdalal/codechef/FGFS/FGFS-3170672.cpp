#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define PI 3.14159265358979323846264338327950288419716939937510
#define eps 0.0000001
using namespace std;
typedef long long ll;
typedef double d;
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

struct node{
	int s,f;//,room;
};

bool comf(node a,node b){
	return a.f<b.f;
}

bool coms(node a,node b){
	return a.s<b.s;
}

inline int scedule(vector<node> &a){
	sort(a.begin(),a.end(),comf);
	//~ for(int k=0;k<a.size();k++){
		//~ cout<<a[k].s<<"-"<<a[k].f<<" ";
	//~ }cout<<endl;
	int i=a.size()-1,j,ans=0;
	for(;i>=0;i=j){
		ans++;
		j=i-1;
		while(j>=0 and a[j].f>a[i].s){
			if(a[j].s>a[i].s)i=j;
			j--;
		}
	}
	//~ cout<<"ans:"<<ans<<endl;
	return ans;
}

int main(){
	//DD;
	register int t,i,j,n,k,s,f,p;
	r(t);
	while(t--){
		map<int ,int> as;
		r(n); r(k);
		vector< vector<node> > gg;
		gg.resize(n+2);
		for(i=0,j=0;i<n;i++){
			r(s); r(f); r(p);//scanf("%d%d%d",&s,&f,&p);
			node temp;
			temp.s=s;     temp.f=f;
			int yu=as[p];
			if(yu){
				gg[yu].push_back(temp);
			}else{
				as[p]=++j;
				gg[j].push_back(temp);
			}
		}
		int ans=0;
		for(i=1;i<=j;i++){
			ans+=scedule(gg[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}