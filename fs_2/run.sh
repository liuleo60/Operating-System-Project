
run="40 80 160 320 640 1280"
echo "---------------------------------------------------"
echo "sequencial read"
echo "---------------------------------------------------"
for i in $run
do
    echo $i
    echo "********************seq"
    bash clean.sh
    ./radomread $i 0
    echo "-----------------------------random"
    bash clean.sh
    ./radomread $i 1
done

