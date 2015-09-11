#!/bin/sh

run()
{
   config=$1
   output_dir=$2
   iev1=$3
   iev2=$4
   mkpdf=$5
   mktxt=$6
   [ ! -e $output_dir ] && mkdir $output_dir
   cp $config $output_dir
   echo "===============" >> $output_dir/log.txt
   echo "Start at `date`" >> $output_dir/log.txt
   echo "===============" >> $output_dir/log.txt
   echo "===============" >> $output_dir/err
   echo "Start at `date`" >> $output_dir/err
   echo "===============" >> $output_dir/err
   echo "./main $config $output_dir $iev1 $iev2 $mkpdf $mktxt >> $output_dir/log.txt 2>> $output_dir/err &"
   ./main $config $output_dir $iev1 $iev2 $mkpdf $mktxt >> $output_dir/log.txt 2>> $output_dir/err &
}

# thre=0.02
#run config1.txt output/run1/ 10 10 yes no # single-0%-0.02-threshold
#run config2.txt output/run2/ 10 10 yes no # multi -0%-0.02-threshold
#run config3.txt output/run3/ 10 10 yes no # single-10%-0.02-threshold
#run config4.txt output/run4/ 10 10 yes no # multi -10%-0.02-threshold

#run config1.txt output/run1/ 0 1999 no yes # single-0%-0.02-threshold
#run config2.txt output/run2/ 0 1999 no yes # multi -0%-0.02-threshold
#run config3.txt output/run3/ 0 1999 no yes # single-10%-0.02-threshold
#run config4.txt output/run4/ 0 1999 no yes # multi -10%-0.02-threshold

# thre=0.01
#run config1.txt output/run5/ 10 10 yes no # single-0%-0.01-threshold
#run config2.txt output/run6/ 10 10 yes no # multi -0%-0.01-threshold
#run config3.txt output/run7/ 10 10 yes no # single-10%-0.01-threshold
#run config4.txt output/run8/ 10 10 yes no # multi -10%-0.01-threshold

#run config1.txt output/run5/ 0 1999 no yes # single-0%-0.01-threshold
#run config2.txt output/run6/ 0 1999 no yes # multi -0%-0.01-threshold
#run config3.txt output/run7/ 0 1999 no yes # single-10%-0.01-threshold
#run config4.txt output/run8/ 0 1999 no yes # multi -10%-0.01-threshold

# thre=0.005
#run config1.txt output/run9/  10 10 yes no # single-0%-0.005-threshold
#run config2.txt output/run10/ 10 10 yes no # multi -0%-0.005-threshold
#run config3.txt output/run11/ 10 10 yes no # single-10%-0.005-threshold
#run config4.txt output/run12/ 10 10 yes no # multi -10%-0.005-threshold

#run config1.txt output/run9/  0 1999 no yes # single-0%-0.005-threshold
#run config2.txt output/run10/ 0 1999 no yes # multi -0%-0.005-threshold
#run config3.txt output/run11/ 0 1999 no yes # single-10%-0.005-threshold
#run config4.txt output/run12/ 0 1999 no yes # multi -10%-0.005-threshold

# thre=0.001
#run config1.txt output/run13/ 10 10 yes no # single-0%-0.001-threshold
#run config2.txt output/run14/ 10 10 yes no # multi -0%-0.001-threshold
#run config3.txt output/run15/ 10 10 yes no # single-10%-0.001-threshold
#run config4.txt output/run16/ 10 10 yes no # multi -10%-0.001-threshold

# thre=0.001
#run config1.txt output/run13/ 0 1999 no yes # single-0%-0.001-threshold
#run config2.txt output/run14/ 0 1999 no yes # multi -0%-0.001-threshold
#run config3.txt output/run15/ 0 1999 no yes # single-10%-0.001-threshold
#run config4.txt output/run16/ 0 1999 no yes # multi -10%-0.001-threshold

# check pz peaks in negative pzres
run output/run1/config1.txt output/run1/ 0 10 yes no
