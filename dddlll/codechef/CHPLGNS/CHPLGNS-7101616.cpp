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

// const dbl PI = acos(-1);

struct point
{
    dbl x,y;
    point(){}
    point(dbl a,dbl b){
        x=a;
        y=b;
    }
};

point operator -(point p1,point p2){
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

point operator +(point p1,point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

point operator *(point p1,dbl val){
    p1.x *= val;
    p1.y *= val;
    return p1;
}


# define PI           3.14159265358979323846  /* pi */
# define TWOPI           2*3.14159265358979323846  /* 2pi */

double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > PI)
      dtheta -= TWOPI;
   while (dtheta < -PI)
      dtheta += TWOPI;

   return(dtheta);
}

struct poly
{
    point *list;
    int len,id;
};

poly a[100001];

int check1(poly s,point tp){
	point p1,p2;
    double angle=0.0;
    for (int i=0;i<s.len;i++) {
        p1 = s.list[i] - tp;
        p2 = s.list[(i+1)%s.len] - tp;
        angle += Angle2D(p1.x,p1.y,p2.x,p2.y);
    }
    // cerr << angle << endl;
    if (abs(angle) < PI)
        return 1;
    else
        return 0;
} 

bool compa(poly s, poly t){
    // dbg(s.id);
    // dbg(t.id);
    if(s.len>t.len)return !compa(t,s);
    point tp=t.list[2];
    int par=check1(s,t.list[0])+check1(s,t.list[1]);
    if(par==2)return 1;
    else{
    	int onemore=check1(s,t.list[2]);
    	if (par+onemore>=2)return 1;
    	else{
    		if(par+onemore==0)return 0;
    		return par+onemore+check1(s,(t.list[0]+t.list[1]+t.list[2])*(1.0/3.0) )>=2;
    	}
    }
    // return check1(s,t.list[1])+check1(s,t.list[2])+check1(s,(t.list[0]+t.list[1]+t.list[2])*(1.0/3.0) )>=2;
    // point p1,p2;
    // double angle=0.0;
    // for (int i=0;i<s.len;i++) {
    //     p1 = s.list[i] - tp;
    //     p2 = s.list[(i+1)%s.len] - tp;
    //     angle += Angle2D(p1.x,p1.y,p2.x,p2.y);
    // }
    // // cerr << angle << endl;
    // if (abs(angle) < PI)
    //     return 1;
    // else
    //     return 0;
}

bool compn(poly s, poly t){
    // dbg(s.id);
    // dbg(t.id);
    if(s.len>t.len)return !compn(t,s);
    point tp=t.list[2];
    return check1(s,t.list[2]);
}

int main(){
    int t,n,m;
    
    cin >> t ;
    while(t--){
        cin >> n;
        int sum=0;
        for (int i = 0; i < n; ++i)
        {
            cin >> m;
            sum+=m;
            a[i].len=m;
            a[i].id=i;
            a[i].list=new point[m];
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i].list[j].x >> a[i].list[j].y ;
            }
        }
        if(sum>10000)sort(a,a+n,compn);
        else sort(a,a+n,compa);
        int ans[n];
        for (int i = 0; i < n ; ++i)
        {
            ans[a[i].id]=i;
            free(a[i].list);
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";


    }

    return 0;
}