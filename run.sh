#!/bin/sh

./main config1.txt output/run1/ 10 10 yes > output/run1/log.txt & # single-0%-0.02-threshold
./main config2.txt output/run2/ 10 10 yes > output/run2/log.txt & # multi -0%-0.02-threshold
./main config3.txt output/run3/ 10 10 yes > output/run3/log.txt & # single-10%-0.02-threshold
./main config4.txt output/run4/ 10 10 yes > output/run4/log.txt & # multi -10%-0.02-threshold
