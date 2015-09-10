#!/bin/sh

run()
{
   config=$1
   output_dir=$2
   iev1=$3
   iev2=$4
   mkpdf=$5
   [ ! -e $output_dir ] && mkdir $output_dir
   cp $config $output_dir
   echo "./main $config $output_dir $iev1 $iev2 $mkpdf > $output_dir/log.txt 2> $output_dir/err &"
   ./main $config $output_dir $iev1 $iev2 $mkpdf > $output_dir/log.txt 2> $output_dir/err &
}

#run config1.txt output/run1/ 10 10 yes # single-0%-0.02-threshold
#run config2.txt output/run2/ 10 10 yes # multi -0%-0.02-threshold
#run config3.txt output/run3/ 10 10 yes # single-10%-0.02-threshold
#run config4.txt output/run4/ 10 10 yes # multi -10%-0.02-threshold

#run config1.txt output/run1/ 0 1999 no # single-0%-0.02-threshold
#run config2.txt output/run2/ 0 1999 no # multi -0%-0.02-threshold
#run config3.txt output/run3/ 0 1999 no # single-10%-0.02-threshold
#run config4.txt output/run4/ 0 1999 no # multi -10%-0.02-threshold

#run config1.txt output/run5/ 10 10 yes # single-0%-0.01-threshold
#run config2.txt output/run6/ 10 10 yes # multi -0%-0.01-threshold
#run config3.txt output/run7/ 10 10 yes # single-10%-0.01-threshold
#run config4.txt output/run8/ 10 10 yes # multi -10%-0.01-threshold

#run config1.txt output/run5/ 0 1999 no # single-0%-0.01-threshold
#run config2.txt output/run6/ 0 1999 no # multi -0%-0.01-threshold
#run config3.txt output/run7/ 0 1999 no # single-10%-0.01-threshold
#run config4.txt output/run8/ 0 1999 no # multi -10%-0.01-threshold
