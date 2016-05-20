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

const dbl PI = acos(-1);

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

inline dbl len2(point p1){
	return p1.x*p1.x + p1.y*p1.y;
}

inline dbl len(point p1){
	return sqrt(p1.x*p1.x + p1.y*p1.y);
}

point rotate(point p,dbl th){    // anti-clock 
	return point(p.x*cos(th*PI/180.0)-p.y*sin(th*PI/180.0),p.x*sin(th*PI/180.0)+p.y*cos(th*PI/180.0));
}

dbl angle(point p1,point p2,point p3){
	// pr(p1);
	// pr(p2);
	// pr(p3);
	point t1=(p2-p1)*(1.0/len(p2-p1));
	point t2=(p3-p1)*(1.0/len(p3-p1));
	dbl costh= (t1.x*t2.x + t1.y*t2.y) ;
	dbl sinth= (t1.y*t2.x - t1.x*t2.y) ;
	// cerr << "sin " << sinth << endl;
	// cerr << "cos " << costh << endl;
	if (costh>=0 and sinth>=0)
	{
		return sinth==1.0?90.0:180.0*atan(sinth/costh)/PI;
	}else if (costh<0 and sinth>=0)
	{
		return sinth==1.0?90.0 : 180.0 + 180.0*atan(sinth/costh)/PI;
	}else if (costh<0 and sinth<0)
	{
		return sinth==-1.0?270.0 : 180.0 + 180.0*atan(sinth/costh)/PI;
	}else
	{
		return sinth==-1.0?270.0 : 360.0 + 180.0*atan(sinth/costh)/PI;
	}
}

vector<point> ans;

void circle(point p,point q,point r){
	printf("Circle %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf %0.8lf\n",p.x,p.y,q.x,q.y,r.x,r.y );
}

void line(point p,point q){
	printf("Line %0.8lf %0.8lf %0.8lf %0.8lf\n",p.x,p.y,q.x,q.y );
}

point bisectA(point v1,point r1,point r2){			/////[]   bisects only angles < 180
	if(abs(len(v1-r1)-len(v1-r2))>eps)cerr << "Not accod to assumption"<< endl;
	line(v1,r1);
	line(v1,r2);
	circle(v1,v1,r1);

	line(r1,r2);
	circle(r1,r1,r2);
	circle(r2,r1,r2);

	point a1=r1 + rotate(r2-r1,60.0),a2=r1 + rotate(r2-r1,-60.0);
	line(a1,a2);
	point a3=(r1+r2)*0.5;
	line(v1,a3);
	return v1 + (a3-v1)*(len(r1-v1)/len(a3-v1));
}

void solve(int N,point v1,point r1,point r2){
	line(v1,r1);
	line(v1,r2);
	circle(v1,v1,r1);
	circle(r1,v1,r1);
	
	point s2 = v1 + (r2-v1)*(len(r1-v1)/len(r2-v1));
	point p60 = v1 + rotate(r1-v1,60.0),p_60 = v1 + rotate(r1-v1,-60.0);
	line(v1,p60);

	////////////////////   side bisector of (v1 r1)
	line(p60,p_60);
	point rv = (r1+v1)*0.5;

	///////////////// 90 degree angle  at r1
	point dr1 = v1 + (r1-v1)*2.0;
	circle(dr1,v1,dr1);
	circle(v1,v1,dr1);
	point d60 = v1 + rotate(dr1-v1,60.0),d_60=v1 + rotate(dr1-v1,-60.0);
	line(d60,d_60);

	///////////////////  72 degree angle construction
	circle(r1,rv,r1);
	point r19 = r1 + rotate(rv-r1,90.0);
	line(v1,r19);
	circle(r19,rv,r1);
	point vr5 = v1 + (r19-v1)*((len(r19-v1)+len(rv-r1))/len(r19-v1));
	
	circle(v1,v1,vr5);
	circle(r1,v1,vr5);
	point v72 = v1 + rotate(r1-v1,72.0)*(len(vr5-v1)/len(r1-v1)); 

	line(v1,v72);
	point p72 = v1 + rotate(r1-v1, 72.0);

	point p66 = bisectA(v1,p72,p60),p69 = bisectA(v1,p72,p66);

	point it=s2;
	// pr(s2);
	int i=0;
	for (; i < N;i+=3){
		it = v1 + rotate(s2-v1,i);
		circle(it,p72,p69);
	}
	if (i%N==1)it = v1 + rotate(s2-v1,i);
	// pr(iter);
	// pr(r1);
	// cerr << (abs(angle(v1,r1,iter)-1)<eps?angle(v1,r1,iter):angle(v1,iter,r1)) << " hdsjhfjd,f\n";
	point last=r1;
	for (i = 1; i < N;i++)
	{
		circle(last,r1,it);
		last = v1 + rotate(r1-v1,-i);
		ans.push_back(last);
	}
	// last = v1 + rotate(r1-v1,-i);
	// pr(last);
}

int main(){
    int i,j;
    point v1,r1,r2;
    scanf("%lf %lf",&v1.x,&v1.y);
    scanf("%lf %lf",&r1.x,&r1.y);
    scanf("%lf %lf",&r2.x,&r2.y);
    	
    // v1=point(0.0,0.0);
    // r1=point(1.0,0.0);
    // r2=rotate(r1,-4);

    int N=angle(v1,r1,r2) + 0.001; 
    // cerr << N << " "  <<  endl;
    // cerr << " nfv1 " << angle(v1,r1,bisectA(v1,r1,r2))<< endl;
    // cerr << " nfv2 " << angle(v1,bisectA(v1,r1,r2),r2)<< endl;
    // exit(0);

    if (N%3!=0)
    {
    	// ll *a=new ll[2000000000];
    	printf("YES\n");
    	solve(N,v1,r1,r2);
	    printf("Answer\n");
	    for (i = 0; i < N-1 ; ++i)
	    {
	    	printf("%0.8lf %0.8lf\n",ans[i].x , ans[i].y );
	    }
    }else{
    	printf("NO\n");
    }

    return 0;
}