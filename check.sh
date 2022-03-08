#!/bin/bash

if [ $# -eq 0 ]; then
  FLG_M="TRUE" ;
fi

while getopts abm OPT
do
  case $OPT in
    "a" ) FLG_B="TRUE" ; FLG_M="TRUE" ;;
    "b" ) FLG_B="TRUE" ;;
    "m" ) FLG_M="TRUE" ;;
      * ) echo "Usage: $CMDNAME [-a|-b|-m]" 1>&2
          exit 1 ;;
  esac
done

# Mandetory
if [ "$FLG_M" = "TRUE" ]; then
  make &&
  rm -f original_only.txt ft_only.txt &&
  make re "MYCFLAGS=-D ORIGINAL_ONLY" &&
  ./test.out > original_only.txt &&
  make re "MYCFLAGS=-D FT_ONLY" &&
  ./test.out > ft_only.txt &&
  diff -s original_only.txt ft_only.txt
fi

# Bonus
if [ "$FLG_B" = "TRUE" ]; then
  make &&
  rm -f original_only.txt ft_only.txt &&
  make fclean bonus "MYCFLAGS=-D ORIGINAL_ONLY" &&
  ./test_bonus.out > original_only.txt &&
  make fclean bonus "MYCFLAGS=-D FT_ONLY" &&
  ./test_bonus.out > ft_only.txt &&
  diff -s original_only.txt ft_only.txt
fi
