#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>

#define pb push_back
#define H 5
#define MUL 100
#define dbg(x) {cerr << #x << " = " << x << endl;}
typedef double dbl;
typedef long long ll;
using namespace std;

char arr[1111];
ll TB[111][1111],n,l,t,b[111],cc,B;
vector<int> a;
ll *dp1=new ll[111],*dp2=new ll[111];

inline void reset(){
    cc=0;
    random_shuffle(a.begin(), a.end());
    // for (int i = a.size()-1; i>=0 ; --i)
    // {
    //  cerr << a[i] ;
    // }cerr << endl;
    for (int i = 0; i < n; ++i){
        ll temp=0;
        for (int j =0; j <l ; ++j){
            temp += TB[i][j]*a[j];
        }
        dp1[i]=temp%b[i];
        cc+=dp1[i];
    }
    // cerr << endl;
}

inline void findOpt(double lmt){
    if (l>1){
        double start=clock();
        lmt=(lmt/(t+1))*CLOCKS_PER_SEC;
        reset();
        // dbg(cc);
        vector<int> mina;
        for (int i = 0; i < l; ++i)mina.pb(a[i]);
        ll btn=cc;
        int j=0 ,agr=0 ;
        for(double tp=clock()-start ;cc!=0 and tp<lmt;j++,tp=clock()-start){
            if(l>2 and rand()%100<=1){
                int x=2+rand()%(l-2),y=1+rand()%(x-1),z=rand()%y;
                if(a[x]==a[y]==a[z])continue;
                ll nval=0;
                for (int i = 0; i < n; ++i){
                    dp2[i]=(dp1[i]+(a[z]-a[x])*TB[i][x] + (a[x]-a[y])*TB[i][y] + (a[y]-a[z])*TB[i][z])%b[i] ;
                    if(dp2[i]<0)dp2[i]+=b[i];
                    nval+=dp2[i];
                }
                double p = exp(-MUL*(nval-cc+1)*CLOCKS_PER_SEC/abs(lmt-tp) ) ;
                bool myCond=(ll(rand())*ll(rand())%100000) < 100000*p;
                if ( myCond  ){
                    swap(dp2,dp1);
                    int save=a[x];
                    a[x]=a[z];
                    a[z]=a[y];
                    a[y]=save;
                    cc=nval;
                    if (btn>nval){
                        btn=nval;
                        for (int i = 0; i < l; ++i)mina[i]=a[i];
                    }
                }
                if (tp>lmt/(B-agr) and agr<B){
                    agr+=1;
                    reset();
                    if (cc<btn)
                    {
                        btn=cc;
                        for (int i = 0; i < l; ++i)mina[i]=a[i];
                    }
                }
            }else{
                int x=1+rand()%(l-1),y=rand()%x;
                if(a[x]==a[y])continue;
                ll nval=0;
                for (int i = 0; i < n; ++i){
                    dp2[i]=( dp1[i] + (a[x]-a[y])*(TB[i][y]-TB[i][x]) )%b[i] ;
                    if(dp2[i]<0)dp2[i]+=b[i];
                    nval+=dp2[i];
                }
                double p = exp(-MUL*(nval-cc+1)*CLOCKS_PER_SEC/abs(lmt-tp) ) ;
                bool myCond=(ll(rand())*ll(rand())%100000) < 100000*p;
                if ( myCond  ){
                    swap(dp2,dp1);
                    swap(a[x],a[y]);
                    cc=nval;
                    if (btn>nval){
                        btn=nval;
                        for (int i = 0; i < l; ++i)mina[i]=a[i];
                    }
                }
                if (tp>lmt/(B-agr) and agr<B){
                    agr+=1;
                    reset();
                    if (cc<btn)
                    {
                        btn=cc;
                        for (int i = 0; i < l; ++i)mina[i]=a[i];
                    }
                }
            }
        }
        for (int i = 0; i < l; ++i){
            arr[l-i-1]=(mina[i]+'0');
        }
        cerr << cc << " " << btn << endl;
    }
    cout << arr << "\n";
}

inline void findOpt2(double lmt){
    double start=clock();
    lmt=(lmt/(t+1))*CLOCKS_PER_SEC;
    reset();
    // dbg(cc);
    vector<int> mina;
    for (int i = 0; i < l; ++i)mina.pb(a[i]);
    ll btn=cc;
    int j=0 ,agr=0 ;
    for(double tp=clock()-start ;cc!=0 and tp<lmt;j++,tp=clock()-start){
        int x=2+rand()%(l-2),y=1+rand()%(x-1),z=rand()%y;
        if(a[x]==a[y]==a[z])continue;
        ll nval=0;
        for (int i = 0; i < n; ++i){
            dp2[i]=(dp1[i]+(a[z]-a[x])*TB[i][x] + (a[x]-a[y])*TB[i][y] + (a[y]-a[z])*TB[i][z])%b[i] ;
            if(dp2[i]<0)dp2[i]+=b[i];
            nval+=dp2[i];
        }
        double p = exp(-10*(nval-cc+1)*CLOCKS_PER_SEC/abs(lmt-tp) ) ;
        bool myCond=(ll(rand())*ll(rand())%100000) < 100000*p;
        if ( myCond  ){
            swap(dp2,dp1);
            int save=a[x];
            a[x]=a[z];
            a[z]=a[y];
            a[y]=save;
            cc=nval;
            if (btn>nval){
                btn=nval;
                for (int i = 0; i < l; ++i)mina[i]=a[i];
            }
        }
        if (tp>lmt/(B-agr) and agr<B){
            agr+=1;
            reset();
            if (cc<btn)
            {
                btn=cc;
                for (int i = 0; i < l; ++i)mina[i]=a[i];
            }
        }
    }
    for (int i = 0; i < l; ++i){
        arr[l-i-1]=(mina[i]+'0');
    }
    cerr << cc << " " << btn << endl;
    cout << arr << "\n";
}

int main(){
    double myst=clock();
    srand(time(NULL));
    ll p,q;
    ios_base::sync_with_stdio(0);
    cin >> t;
    for(;t--;){
        cin >> arr;
        cin >> n;
        l=strlen(arr);
        B=5-log10(l);
        for (int i = 0; i < n; ++i){
            cin >> b[i];
            for (int j = TB[i][0]=1 ; j < l; ++j){
                TB[i][j]=TB[i][j-1]*10%b[i];
            }
        }
        a.clear();
        for (int i = 0; i < l; ++i)a.pb(arr[l-i-1]-'0');
        double ttl=-(clock()-myst)/CLOCKS_PER_SEC  + 4.9722;
        findOpt( ttl  );
        // else findOpt(ttl);
    }

    return 0;
}