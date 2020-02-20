#!/bin/bash
for f in *.txt
do
    ./main < ${f} 
done