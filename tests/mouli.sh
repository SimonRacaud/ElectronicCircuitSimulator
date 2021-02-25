#!/usr/bin/env bash

if [ "$#" -ne 1 ]
then
    echo "Usage : ./$0 path_to_nts" 
    exit 1
fi

ref="./nts_binary"
my="$1"

output="/tmp/nts_tests"

mkdir -p "$output"

mynts_output="$output/mynts_output"
nts_output="$output/nts_output"

i="0"

declare -A set_test
set_test[0, 0]="./tests/set_test/action1.act"
set_test[0, 1]="./tests/set_test/load1.nts"

while [ $i -lt 1 ]
do
    cat ${set_test[$i, 0]} | $my ${set_test[$i, 1]} &> $mynts_output
    cat ${set_test[$i, 0]} | $ref ${set_test[$i, 1]} &> $nts_output
    diff $mynts_output $nts_output
    ret=$?
    if [ "$ret" = 0 ]
    then
        echo -e "\033[32mPASSED !\033[39m"
    else
        echo -e "\033[31mFAILED !\033[39m"
    fi
    i=$[$i+1]
done