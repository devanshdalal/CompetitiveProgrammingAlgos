#include <stdio.h>
//~ #include <iostream>
#include <string.h>
//~ using namespace std;
#define si(a) scanf("%d", &a)

int main() 
{
	int t;
	//~ ios_base::sync_with_stdio(false);
	si(t);
	char str[8000000];
	while(t--)
	{
		int n, counter=0, diff,k=0;
		int s, e, l, r;
		si(n);
		si(s);si(e);
		for(int i=1;i<n;i++)
		{
			si(l);si(r);
			while(l<s)
			{
				counter++;
				s--;
				str[k++]='L';
				str[k++]='-';
			}
			while(l > s || r > e)
			{
				if(l>s && s+1 != e)
				{
					s++;
					str[k++]='L';
					str[k++]='+';
				} else {
					e++;
					str[k++]='R';
					str[k++]='+';
				}
				counter++;
			}
			while(r<e)
			{
				counter++;
				e--;
				str[k++]='R';
				str[k++]='-';
			}
			
		}
		str[k++]='\n';
		str[k++]='\0';
		//~ cout<<counter<<endl<<str<<endl;
		int len=strlen(str);
		printf("%d\n%s\n",counter,str);
		//~ for(int i=0;i<len;i++)putchar_unlocked(str[i]);
	}
	return 0;
}