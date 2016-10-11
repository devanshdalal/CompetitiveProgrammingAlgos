#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<cassert>
#include<ctime>
// #include<time>
#define fastio ios_base::sync_with_stdio(false)
#define MAX 10000001
#define eps 0.0000001
#define equal(x,y) abs(x-y)<eps
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define pr(p) {cerr << p.x << "," << p.y << " " << #p << endl;}
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
const ll mod = 1000000007;

std::map<string, int> map1;

int main(){
    int t,n,m;

    map1["blue"]=1;
    map1["yellow"]=2;
    map1["green"]=3;
    map1["black"]=4;
    map1["orange"]=5;
    map1["red"]=6;
    
    cin >> t ;
    char color[20];
    int s[6];
    while(t--){
    	for (int i = 0; i < 6; ++i)
    	{
    		string color;
    		cin >> color ;
    		s[i]=map1[color];
    	}
    	if ( (s[0]==s[2] and s[2]==s[4]) or (s[0]==s[2] and s[2]==s[5]) or (s[1]==s[2] and s[2]==s[4])
    	or (s[1]==s[2] and s[2]==s[5]) or (s[0]==s[3] and s[3]==s[4]) or (s[0]==s[3] and s[3]==s[5])
    	or (s[1]==s[3] and s[3]==s[4]) or (s[1]==s[3] and s[3]==s[5])  )
    	{
    		cout << "YES\n";
    	}else{
    		cout << "NO\n" ; 
    	}
    }

    return 0;
}