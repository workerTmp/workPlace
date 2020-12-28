#!/bin/bash

#sh works/create.sh medovecot -only build fuzzers
#sh works/create.sh medovecot fuzz_test-mbox-from build fuzzers and start targets
#sh works/create.sh medovecot fuzz_test-mbox-from 1 only start targets

echo $#
if [ "$#" -ne 3 ]; then
  if [ ! -d "oss-fuzz/$1" ]; then
    (cd oss-fuzz && export PROJECT_NAME=$1 && python infra/helper.py generate $PROJECT_NAME)
  fi
  #works/$1 change to works/MyProj/ for all projects one folder
  (cp -r works/$1/* oss-fuzz/projects/$1/&&cd oss-fuzz &&python infra/helper.py build_image $1 --pull)
  (cd oss-fuzz &&python infra/helper.py build_fuzzers $1 && python infra/helper.py check_build  $1)
fi
if [ "$#" -eq 1 ]; then
    exit 2
fi
if [ ! -d "/opt/123/" ]; then
  (mkdir /opt/123)
fi
(cd oss-fuzz && python infra/helper.py run_fuzzer --corpus-dir /opt/123/ $1 $2)
