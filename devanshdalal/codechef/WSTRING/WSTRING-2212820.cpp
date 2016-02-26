#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[10000];
int first[26];
int second[26];
int third[26];
int fourth[26];
		
int maxx(int arr[]){
	int ma=0;
	for(int tw=0;tw<26;tw++){
		ma=max(ma,arr[tw]);
	}
	return ma;
}


int main(){
	int t,i,j,k,kk,l,fir,sec,thi,fou;bool sp;
	scanf("%d",&t);
	while(t--){
		int maximum=0;
		scanf("%s",&a); l=strlen(a);
		for(i=0;i<26;i++){ fourth[i]=0;third[i]=0;second[i]=0;first[i]=0;      }
		for(i=0;i<l;i++){
			if(a[i]=='#') continue;
			fourth[a[i]-'a']++;
		}
		//cout<<" "<< i<< " "<<endl;
		//cout<<" "<< maximum<< " "<<endl;
		if(a[0]=='#') i=1; else i=0;
		for(;i<l;i++){
			if(a[i]=='#'){
				if(a[i-1]=='#' and i>1 and a[i-2]=='#') continue;
				fir=maxx(first); sec=maxx(second);thi=maxx(third);fou=maxx(fourth);
				if(fir!=0 and sec!=0 and thi!=0 and fou!=0) maximum=max(fir+sec+thi+fou,maximum);
				//cout<<" "<<maxx(first) << " "<<maxx(second) <<" "<< maxx(third) <<" "<<maxx(fourth) <<endl;
				//cout<<" "<< maximum<< " "<<endl;
				for(kk=0;kk<26;kk++){first[kk]+=second[kk]; second[kk]=third[kk]; third[kk]=0;}
				}
			else{
				third[a[i]-'a']++;
				fourth[a[i]-'a']--;
			}
		}
		if(maximum<4) printf("0\n"); else printf("%d\n",maximum+3);
	}
	return 0;
}