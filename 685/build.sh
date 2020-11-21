g++ -std=c++14 -pthread -lm -O3 -g ${1}.cpp -o ${1}.o
./${1}.o < ${1}.txt > debug.txt