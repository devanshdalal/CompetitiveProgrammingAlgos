#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define sf scanf
#define pf printf
using namespace std;
typedef long long ll;
int n,k,m;char a[2000009],b[2000009];

ll modPow(int X, int Y)
{
    ll Temp,Ans;ll M=(ll)pow(10,k);
    if(!Y) return 1;
    Temp = modPow(X,Y/2);
    Ans = (Temp*Temp)%M;
    if(!(Y&1)) return Ans;
    else return (X*Ans)%M;
}

int arr[4]={0,0,0,0};

int main(){
	int t,i,j=0,te,pos=0;int done=1;
	scanf("%d",&n);
	scanf("%s",&a);
	scanf("%s",&b);int N=2*n;
	for(i=0;i<N;i++){
		if(a[i]=='1' and b[i]=='1')arr[0]++;
		else if(a[i]=='1' and b[i]=='0')arr[1]++;
		else if(a[i]=='0' and b[i]=='1')arr[2]++;
		else arr[3]++;
	}
	int fi[3],turn=1;
	fi[1]=fi[2]=arr[0]/2;
	if(arr[0]&1){
		fi[1]++;
		turn=2;
	}
	if(arr[1]<=arr[2]){
		fi[1]+=arr[1] ;
		fi[2]+=arr[1] + (arr[2]-arr[1])/2 ;
		arr[2]-=arr[1];
		if(arr[2]&1){
			fi[turn]+=(turn-1);
			turn=1 + (turn%2);
		}
	}
	else{
		fi[1]+=arr[2] + (arr[1]-arr[2])/2;
		fi[2]+=arr[2]  ;
		arr[1]-=arr[2];
		if(arr[1]&1){
			fi[turn]+=(turn==2)?0:1;
			turn=1 + (turn%2);
		}
	}
	//cout<<fi[1]<<" "<<fi[2];
	if(fi[1]==fi[2])printf("Draw");
	else if(fi[1]>fi[2])printf("First");
	else printf("Second");
	return 0;
}