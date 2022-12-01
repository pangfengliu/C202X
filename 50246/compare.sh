for i in {1..5} ; do ./50246 < $i.in > $i ; done
for i in {1..5} ; do echo "comparing " 1-$i.out ; diff -Z $i.out $i ; done

