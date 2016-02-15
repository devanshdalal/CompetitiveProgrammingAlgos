#include<cstdio>
//#import<sstream>
#include<algorithm>
int ii;char buf[11]; 
int ta[100][100];
//int getchar_unlocked()  {return getchar();}
inline void fastRead_int(int &x) {
	register int c = getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

//int putchar_unlocked(char ch) { return putchar(ch);  }
inline void writeInt(int x) 
{
     ii = 10;
     do 
     {
        buf[--ii] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do 
     {
        putchar_unlocked(buf[ii]);
     } while (buf[ii++] != '\n');
}

int main(){
	buf[10] = '\n';
	int t,i,j,n;
	scanf("%d",&t);
	while(t--){
		fastRead_int(n);
		for(i=0;i<n;i++){
			for(j=0;j<=i;j++){
				fastRead_int(ta[i][j]);
			}
		}
		for(i=n-1;i>0;i--){
			for(j=i;j>0;j--){
				ta[i-1][j-1]+=std::max(ta[i][j-1],ta[i][j]);
			}
		}
		writeInt(ta[0][0]);
	}
	return 0;
}