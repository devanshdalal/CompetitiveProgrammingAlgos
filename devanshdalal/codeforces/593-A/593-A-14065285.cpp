#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
string s;
std::vector<string> v;

bool isin(string st,char x, char y){
	for (int i = 0; i < st.length(); ++i)
	{
		if (st[i]!=x and st[i]!=y)return 0;
	}
	return 1;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		v.push_back(s);
	}

	int maxx=0;
	for (int i = 0; i < 26; ++i)
	{
		for (int j = i; j < 26; ++j)
		{
			int curr=0;
			for (int k = 0; k < n; ++k)
			{
				if(isin(v[k],'a'+i,'a'+j))curr += v[k].length() ;	
			}
			if (curr>maxx)
			{
				// cout << i << ": " << j << endl;
				maxx= curr;
			}
		}

	}

	cout << maxx << endl;
	

	return 0;
}