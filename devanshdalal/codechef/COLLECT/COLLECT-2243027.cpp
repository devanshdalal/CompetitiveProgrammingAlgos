#include <stdio.h>
#include <iostream>
typedef long long ll;
using namespace std;
const int mod=3046201,Siz=2900001;
int n,q;ll mem[Siz];

ll inv[]={1,1,1523101,2538501,2919276,3020816,2534270,2973068,1894734,210526,1239533,1774249,2940205,2335078,1472306,910474,1199230,1324861,2950571,2239536,721217,1049744,324643,543889,2941938,1579854,2169672,418825,2082023,2382705,1602524,1427398};


int app,y,sta;
ll ac;
ll ftry(int m){
	return mem[m];
}

int msb(unsigned int v) {
  static const int pos[32] = {0, 1, 28, 2, 29, 14, 24, 3,
    30, 22, 20, 15, 25, 17, 4, 8, 31, 27, 13, 23, 21, 19,
    16, 7, 26, 12, 18, 6, 11, 5, 10, 9};
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v = (v >> 1) + 1;
  return pos[(v * 0x077CB531UL) >> 27];
}

ll fp(int x,int m){
	int te=1<<msb((unsigned)m);
	ll acu=1;
	int xx=x;
	while(te){
		acu=m/te?((acu*acu)%mod)*((ll)xx):acu*acu;
		m=m%te;
		te=te/2;
		acu=acu%mod;
	}
	return acu;
}

char buf[21];int ix;
//int putchar_unlocked(char ch) { return putchar(ch);  }
inline void writeL(ll x) {
     ix = 20;
     buf[20] = '\n';
     do 
     {
        buf[--ix] = (x % 10) + '0';
        x/= 10;
     }while(x);
     do
     {
        putchar_unlocked(buf[ix]);
     } while (buf[ix++] != '\n');
}

//int getchar_unlocked()  {return getchar();}
inline void Read(int &x) {
	register int c= getchar_unlocked();
	x = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	for(; c>47 && c<58 ; c = getchar_unlocked()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
}

inline bool Readc() {
	register int c= getchar_unlocked();
	for(; ( c<97 || c>123 ); c = getchar_unlocked());
	return c=='c';
}

struct node
{
int sum;
} arr[500009];
 
 
void  update(int node,int low,int high,int ix,int upd)
{
if(low==ix && high==ix)
{
arr[node].sum=upd;
return;
}

int left,mid,right;
left=node<<1;
right=left+1;
mid=(low+high)/2;
if(ix<=mid)
update(left,low,mid,ix,upd);
else if(ix>mid)
update(right,mid+1,high,ix,upd);
else
{
update(left,low,mid,ix,mid);
update(right,mid+1,high,mid+1,ix);
}
 
arr[node].sum=arr[left].sum+arr[right].sum;

}
 
int query(int node,int low,int high,int i,int j){
	
if(low==i && high==j)
{
return arr[node].sum;
}
int left,right,mid;
left=node<<1;
right=left+1;
mid=(low+high)/2;
if(j<=mid)
return query(left,low,mid,i,j);
else if(i>mid)
return query(right,mid+1,high,i,j);
else
return query(left,low,mid,i,mid)+query(right,mid+1,high,mid+1,j);
}


int main(){
	int i,j,k,ii,sum,kk,bal;ll combi,ans;bool bo;
	mem[0]=1;
	for(i=1;i<Siz;i++) mem[i]=((ll)i*mem[i-1])%mod;
	Read(n);
	for(i=0;i<n;i++){ Read(kk); update(1,0,n-1,i,kk);	}
	//for(i=0;i<n;i++) cout << a[i] << endl;
	Read(q);
	//cout<<q<<endl;
	for(i=0;i<q;i++){
		bo=Readc();
		Read(j);
		Read(k);j--;k--;
		if(bo){
			update(1,0,n-1,j,k+1);
		}
		else{
			ans=1;
			sum=query(1,0,n-1,j,k);
			//cout <<"ans:"<<ans<<endl;
			bal=sum/(k-j+1);
			kk=sum%(k-j+1);		//cout<<"k="<<k<<",j="<<j<<",kk="<<kk<<endl;
			combi=(ftry(k-j+1)*fp((int)ftry(kk),3046199)%mod)*fp((int)ftry(k-j+1-kk),3046199)%mod;
			ans=(ftry(sum)*combi)%mod;						//cout<<"ans=" <<ans<< endl;
			ans=(ans*fp((int)inv[bal+1],kk))%mod;			//cout<<"ans=" <<fp(int(inv[bal]),k-j+1-kk)<< endl;
			ans=(ans*fp((int)inv[bal],k-j+1-kk))%mod;		
			//cout<<"combi:"<< combi<<endl;		cout <<"ans:"<<ans<<endl;
			writeL(ans);
		}
	}
	return 0;
}