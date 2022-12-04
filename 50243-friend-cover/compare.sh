for i in {1..10} ; do ./50243 < 1-$i.in > $i ; done
for i in {1..10} ; do echo "comparing " 1-$i.out ; diff -Z 1-$i.out $i ; done

