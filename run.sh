#!/bin/sh

TOP_DIR='/home/had/hideyuki/private/genfit2/KEKCC/circle_fit/'

set_ijob=$1
set_irun=$2
echo "set_ijob => $set_ijob"
echo "set_irun => $set_irun"

run()
{
   ijob=$1
   irun=$2
   #echo "ijob ${ijob}"
   #echo "irun ${irun}"
   [ $ijob -ne $set_ijob ] && return
   output_dir=$TOP_DIR/output/run${irun}
   config=$output_dir/config.txt
   [ ! -e $config ] && echo "No config.txt" && return
   iev1=$3
   iev2=$4
   mkpdf=$5
   mktxt=$6
   [ ! -e $output_dir ] && mkdir $output_dir
   echo "===============" >> $output_dir/log-$mkpdf.txt
   echo "Start at `date`" >> $output_dir/log-$mkpdf.txt
   echo "===============" >> $output_dir/log-$mkpdf.txt
   echo "===============" >> $output_dir/err-$mkpdf
   echo "Start at `date`" >> $output_dir/err-$mkpdf
   echo "===============" >> $output_dir/err-$mkpdf
   echo "$TOP_DIR/main $config $output_dir $iev1 $iev2 $mkpdf $mktxt > $output_dir/log-mktxt-$mktxt.txt 2> $output_dir/err-mktxt-$mktxt &"
   $TOP_DIR/main $config $output_dir $iev1 $iev2 $mkpdf $mktxt > $output_dir/log-mktxt-$mktxt.txt 2> $output_dir/err-mktxt-$mktxt &
}

# thre=0.02
run 1 1 10 10 yes no # single-0%
run 2 2 10 10 yes no # multi -0%
run 3 3 10 10 yes no # single-10%
run 4 4 10 10 yes no # multi -10%
      
run 5 1 0 1999 no yes # single-0%
run 6 2 0 1999 no yes # multi -0%
run 7 3 0 1999 no yes # single-10%
run 8 4 0 1999 no yes # multi -10%

# thre=0.01
run  9 5 10 10 yes no # single-0%
run 10 6 10 10 yes no # multi -0%
run 11 7 10 10 yes no # single-10%
run 12 8 10 10 yes no # multi -10%

run 13 5 0 1999 no yes # single-0%
run 14 6 0 1999 no yes # multi -0%
run 15 7 0 1999 no yes # single-10%
run 16 8 0 1999 no yes # multi -10%

# thre=0.005
run 17  9 10 10 yes no # single-0%
run 18 10 10 10 yes no # multi -0%
run 19 11 10 10 yes no # single-10%
run 20 12 10 10 yes no # multi -10%

run 21  9 0 1999 no yes # single-0%
run 22 10 0 1999 no yes # multi -0%
run 23 11 0 1999 no yes # single-10%
run 24 12 0 1999 no yes # multi -10%

# thre=0.001
run 25 13 10 10 yes no # single-0%
run 26 14 10 10 yes no # multi -0%
run 27 15 10 10 yes no # single-10%
run 28 16 10 10 yes no # multi -10%

run 29 13 0 1999 no yes # single-0%
run 30 14 0 1999 no yes # multi -0%
run 31 15 0 1999 no yes # single-10%
run 32 16 0 1999 no yes # multi -10%

# debug pzres tail
run 33 1 257 257 yes no
run 34 1 128 128 yes no

run 35 1 18 18 yes no
run 36 1 16 16 yes no
run 37 1 19 19 yes no
