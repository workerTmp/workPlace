#!/bin/bash

echo "curl -F \"file=@test.txt\" https://file.io"
echo "7z x /tmp/1.7z -o\"/tmp/in\" -p123321"
echo "7z a -ssw -mx1 -p123321 -r0 /tmp/2.7z /tmp/out/"
while true; do
sleep 3000
done
