#include<cstdio>
#include<cstring>
using namespace std;
int r; char a[100000];
int arr[26];int li[]={0,15,30,40};//c=2 and s=18

int getchar_unlocked()  {return getchar();}

int main(){
	int t,i,j,l;register char ch;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&r);
		scanf("%s",a);l=strlen(a);
		arr[3]=arr[19]=0;
		for(i=arr[2]=arr[18]=0;i<r;i++){
			j=a[i]-'A';
			arr[j]++;
			if(arr[j]&4)  {arr[j+1]++;  arr[2]=0; arr[18]=0;  }
		}
		printf("%d-%d",arr[19],arr[3]);
		if(arr[2]==0 && arr[18]==0) printf("\n");
		else printf(",%d-%d\n",li[arr[18]],li[arr[2]]);
	}
	return 0;
}