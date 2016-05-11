#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,m;
char a[1000][1000];
bool vis[1000][1000];

ll d[1000][1000];


int main() {
	
	// your code here
	ios_base::sync_with_stdio(0);
	
	cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> a[i];
            /*for(int j=0;j<n;j++){
                vis[i]
            }*/
            //fill(vis[i],vis[i]+m,0);
        }
        
        priority_queue< pair<int,pair<int,int> >, vector< pair<int ,pair<int,int> > > , std::greater< pair<int ,pair<int,int> > >  > pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1'){
                    d[i][j]=0;
                    //vis[i][j]=1;
                    pq.push(make_pair( 0 ,make_pair(i,j) ) );
                }else{
                    d[i][j]=100000000L;
                }
                vis[i][j]=0;
            }
        }
        
        int i,j,cost;
        
        while(!pq.empty()){
            pair<int,pair<int,int> > tp = pq.top(); pq.pop();
            cost=tp.first; i=tp.second.first; j=tp.second.second;
            if(vis[i][j])continue;
            vis[i][j]=1;
            d[i][j]=cost;
            if( i<n-1 and !vis[i+1][j] ){
                pq.push(make_pair( cost+1 ,make_pair(i+1,j) ) );
            }
            if( i>0 and !vis[i-1][j] ){
                pq.push(make_pair( cost+1 ,make_pair(i-1,j) ) );
            }
            if( j<m-1 and !vis[i][j+1] ){
                pq.push(make_pair( cost+1 ,make_pair(i,j+1) ) );
            }
            if( j>0 and !vis[i][j-1] ){
                pq.push(make_pair( cost+1 ,make_pair(i,j-1) ) );
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        
    }

	

	return 0;
}