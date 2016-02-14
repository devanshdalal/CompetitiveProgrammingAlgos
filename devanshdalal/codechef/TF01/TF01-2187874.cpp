#include<cstdio>
using namespace std;
//int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int i,j,T,n,k;
int set[1001];
//bool subset[1001][1001];

bool isSubsetSum(int nn,int kk){
    if(nn==0 && kk!=0) return false;
    if(kk==0) return true;
    if(kk<set[nn-1]) return isSubsetSum(nn-1,kk);
    return isSubsetSum(nn-1,kk) || isSubsetSum(nn-1,kk-set[nn-1]);
}

int main() 
{ 
    scanf("%d",&T);
    while(T--)
    {
        fastRead_int(n); fastRead_int(k);
        for(i=0; i<n; i++) fastRead_int(set[i]);
        if(isSubsetSum(n,k)) printf("1\n");
        else printf("0\n");
    }
  return 0;
}