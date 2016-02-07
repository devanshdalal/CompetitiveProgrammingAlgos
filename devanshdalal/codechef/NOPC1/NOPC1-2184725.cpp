#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int getchar_unlocked(){ return getchar();}

inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0; 
    while (c < 33)
        c = getchar_unlocked(); 
    while (c != '\n') {
       str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    } 
    str[i] = '\0';
}



int main(){
	char M[40];char S[40];int i,j,m,s; bool f=false;
	fastRead_string(M);   m=strlen(M);
	fastRead_string(S);  s=strlen(S);
	for(m=m-1;m>=s-1;m--){
		for(i=m,j=s-1;(S[j]==M[i]);j--,i--){
			if(j==0) {f=true;  goto label;      }
			else if(i==0) {goto label;           }
		}
	}
	label: printf(f?"Y":"N");
return 0;
}