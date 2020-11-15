## manual work with target for oss-fuzz

1. use bash script for automatize work  
#sh works/create.sh medovecot -only build fuzzers  
#sh works/create.sh medovecot fuzz_test-mbox-from build fuzzers and start targets  
#sh works/create.sh medovecot fuzz_test-mbox-from 1 only start targets  

2. when create target file use simple compilation  
gcc -c fuzz_test-target.c -o 11.o

3. see chenge value rss for early detection oom
