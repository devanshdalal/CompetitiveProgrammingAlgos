import sys,os
import fileinput
import subprocess

try:
	a=subprocess.check_output('ps | grep proxy | grep -o \'[0-9]*\'',shell=True).split()[0].strip();
	print a,'kill '+str(int(a));
	print os.system('kill '+str(int(a)) );
except Exception, e:
	pass




try:
	# a=subprocess.check_output('ps | grep proxy | grep -o \'[0-9]*\'',shell=True).split()[0].strip();
	a=subprocess.check_output('ps | grep sleep | grep -o \'[0-9]*\'',shell=True).split()[0].strip();
	os.system('kill '+a);
except Exception, e:
	pass



try:
	# a=subprocess.check_output('ps | grep proxy | grep -o \'[0-9]*\'',shell=True).split()[0].strip();
	a=subprocess.check_output('ps | grep git-credential | grep -o \'[0-9]*\'',shell=True).split()[0].strip();
	os.system('kill '+a);
except Exception, e:
	pass

