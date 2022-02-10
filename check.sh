#!/bin/bash
make &&
rm -f original_only.txt ft_only.txt &&
make re "MYCFLAG=-D ORIGINAL_ONLY" &&
./test.out > original_only.txt &&
make re "MYCFLAG=-D FT_ONLY" &&
./test.out > ft_only.txt &&
diff -s original_only.txt ft_only.txt