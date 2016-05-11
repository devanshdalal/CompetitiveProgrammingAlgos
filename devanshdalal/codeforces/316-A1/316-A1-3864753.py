import math
lis=[0]*100
#lis[ord('?')]=0;

count=10
ans=1

a=raw_input()
if(a[0]=='?'):
	ans=9
elif(ord(a[0])>64):
	ans=9
	lis[ord(a[0])]=1
	count=count-1

leng=len(a);
i=0;
while(i<leng-1):
	i=i+1
	ch=int(ord(a[i]))
	if(ch<58 or lis[ch]!=0):
		continue;
	else:
		if(a[i]=='?'):
			ans=ans*10
		else:
			ans=ans*count;
			lis[ch]=1;
			count=count-1;
print ans;