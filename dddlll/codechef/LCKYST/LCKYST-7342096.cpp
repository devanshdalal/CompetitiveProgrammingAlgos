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

int main(){
    int t,n,m;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	ll b =1,a;
    	cin >> a;
    	while(a%10==0){
    		a/=10;
    		b*=10;
    	}
    	while(a%25==0){
    		a/=25;
    		b*=100;
    	}
    	if (a%5==0)
    	{
    		a/=5;
    		b*=20;
    	}
    	cout << (a*b) << endl;
    }

    return 0;
}