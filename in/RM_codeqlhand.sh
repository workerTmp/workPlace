#/bin/bash

echo "export PATH=/opt/codeqlmy/codeql:$PATH"
echo "codeql resolve languages"
echo "codeql resolve qlpacks"
echo "codeql query format -i <file>"
echo "codeql generate query-help --format=markdown"
echo "codeql database create cpp-database --language=cpp --command=make"
echo "codeql query run file.ql -d=db1"
echo "codeql test run file.qlref"
while true; do
sleep 3000
done
