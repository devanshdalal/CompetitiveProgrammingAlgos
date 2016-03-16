#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>
typedef long long ll;
using namespace std;
#define ma 100100
char a[ma];

int getchar_unlocked() { return getchar(); }
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
}

char buf[21];int ix;
int putchar_unlocked(char ch) { return putchar(ch);  } 
inline void writeL(ll x) {
     ix = 20;
     buf[20] = '\n';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[ix++] != '\n');
}

int link2[26];
struct sot{
	int val,co;
};

bool operator<(sot a, sot b) {
        return a.co < b.co?1:(a.co == b.co? a.val<b.val :false);
}

bool operator==(sot const &a, sot const &b) { 
	return a.co == b.co and a.val==b.val;
}

int cmp(sot a,sot b){
	return a.co<b.co?1:(a.co==b.co?0:-1);
}

bool dict[26][26];
char app[26];

int main(){
	int t,i,j,k,p,q,x1,x2,y1,y2,n;
	r(t);
	while(t--){
		char arr[300];//[300];
		cin>>arr;
		char b[150000];
		char ter;
		cin.get(ter);
		cin.get(ter);
		i=0;
		while(ter!='\n'){
			b[i++]=ter;
			cin.get(ter);
		}
		int to=0;
		bool av[26];
		b[i]='\0';
		x1=strlen(b);
		sot pri[26];
		for(i=0;i<26;i++){
			pri[i].co=0;
			pri[i].val=i;
			av[i]=0;
			link2[i]=-1;
			app[i]='?';
		}
		for(i=0;i<x1;i++){
			if(b[i]>96 and b[i]<123){
				pri[b[i]-97].co++;
				if(!av[b[i]-97]){
					av[b[i]-97]=true;
					app[to++]=b[i];
				}
			}else if(b[i]>64 and b[i]<91){
				pri[b[i]-65].co++;
				if(!av[b[i]-65]){
					av[b[i]-65]=true;
					app[to++]=b[i]+32;
				}
			}
		}
		for(i=0;i<to;i++){
			link2[app[i]-97]=i;
		}
		stable_sort(pri,pri+26);
		char *c=new char[x1+1];
		int link[26];
		for(i=0;i<26;i++){
			link[pri[i].val]=i;
		}
		//~ for(i=0;i<26;i++){
			//~ cout<<char(i+97)<<"-"<<arr[link[i]]<<"/"<<pri[link[i]].co<<"|";
		//~ }cout<<endl;
		//~ cout<<"b= "<<b<<endl;
		for(i=0;i<x1;i++){
			if(b[i]>96 and b[i]<123){
				c[i]=arr[link[b[i]-97]];
			}else if(b[i]>64 and b[i]<91){
				c[i]=arr[link[b[i]-65]]-32;
			}
			else c[i]=b[i];
		}
		c[x1]='\0';
		printf("%s\n",c);
		free(c);
	}
	return 0;
}