#!/bin/sh

# testStability.sh
# script by Matthew Di Meglio, Aug 2015

sort='./sortA'

for i in `seq 1 1000`
do
    ./gen 1000 R | sed -r -e "s/^(1|2|3|4|5|6|7|8|9|10) /1 /" > stabilityInput.txt
    cat stabilityInput.txt | "$sort" | egrep "^1 " > stabilityOutput.txt
    cat stabilityInput.txt | egrep "^1 " > stabilityExpected.txt
    
    if [ -z `diff stabilityOutput.txt stabilityExpected.txt` ]
    then
        echo "Test $i passed"
    else
        echo "Test $i failed"
        echo "Sort A output lines with key 1 in order:"
        cat stabilityOutput.txt
        echo ""
        echo "Expected:"
        cat stabilityExpected.txt
    fi

    rm stabilityInput.txt
    rm stabilityOutput.txt
    rm stabilityExpected.txt
done