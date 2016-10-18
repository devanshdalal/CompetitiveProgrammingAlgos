#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cassert>

typedef long long ll;

std::pair<int,ll> a[1000001],b[1000001];
int left[1000001],right[1000001],k;
char ans[1000001];

int bsearch(ll n){
	int l=0,h=k-1,m;
	while(l<=h){
		m=(l+h)/2;
		if(n<b[m].first){
			h=m-1;
		}else if(n>b[m].first){
			l=m+1;
		}else{
			return m;
		}
	}
	return h;
}


int main(){
	std::ios_base::sync_with_stdio(0);
	int n,t,m,kk;
	char ch,turn;	
	
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i].first ;
		a[i].second=i;
	}

	std::stack<std::pair<int,int> > s;
	for (int i = 0; i < n; ++i)
	{
		while(!s.empty() and s.top().first<=a[i].first){
			s.pop();
		}
		if (s.empty())
		{
			left[i]=0;
		}else{
			left[i]=s.top().second+1;
		}
		s.push(a[i]);
	}

	while(!s.empty())s.pop();
	for (int i = n-1; i >=0 ; --i)
	{
		while(!s.empty() and s.top().first<a[i].first){
			s.pop();
		}
		if (s.empty())
		{
			right[i]=n-1;
		}else{
			right[i]=s.top().second-1;
		}
		s.push(a[i]);
	}


	for (int i = 0; i < n; ++i)
	{
		a[i].second=ll(i-left[i]+1)*ll(right[i]-i+1);
	}

	sort(a,a+n);

	for (int i = k =0; i < n;)
	{
		ll sum=0;
		int j;
		for (j = i; j<n and a[i].first==a[j].first; ++j)
		{
			sum+=a[j].second;
		}
		b[k].first=a[i].first;
		b[k++].second=sum;
		i=j;
	}

	for (int i = 1; i < k; ++i)
	{
		assert(b[i].second>0);
		b[i].second+=b[i-1].second;
	}
	assert(b[k-1].second>=ll(n)*ll(n+1)/2);

	ll total = ll(n)*ll(n+1)/2;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for(int i=0;i<m;i++){
		std::cin >> ch >> kk >> turn ;
		switch(ch){
			case '<': 
				if( ( kk<=b[0].first? 0:b[ bsearch(kk-1) ].second ) &1){
					ans[i]=turn;
				}else{
					ans[i]= turn=='C'?'D':'C' ;
				}
				break;
			case '>':
				if( ( total - (kk<b[0].first?0:b[bsearch(kk)].second) )&1){
					ans[i]=turn;
				}else{
					ans[i]= turn=='C'?'D':'C' ;
				}
				break;
			case '=':
				int j=bsearch(kk);
				if(  ( (j>=0 and b[j].first==kk)? (b[j].second - (j==0?0:b[j-1].second)):0 )&1){
					ans[i]=turn;
				}else{
					ans[i]= turn=='C'?'D':'C' ;
				}
		}
	}

	std::cout << ans << "\n";

	return 0;
}