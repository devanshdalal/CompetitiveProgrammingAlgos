#include<cstdio>
#include<cstring>
using namespace std;
char a[100000];
int order[200];
int rep[200];

int main(){
	int i,j,l,counter=0;
	scanf("%s",&a); l=strlen(a);
	for(i=0;i<200;i++) {  rep[i]=0;}
	for(i=0;i<l;i++){
		if(rep[a[i]]==0) order[counter++]=a[i];
		rep[a[i]]++;
	}
	for(i=0;i<counter;i++){ printf("%c%d",order[i],rep[order[i]]);    }
	
	return 0;
}