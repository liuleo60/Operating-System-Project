pkill iostat;
pkill sar;
iostat -dx 1 > iostat.log &
sar -B 1 1000 > sar.log &
