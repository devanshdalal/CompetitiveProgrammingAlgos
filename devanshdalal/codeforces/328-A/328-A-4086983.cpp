#include<iostream>
# include<cstdio>
# include<algorithm>
# include<cstring>
# include<vector>
# include<queue>
# include<cmath>
# include<bitset>
using namespace std;
typedef long long ll;
bool visited[100001];
vector< int > v;

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

bool eq(double a,double b){
	//cout<<a<<","<<b<<endl;
	return a-b<0.000001 and b-a<0.000001;
}

typedef double d;

int near(d a){
	int r=floor(a);
	if(a-r<0.5)return r;
}

int check(int i,int j,int k,int l){
	if(i!=j and j!=0 and k!=l and l!=0 and  eq(d(j)/d(i),d(k)/d(j)) and eq(d(l)/d(k),d(k)/d(j)))return eq(d(near(d(l*l)/d(k))),d(l*l)/d(k))?near(d(l*l)/d(k)):42;
	return 42;
}

int main(){
	int t,tt,i,j,k,l,beg,end,x,y;
	scanf("%d %d %d %d",&i,&j,&k,&l);
	if(i-j==j-k and j-k==k-l){cout<<2*l-k;}
	else cout<<check(i,j,k,l);
	return 0;
}