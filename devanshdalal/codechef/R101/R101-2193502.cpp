#include<cstdio>
#include<cstring>
char a[100000];
int arr[150]={0};

int getchar_unlocked(){ return getchar();}
inline void Read() {
   register int c = getchar_unlocked();
   for(; c<64 ; c = getchar_unlocked());  
   for(; c!='\n' || c==' ' ; c = getchar_unlocked()) {
        arr[c]++;
   }
}

int main(){
	int t,n,co=0;
	Read();
	char ch=getchar_unlocked();
	for(; ch=='\n' ; ch = getchar_unlocked());
	printf("%d\n",arr[ch]);
	return 0;
}