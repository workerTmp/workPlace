#!/bin/bash

echo "sh works/create.sh medovecot -only build fuzzers"
echo "sh works/create.sh medovecot fuzz_test-mbox-from build fuzzers and start targets"
echo "sh works/create.sh medovecot fuzz_test-mbox-from 1 only start targets"
echo "curl -F \"file=@test.txt\" https://file.io"
echo "7z x /tmp/in/1.7z -o\"/tmp/in\" -p123321"
echo "7z a -ssw -mx1 -p123321 -r0 /tmp/out/2.7z /tmp/out/"
while true; do
sleep 3000
done
