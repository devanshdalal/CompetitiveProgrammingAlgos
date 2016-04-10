#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int M= 1000001;

const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int ind[168];

struct node{
	int val,rep;
};int last;

int main(){
	int t,n,i,j,k,te;
	scanf("%d",&t);
	while(t--){
		node arr[11];
		for(i=0;i<168;i++)ind[i]=0;
		last=0;
		scanf("%d",&n);
		int ans=1;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			for(k=0;k<168 && j>1;k++){
				while(j>1 && j%pr[k]==0){
					ind[k]++;
					j=j/pr[k];
					//for(te=0;te<10;te++)cout<<te<<"->"<<index[te]<<"   ";cout<<endl;
				}
			}
			if(j>1000){
				bool done=false;
				for(k=0;k<last;k++){
					if(arr[k].val==j){done=true;arr[k].rep++;}
				}
				if(!done){
					arr[last].val=j;arr[last++].rep=1;
				}
			}
		}
		for(i=0;i<168;i++){
			ans*=(1+ind[i]);
		}
		for(i=0;i<last;i++){
			ans*=(1+arr[i].rep);
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
#define BUF 4096
char ibuf[BUF];
int ipt = BUF; 
int readInt() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}
*/