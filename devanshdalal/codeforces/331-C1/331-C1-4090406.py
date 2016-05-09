n=input();

co=0
while(n>0):
	ma='0'
	a=str(n);
	for i in a:
		if(ma<i):
			ma=i
	kk=int(ma)
	#print kk
	n-=kk
	co+=1

print co