gcc file_cache.c -o file_cache

SWAP=0
echo $SWAP

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 62000 data_250M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 125000 data_500M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 250000 data_1G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 500000 data_2G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 1000000 data_4G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 2000000 data_8G.dat

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 4000000 data_16G.dat

SWAP=60
echo $SWAP

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 62000 data_250M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 125000 data_500M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 250000 data_1G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 500000 data_2G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 1000000 data_4G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 2000000 data_8G.dat

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 4000000 data_16G.dat

SWAP=100
echo $SWAP

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 62000 data_250M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 125000 data_500M.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 250000 data_1G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 500000 data_2G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 1000000 data_4G.dat


sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 2000000 data_8G.dat

sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/drop_caches
echo $SWAP > /proc/sys/vm/swappiness

./file_cache 4000000 data_16G.dat
