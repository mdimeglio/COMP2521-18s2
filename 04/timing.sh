#!/bin/sh

# timing.sh
# Script by Matthew Di Meglio, Aug 2018

printf "N,A-Rand(sec),B-Rand(sec),A-Asc(sec),B-Asc(sec),A-Desc(sec),B-Desc(sec),\n"

for n in `seq 10000 500 12000`
do
    for i in `seq 1 5`
    do
        printf "$n,"
        for sortOrder in R A D
        do
            ./gen $n $sortOrder > input.txt
            for sort in './sortA' './sortB'
            do
                (/usr/bin/time --format='%U,' "$sort" < input.txt > /dev/null) &> time.txt
                cat time.txt | tr -d "\n"
                rm time.txt
            done
            rm input.txt
        done
        echo
    done
done




