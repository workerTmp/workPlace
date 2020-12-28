#!/bin/bash

echo "create projectFolder in works/"
echo "export PATH=/opt/codeqlmy/codeql:$tmpPATH"
echo "codeql resolve languages"
echo "codeql resolve qlpacks"
echo "codeql query format -i <file>"
echo "codeql generate query-help --format=markdown"
echo "codeql database create cpp-database --language=cpp --command=make"
echo "codeql query run file.ql -d=db1"
echo "codeql test run file.qlref"
echo "curl -F \"file=@test.txt\" https://file.io"
echo "7z x /tmp/1.7z -o\"/tmp/in\" -p123321"
echo "7z a -ssw -mx1 -p123321 -r0 /tmp/2.7z /tmp/out/"
while true; do
sleep 3000
done
