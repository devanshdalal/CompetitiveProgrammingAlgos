#include<iostream>
# include<cstdio>
# include<algorithm>
# include<cstring>
# include<vector>
# include<queue>
# include<bitset>
using namespace std;
typedef long long ll;
bool visited[120];

struct node{
	int x,y;
};
vector< node > v;

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

int main(){
	int t,tt,i,j,k,beg,end,x,y;
	r(t);
	node pi;
	while(t--){
		r(tt);r(pi.x);r(pi.y);
		if(tt==1){
			v.push_back(pi);
		}
		else{
			memset(visited,false,sizeof(visited));
			node b;bool d=false;
			queue<int> Q;
			pi.x--;pi.y--;
			Q.push(pi.x);
			while(!Q.empty()){
				k=Q.front(); Q.pop();
				visited[k]=true;
				if(k==pi.y){d=true;cout<<"YES\n"; break;}
				for(i=0 ; i< v.size() ; ++i ){
					if(visited[i]==false && ((v[i].x<v[k].x && v[k].x<v[i].y) || (v[i].x<v[k].y && v[k].y<v[i].y) )){
						Q.push(i);
					}
				}
			}
			if(!d)cout<<"NO"<<endl;
			
		}
	} 
	return 0;
}