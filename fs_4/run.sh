run="1 2 3 4 5 6 7 8"
size=200

for i in $run
do
    echo $i
    bash clean.sh
    ./r $size $i
done

