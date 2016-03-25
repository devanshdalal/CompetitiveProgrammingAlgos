#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;

// Devansh Dalal's Code

char aa,bb;
char * arr=new char[1100000];
int t,i,j,n,q,l;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		map<char, char> mymp;
		for(i=0;i<n;i++){
			bb=aa='\n';
			while(aa=='\n' or aa==' ')aa=getchar_unlocked();
			while(bb=='\n' or bb==' ')bb=getchar_unlocked();
			mymp[aa]=bb;
		}

		scanf("%s",arr);
		bool st1=false,en1=false,has=false;
		l=strlen(arr);
		int start=0,end=l-1;
		for (i = 0; i < l; ++i)
		{
			if(mymp[arr[i]]){ arr[i]=mymp[arr[i]];  }
			if (!st1 and arr[i]=='0'){ start=i+1;  }
			else st1=true;
			if(arr[i]=='.')has=true;
		}
		if(start==-10000000)break;
		if(start==l)start=l-1;
		for (i = l-1; i>=0 and has  ; i--)
		{
			if(arr[i]=='0')end=i-1;
			else if(arr[i]=='.'){ end=i-1; break;}
			else break;
		}
		if(start>end and arr[start]=='.' ){arr[start]='0';end=start;}
		for (i = start; i <= end ; ++i)
		{
			putchar_unlocked(arr[i]);
		}
		putchar_unlocked('\n');

	}
	return 0;
}