#!/bin/bash

echo "export PROMPT_COMMAND=\"history -a;\""
echo "create projectFolder in works/"
echo "export PATH=/opt/codeqlmy/codeql:$tmpPATH"
echo "codeql test run <qlref> --show-extractor-output"
echo "codeql query format -i <ql>"
echo "codeql generate query-help --format=markdown"
echo "codeql database create cpp-database --language=cpp --command=make"
echo "codeql query run file.ql -d=db1"
echo "curl -F \"file=@/tmp/out/1.7z\" https://file.io"
echo "7z x /tmp/in/1.7z -o\"/tmp/in\" -p123321"
echo "7z a -p123321 -r0 /tmp/out/1.7z /tmp/out/"
while true; do
sleep 3000
done
