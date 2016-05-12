#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<bitset>
#include<vector>
#include<stack>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10001
using namespace std;
typedef long long ll;
using namespace std;

#ifdef _WIN32
inline int getchar_unlocked() { return getchar(); }
inline putchar_unlocked(char ch) { return putchar(ch);  }
#endif
void r(int &x){
    register unsigned int c = getchar_unlocked();
    x = 0;int neg=0;
    for(;(c<48 || c>57) && c!='-';c = getchar_unlocked());
    if(c=='-'){neg=1; c=getchar_unlocked(); }
    for(;c>47 && c<58;c = getchar_unlocked() ) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg)x=-x;
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

int cum[1002][1002];
bool a[1002][1002];
int ans[1002][1002];

// The main function to find the maximum rectangular area under given
// histogram with n bars
int height,width,ht,wt;
inline int getMaxArea(vector<int> & hist, int n,int maxval){
	//int * hist=cum[ii];
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || min(maxval,hist[s.top()]) <= min(maxval,hist[i]) )
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
           	height=min(maxval,hist[tp]);
 			//width=(s.empty() ? i : i - s.top() - 1);
 			area_with_top = height * (s.empty() ? i : i - s.top() - 1);
            // update max area, if needed
            if (max_area < area_with_top){
                max_area = area_with_top;
                ht=height;
                //wt=width;
                //cout<<"height: "<<ht<<" "<<wt<<endl;
            }
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        height=min(maxval,hist[tp]);
		//width=(s.empty() ? i : i - s.top() - 1);
		area_with_top = height * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top){
            max_area = area_with_top;
            ht=height;
            //wt=width;
            //cout<<"height: "<<ht<<" "<<wt<<endl;
        }
    }
    return max_area;
}
	
/*inline int find(int rx,int ry,int lx,int ly){
	return cum[rx][ry]+cum[lx-1][ly-1]-cum[lx-1][ry]-cum[rx][ly-1];
}*/

int main(){
	//~ DD;
	register int t,i,j,N,M,K,p,pp,Q;
	r(N); r(M);//scanf("%d%d",&N,&M);
	for(i=0;i<=N;i++){
		ans[i][0]=cum[i][N+1]=cum[i][0]=0;
	}
	for(i=0;i<=M;i++){
		ans[0][i]=cum[M+1][i]=cum[0][i]=0;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			ans[i][j]=0;
			r(pp);//scanf("%d",&pp);
			a[i][j]=pp;
		}
	}
	for(i=N;i>0;i--){
		for(j=M;j>0;j--){
			if(a[i][j]){
				cum[i][j]=0;
			}else{
				cum[i][j]=1+cum[i+1][j];
			}
		}
	}
	for(i=1;i<=N;i++){
        vector<int> vec;
        int nof=0;
        for(j=1;j<=M;j++){
            if(cum[i][j]!=0){
                vec.push_back(cum[i][j]);
                nof=0;
            }else{
                if(nof==0){
                    vec.push_back(0);
                    nof++;
                }
            }
        }
		for(j=N;j>=i;){
			int area=getMaxArea(vec,vec.size(),j-i+1);
			/*if(i==4){
				cout<<area<<endl;
				for(pp=1;pp<=M;pp++)cout<<cum[i][pp]<<" ";cout<<endl;
			}*/
			ans[i][j]=max(ans[i][j],area);
			while(j>=i+ht-1){
				ans[i][j]=max(ans[i][j],area);
				j--;
			}
			//j--;
		}
	}
	for(i=N;i>=0;i--){
		for(j=i;j<=N;j++){
			int macx=max(ans[i][j-1],ans[i+1][j]);
			if(macx>ans[i][j])ans[i][j]=macx;
		}
	}
	r(Q);//scanf("%d",&Q);
	while(Q--){
		r(p); r(pp);//scanf("%d%d",&p,&pp);
		writeInt(ans[p][pp]);
		//printf("%d\n",ans[p][pp]);
		putchar_unlocked('\n');
	}
	return 0;
}