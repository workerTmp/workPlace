import sys
import os
import hashlib



fileName=sys.argv[1]
pathName=sys.argv[2]
arName=sys.argv[3]

if not os.path.exists(pathName):
    os.system("mkdir "+pathName)

with open(fileName) as f:
    for line in f:
        pbHash = hashlib.sha1(line.split("\n")[0].encode('utf-8')).hexdigest()
        open(pathName+pbHash,"w").write(line.split("\n")[0])
os.system("zip -j "+arName+"_seed_corpus.zip "+pathName+"*")
