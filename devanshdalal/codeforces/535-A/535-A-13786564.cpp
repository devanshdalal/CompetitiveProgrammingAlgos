#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {std::cerr << #x << " = " << x << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

string f(int n){
	switch(n){
		case 0: return string("");
		case 2: return string("twenty");
		case 3: return string("thirty");
		case 4: return string("forty");
		case 5: return string("fifty");
		case 6: return string("sixty");
		case 7: return string("seventy");
		case 8: return string("eighty");
		case 9: return string("ninety");
	}
	return string("");
}

string g(int n){
	switch(n){
		case 0: return string("zero");
		case 1: return string("one");
		case 2: return string("two");
		case 3: return string("three");
		case 4: return string("four");
		case 5: return string("five");
		case 6: return string("six");
		case 7: return string("seven");
		case 8: return string("eight");
		case 9: return string("nine");
		case 10: return string("ten");
	}
	return string("");
}

string ten(int n){
	switch(n){
		case 11: return string("eleven");
		case 12: return string("twelve");
		case 13: return string("thirteen");
		case 14: return string("fourteen");
		case 15: return string("fifteen");
		case 16: return string("sixteen");
		case 17: return string("seventeen");
		case 18: return string("eighteen");
		case 19: return string("nineteen");
	}
	return string("");
}

int main(){
    ll t,n;
    std::ios_base::sync_with_stdio(0);


    std::cin >> n ;

    // for (int i = 0; i <=99; ++i)
    // {
    // 	n=i;
	    string ans;
	    
	    if (n<=10)
	    {
	    	ans = g(n);
	    }else if (10<n and n<20)
	    {
	    	ans=ten(n);
	    }else
	    {
	    	ans = f(n/10)+( n%10>0?"-"+g(n%10):string("") );
	    }

	    cout << ans << endl;
    // }


    return 0;
}