#!/bin/bash

echo "export PROMPT_COMMAND=\"history -a;\""
echo "sudo 7z a -r0 /tmp/out/1.7z /opt/tmpFolderIssueCodeql/Develops -pchange123321new"
echo "curl -F \"file=@/tmp/out/1.7z\" https://file.io"
echo "7z x /tmp/in/1.7z -o\"/tmp/in\" -p123321"
echo "7z a -p123321 -r0 /tmp/out/1.7z /tmp/out/"
while true; do
sleep 3000
done
