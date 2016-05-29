import sys,os
import fileinput
import subprocess
import random
import time,datetime

# if too frequent then stop.

coin=random.randint(0,1);
if coin==0:
	os.chdir("Codes/")
else:
	os.chdir("DirtBike_Racing_Game_3D/")

f=open('time.txt')
lines=f.readlines()[0].strip()
if int(lines)==int(datetime.date.today().strftime("%d")):
	print 'Exiting beacause you pushed recently'
	exit(0)
else:
	f = open('time.txt','w')
	f.write(str(datetime.date.today().strftime("%d")))
	f.close()

print int(datetime.date.today().strftime("%d")),int(lines)

# reading and updating lines.
f=open('line_no.txt')
lines=f.readlines()
print lines[0]

n= int(lines[0]);

f=open('files.txt')
lines=map(lambda x:x.strip(),f.readlines())
print lines[n]


# Starting proxy script
os.system('~/.proxy.sh &')

print 'sleeping'
subprocess.check_output('sleep 15',shell=True)
print 'waking up'

proxy = 'export http_proxy=http://10.10.78.22:3128 && export https_proxy=http://10.10.78.22:3128 && export ftp_proxy=http://10.10.78.22:3128 ; '

print "git add "+lines[n]


passed=0;
LOW,HIGH=1,5;
try:
	m=random.randint(LOW,HIGH)
	for x in xrange(n,n+m):
		print subprocess.check_output("git add "+lines[x], shell=True)
		os.system("git commit -m \"" +lines[x] +" ADDED\"")
		print subprocess.check_output(proxy+"git push origin master", shell=True)
		passed+=1
	
	# f.write(str(n+m)+'\n') # python will convert \n to os.linesep	
except Exception, e:
	print "Exception",e

finally:
	f = open('line_no.txt','w')
	f.write(str(n+passed)+'\n')
	f.close() # you can omit in most cases as the destructor will call it
	
	os.system('python ../clean.py');

