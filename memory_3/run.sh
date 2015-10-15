free > memory.log | grep total
free >> memory.log | grep Mem
sleep 1
./pagefault
sleep 1
pkill sar
pkill iostat
free >> memory.log | grep Mem

bash clean.sh
