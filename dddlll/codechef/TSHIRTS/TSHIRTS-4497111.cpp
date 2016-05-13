#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define DD ios_base::sync_with_stdio(false)
#define LMT 2049
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;
bool lend;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char ch) { return putchar(ch);  }
#endif
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57)  ;c = getchar_unlocked()){
        if (c=='\n')
        {
            lend=true;
            x=-1;
            return;
        } 
    }
    for(;c>47 && c<58;c = getchar_unlocked() ) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if (c=='\n')
    {
        lend=true;
    }
}

char buf[11];int ix; 
inline void writeInt(int x) {
     ix = 10;
     buf[10] = '\0';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[++ix] != '\0');
}

inline int domod(int g){
	if (g>mod)return g-mod;
	return g;
}

int main() {
    //ios_base::sync_with_stdio(false);
    int t,n,i,j,k,l,val;
    r(t);
    while (t--) {
    	clock_t start=clock();
        r(n);
        const int n2=(1<<n); 
    	int b[n2],a[101][n2];
        for ( j =b[0]= 1; j < n2; ++j)
        {
            b[j]=0;
        }
        for (i = 0; i < 101; ++i)
        {
            for (j = 0; j <n2 ; ++j)
            {
                a[i][j]=0;
                
            }
            a[i][0]=1;
        }

        vector<int> v[101];
        for (i = 1; i <=n; i++) {
            for (lend=false;!lend ; ) { 
                r( j);
                if(j==-1)break;
                v[j].push_back(i-1);
           }
        }

        for (i = 1; v[i].size()==0; ++i);
		// cout<< l << " "<< i << " =============================" << endl;
		// cout << "time2: "<< (double(clock()-start)/CLOCKS_PER_SEC) << " sec " << endl;
	    // start = clock();
        for (l=i-1; i < 101; ++i)
        {
        	if (v[i].size()==0 )continue;
            int size=v[i].size();
            for ( j = n2-1; j >0;j--){
                a[i][j]=a[l][j];
            }
    		for (k = 0; k < size ; ++k)
    		{
        		int pr=1<<v[i][k];
                for ( j = n2-1; j >=0;){
                    if(a[l][j]==0){
                        if(j&pr){
                            j-=pr;
                        }else{
                            j--;
                        }
                        continue;
                    }
        			if ( (j&pr)==0)
        			{
        				val=j|pr;
        				a[i][val]+=a[l][j];
        				if (a[i][val]>mod)a[i][val]-=mod;
                        j--;
                    }else{
                        j-=pr;
                        // j--;

                    }
        		}
            }
            l=i;
        }
		// for ( i = 0; i < 101; ++i)
  //       {
  //       	if (v[i].size()==0)continue;
  //       	for ( j = 0; j < n2 ;  ++j)
  //       	{
  //               cout << a[i][j]<< "  ";
  //       	}
  //       	cout << endl;
  //       } 

        // cout << 2*((1<<n)-1) << endl;
        printf("%d\n", a[l][n2-1] );
   		// exit(0);   	 
	   // cout << "time: "<< (double(clock()-start)/CLOCKS_PER_SEC) << " sec " << endl;
	   // start = clock();
   }
   return 0;
}