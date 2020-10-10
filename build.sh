#gcc -Wall main.c index.c -o prog 
#  -flinker-output=pie
#  -print-search-dirs \
#  -B `pwd`/index \
#  -c \
#  -Wall -o prog main.c
pushd build
cmake -G "Unix Makefiles" ../
make
popd