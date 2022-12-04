for i in {0..9} ; do ./10327 < $i.in > $i ; done
for i in {0..9} ; do echo "comparing " $i.out ; diff -Z $i.out $i ; done

