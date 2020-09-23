#!/bin/bash

####################################################################################################
# Script to extract core file information
####################################################################################################

if [ $# ne 2 ]; then
  echo "Usage: `basename $0` <Binary that crashed> <Core file name>"
  exit -1
fi

####################################################################################################
# Use below if you want to look at all the cores in a loop
####################################################################################################
# Find Today's and Yesterday's files in this dir
# cores=`find . -name 'core.*' -mtime -1`

binimg=$1
core=$2
logfile="$core-gdb.log"
rm $logfile

bininfo=`ls -l $binimg`
coreinfo=`ls -l $core`

gdb -batch \
  -ex "set logging file $logfile" \
  -ex "set logging on" \
  -ex "set pagination off" \
  -ex "printf ****************************************************************************************\n" \
  -ex "printf \"**\n** Process info for $binimg - $core \n** Generated `date`\n\"" \
  -ex "printf \"**\n** $bininfo \n** $coreinfo \n**\n\"" \
  -ex "printf ****************************************************************************************\n" \
  -ex "file $binimg" \
  -ex "core-file $core" \
  -ex "bt" \
  -ex "info proc" \
  -ex "printf \"*\n* Libraries \n*\n\"" \
  -ex "info sharedlib" \
  -ex "printf \"*\n* Memory Map \n*\n\"" \
  -ex "info target" \
  -ex "printf \"*\n* Registers \n*\n\"" \
  -ex "info registers" \
  -ex "printf \"*\n* Current Instructions \n*\n\"" \
  -ex "x/16i \$pc" \
  -ex "printf \"*\n* Threads (full) \n*\n\"" \
  -ex "info threads" \
  -ex "bt" \
  -ex "thread apply all bt full" \
  -ex "printf \"*\n* Threads (basic) \n*\n\"" \
  -ex "info threads" \
  -ex "thread apply all bt" \
  -ex "printf \"*\n* Done \n*\n\"" \
  -ex "quit"
