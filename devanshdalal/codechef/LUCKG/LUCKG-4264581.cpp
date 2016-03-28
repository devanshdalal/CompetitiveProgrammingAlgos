#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define nnn ios_base::sync_with_stdio(false)
#define LMT 1001
using namespace std;

int n,m,a[LMT],cycles[LMT],lth[LMT],end[LMT],*ans[LMT],*temp[LMT];
bool vis[LMT];
int ind=1;

inline void gen3(int nx){
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < nx; ++i)
		{
			temp[(i+j)%nx][j]=ind++;
		}
	}
	for (int j = 3; j < m; ++j)
	{
		for (int i = 0; i < nx; ++i)
		{
			temp[(j&1?i:nx-i-1)][j]=ind++;
		}
	}
}

inline void gen4(int nx){
	if ( nx==3)
	{
		ind--;
		temp[0][0]=ind+2; temp[0][1]=ind+4; temp[0][2]=ind+9; temp[0][3]=ind+11;
    	temp[1][0]=ind+3; temp[1][1]=ind+5; temp[1][2]=ind+6; temp[1][3]=ind+12;
    	temp[2][0]=ind+1; temp[2][1]=ind+7; temp[2][2]=ind+8; temp[2][3]=ind+10;
    	ind+=13;
	}else{
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < nx; ++i)
			{
				temp[(i+j)%nx][j]=ind++;
			}
		}
	}
	for (int j = 4; j < m; ++j)
	{
		for (int i = 0; i < nx; ++i)
		{
			temp[(j&1?i:nx-i-1)][j]=ind++;
		}
	}
}

inline void prt(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << ans[i][j] << " ";
		}
		if(i<n-1)cout << endl;
	}
}

bool check(int x,int y){
	int res=0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			res+=(ans[x][i]>ans[y][j]);
		}
	}
	return res>m*m/2;
}

bool test(){
	memset(vis,0,sizeof(vis));
	for (int i = 0; i < n; ++i)
    {
        if(!vis[i]){
            for(int j=i;!vis[j];j=a[j]){
                vis[j]=true;
                if(check(j,a[j])==false){
                	cout << n << "-?????????????????????"<< m  << endl;
                	prt();
                	exit(0);
                }
            }
    	}
	}
}

int main(){
    int t,i,j,k,l,p,q;
    nnn;
    for (i = 0; i < LMT; ++i)
    {
    	ans[i]=new int[LMT];
    	temp[i]=new int[LMT];
    }
    cin >> t;
    while(t--){
    	cin >> n  >>  m;
    	for (i = 0; i < n; ++i)
    	{
    		cin >> a[i] ; 
    	}
        bool done=true;
        int noc=0;
    	memset(vis,0,sizeof(vis));
    	for ( i = 0; i < n; ++i)
        {
            if(!vis[i]){
            	int len=0;
                for(j=i;!vis[j];j=a[j]){
                    vis[j]=true;
                    cycles[j]=noc;
                    len++;
                }
                lth[noc]=len;
                end[noc]=j;
                noc++;
                if (len<=2 )
                {
                	done=false;
                	break;
                }
        	}
    	}
		if(m<=2){
        	done=false;
        }
    	if (done)
    	{
    		ind=1;
    		for ( i = 0; i < noc; ++i)
    		{
    			if (m%2==0)
    			{
    				gen4(lth[i]);
    			}else{
    				gen3(lth[i]);
    			}
    			k=end[i];
    			for (j= lth[i]; j>=0; j--)
    			{
    				swap(temp[j],ans[k]);
    				k=a[k];
    			}
    		}
    		here:
    		prt();
    	}else{
    		cout << "No Solution" ;
    	}
    	if(t)cout << endl;
    }
    return 0;
}