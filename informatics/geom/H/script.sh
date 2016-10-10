#!/usr/bin/env bash

./gen.out > in
./a.out < in > out
./b.out < in > out2

diff out out2
cmp=$?

if [ $cmp -eq 1 ]
then
    echo "Found test"
else
    echo "Good"
    sh script.sh
fi
