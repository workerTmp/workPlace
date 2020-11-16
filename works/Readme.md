## manual work with target for oss-fuzz

1. use bash script for automatize work  
sh works/create.sh medovecot -only build fuzzers  
sh works/create.sh medovecot fuzz_test-mbox-from build fuzzers and start targets  
sh works/create.sh medovecot fuzz_test-mbox-from 1 only start targets  

2. when create target file use simple compilation  
gcc -c fuzz_test-target.c -o 11.o

3. see chenge value rss for early detection oom

### additional data  
1.  
(cd oss-fuzz && python infra/helper.py reproduce medovecot fuzz_test-mbox-from /home/runner/work/workPlace/workPlace/oss-fuzz/build/out/medovecot/)  
(cd oss-fuzz && python infra/helper.py build_fuzzers --sanitizer=coverage medovecot)  
(cd oss-fuzz &&python infra/helper.py coverage --fuzz-target=fuzz_test-mbox-from --corpus-dir=/opt/123/ medovecot)  

2.  gdb debuging  
(cd oss-fuzz &&python infra/helper.py shell base-runner-debug)  
gdb --args /out/medovecot/fuzz_test-mbox-from /out/medovecot/testcase  

3.  
$ python infra/helper.py build_image $PROJECT_NAME  
$ python infra/helper.py build_fuzzers --sanitizer <address/memory/undefined> \  
    --engine <libfuzzer/afl/honggfuzz> --architecture <x86_64/i386> $PROJECT_NAME  
$ python infra/helper.py check_build  --sanitizer <address/memory/undefined> \  
    --engine <libfuzzer/afl/honggfuzz> --architecture <x86_64/i386> $PROJECT_NAME \  
    <fuzz_target_name>  
	
	


