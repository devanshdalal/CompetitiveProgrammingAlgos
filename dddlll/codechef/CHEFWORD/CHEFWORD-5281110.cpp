#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#define DD ios_base::sync_with_stdio(false)
#define maxx 10000001
#define eps 0.0000001
typedef long long ll;
typedef unsigned long long ul;
typedef double d;
using namespace std;
const ll mod = 1000000007;

template< class T >
class Matrix
{
    public:
        int m,n;
        T *data;
 
        Matrix( int m, int n );
        Matrix( const Matrix< T > &matrix );
 
        const Matrix< T > &operator=( const Matrix< T > &A );
        const Matrix< T > operator*( const Matrix< T > &A );
        const Matrix< T > operator^( int P );
 
        ~Matrix();
};
 
template< class T >
Matrix< T >::Matrix( int m, int n )
{
    this->m = m;
    this->n = n;
    data = new T[m*n];
}
 
template< class T >
Matrix< T >::Matrix( const Matrix< T > &A )
{
    this->m = A.m;
    this->n = A.n;
    data = new T[m*n];
    for( int i = 0; i < m * n; i++ )
        data[i] = A.data[i];
}
 
template< class T >
Matrix< T >::~Matrix()
{
    delete [] data;
}
 
template< class T >
const Matrix< T > &Matrix< T >::operator=( const Matrix< T > &A )
{
    if( &A != this )
    {
        delete [] data;
        m = A.m;
        n = A.n;
        data = new T[m*n];
        for( int i = 0; i < m * n; i++ )
            data[i] = A.data[i];
    }
    return *this;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator*( const Matrix< T > &A )
{
    Matrix C( m, A.n );
    for( int i = 0; i < m; ++i )
        for( int j = 0; j < A.n; ++j )
        {
            C.data[i*C.n+j]=0;
            for( int k = 0; k < n; ++k )
                C.data[i*C.n+j] = C.data[i*C.n+j] + data[i*n+k]*A.data[k*A.n+j];
        }
    return C;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator^( int P )
{
    if( P == 1 ) return (*this);
    if( P & 1 ) return (*this) * ((*this) ^ (P-1));
    Matrix B = (*this) ^ (P/2);
    return B*B;
}
 
// int main()
// {
//     Matrix<int> M(2,2);
//     M.data[0] = 1;M.data[1] = 1;
//     M.data[2] = 1;M.data[3] = 0;
 
//     int F[2]={0,1};
//     int N;
//     while (~scanf("%d",&N))
//         if (N>1)
//             printf("%lld\n",(M^N).data[0]);
//         else
//             printf("%d\n",F[N]);
// }

Matrix<double> tabl(26,26);


int main(){
    int t,i,j,l,n,k,m,p,q;
    scanf("%d",&t);
    char a[101],b[101];
    while(t--){
        scanf("%d %d",&n,&k);
    	
        scanf("%s",a);
        l=strlen(a);
        for (i = 0; i < 26; ++i)
        {
            for (j = 0;j <26; ++j)
            {
                scanf("%lf",&tabl.data[i*26+j]);
            }
        }
        tabl=tabl^k;
        double ans=0;
        map<int,int> mymap;
        for (i = 0; i < n; ++i)
        {
            scanf("%s",b);
            if (strlen(b)==l)
            {
                int val=0,t26=1;
                double prob=1;
                for (j = 0; j< l; ++j)
                {
                    val+=(b[j]-97)*t26;
                    t26=t26*26;
                    if(k>0)prob*=tabl.data[(a[j]-97)*26+(b[j]-97)];
                    else if (a[j]!=b[j])prob=0;
                }
                if(!mymap[val]){
                    ans+=prob;
                    mymap[val]=1;
                }
                // cerr << prob << endl;
            }
        }

        printf("%0.8lf\n", ans );
    }
    return 0;
}