//#include <iostream>
//#include <algorithm>
#include <stdio.h>
//#include <queue>
//#include <cmath>
//#include <cstring>
//typedef long long ll;
//using namespace std;
#define ma 65000
int n,p;

int r(int x){
    register unsigned int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    return x;
}

inline int max(int a, int nb){
return a<nb?nb:a;
}
int main(){
	int t,i,j,k,q,x1,y1,z1,l;
	t=r(t);
	while(t--){
		n=r(n);p=r(p);
		char arr[ma],brr[ma];
		scanf("%s%s",arr,brr);
		int n2=n*n;
		int cou[n+1][n+1][n+1];
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				cou[i][j][0]=cou[i][0][j]=cou[0][i][j]=0;
		for(i=1;i<=n;i++){
			int pla[n+1][n+1];
			for(j=0;j<=n;j++) pla[j][0]=pla[0][j]=0;
			for(j=1;j<=n;j++){
				int mac=0;
				for(k=1;k<=n;k++){
					if(arr[(i-1)*n2+(j-1)*n+(k-1)]==brr[(i-1)*n2+(j-1)*n+(k-1)]){
						mac++;
					}
					pla[j][k]=pla[j-1][k]+mac;
					cou[i][j][k]=cou[i-1][j][k]+pla[j][k];
				}
			}
		}
		int curmax=0;
		int an[41];
		for(i=0;i<41;i++)an[i]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++){
					for(l=1;max(max(i,j),k)+l<=n;l++){
						if(l+1<curmax)continue;
						x1=i+l; y1=j+l; z1=k+l;
						int dan=cou[x1][y1][z1]-(cou[i-1][y1][z1]+cou[x1][j-1][z1]+cou[x1][y1][k-1])+(cou[i-1][j-1][z1]+cou[x1][j-1][k-1]+cou[i-1][y1][k-1])-cou[i-1][j-1][k-1];
						if(  (l+1)*(l+1)*(l+1)*p <= dan*100 ){
							//~ cout<<dan<<" => "<<i<<"|"<<j<<"|"<<k<<" l= "<<l<<" cuboid:"<<endl;
							//~ for(x1=0;x1<=l;x1++){
								//~ for(y1=0;y1<=l;y1++){
									//~ for(z1=0;z1<=l;z1++){
										//~ cout<<arr[(i+x1-1)*n2+(j+y1-1)*n+(k+z1-1)]<<"-"<<brr[(i+x1-1)*n2+(j+y1-1)*n+(k+z1-1)]<<"|";
									//~ }
									//~ cout<<" ";
								//~ }
								//~ cout<<"\t\t";
							//~ }
							//~ cout<<endl;
							//~ cout<<p <<" "<< (100*dan)/( (l+1)*(l+1)*(l+1)) <<endl;
							an[l+1]++;
							curmax=l+1;
						}
					}
				}
			}
		}
		//~ for(i=1;i<=n;i++){
			//~ for(j=1;j<=n;j++){
				//~ for(k=1;k<=n;k++){
					//~ cout<<cou[i][j][k]<<"|";
				//~ }
				//~ cout<<endl;
			//~ }
			//~ cout<<endl;
		//~ }
		an[1]=p==0?n2*n:cou[n][n][n];
		for(i=n;i>0;i--){
			if(an[i]>0){
				break;
			}
		}
		if(i>0)printf("%d %d\n",i,an[i]);
		else printf("-1\n");
	}
	return 0;
}