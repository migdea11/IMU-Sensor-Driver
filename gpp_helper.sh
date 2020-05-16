g++ -c -o main.o main.cpp -std=c++14 -g
g++ -Wall -o test main.o -std=c++14 -lpthread -lpigpio -lrt -g
