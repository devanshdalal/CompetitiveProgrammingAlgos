#include<cstdio>
#include<cstring>
using namespace std;

//inline int getchar_unlocked(){return getchar();       }
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

int main(){
	int t,n,i,a,b,ao,bo,c,ans;
	scanf("%d",&t);
	while(t--){
		ans=0;
		ao=0;bo=0;
		fastRead_int(n);fastRead_int(a);fastRead_int(b);
		for(i=0;i<n;i++){
			ao+=(a%2)  ;  bo+=(b%2);
			a=a/2;  b=b/2;
		}
		if(ao+bo>n) c=2*n-(ao+bo);
		else c=ao+bo;
		for(i=0;i<n;i++){
			if(c) { ans=(ans<<1)+1;  c--;    }
			else { ans<<=1;   }
		}
		printf("%d\n",ans);
	}
	return 0;
}