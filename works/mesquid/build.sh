#!/bin/bash -eu
# Copyright 2020 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
################################################################################

# build project
# e.g.
./autoreconf -i
./configure --prefix=/usr/local/squid
make all

# build fuzzers
# e.g.
python3 $SRC/libadd.py $SRC/mesquid/
#cp $SRC/fuzz_*.zip $OUT/
for file in $SRC/fuzz_*.c;
do
    name=$(basename $file .c)
    mkdir /tmp/${name}_corpus
    $CXX $CXXFLAGS -c  $SRC/${name}.c -o $OUT/${name}.o
    $CXX $CXXFLAGS -o $OUT/${name} $OUT/${name}.o $LIB_FUZZING_ENGINE  $SRC/medovecot/liball1.a
    rm -f $OUT/${name}.o
done
