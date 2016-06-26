import sys,os
import fileinput
import subprocess



os.system('rm -rf .git/')

os.system('echo \'README.md\' > files.txt')
os.system('find . -type f  | sed s,^./,, >> files.txt')

os.system('git init')

proxy = 'export http_proxy=http://10.10.78.22:3128 && export https_proxy=http://10.10.78.22:3128 && export ftp_proxy=http://10.10.78.22:3128 ; '

os.system('git config --global user.email mr.devanshdalal@gmail.com');
os.system('git config --global user.name Devansh Dalal')

f = open('line_no.txt','w')
f.write('0\n') # python will convert \n to os.linesep
f.close() # you can omit in most cases as the destructor will call it


os.system('git remote add origin https://github.com/devanshdalal/CompetitiveProgrammingAlgos.git')
# os.system(proxy+ 'git config remote.origin.url origin https://devanshdalal:GitHub1@github.com/devanshdalal/CompetitiveProgrammingAlgos.git')
# os.system('git config remote.origin.url https://devanshdalal:GitHub1@github.com/devanshdalal/CompetitiveProgrammingAlgos.git')
os.system('git remote -v; git config --global credential.helper cache; git config --global credential.helper \'cache --timeout=36000000\'')


