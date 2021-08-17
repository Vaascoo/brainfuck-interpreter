CC = g++
CFLAGS = -O3 -Wall
all: bf main
	$(CC) $(CFLAGS) -o interpreter bf.o main.o
main:
	$(CC) $(CFLAGS) -c main.cpp -o main.o

bf:
	$(CC) $(CFLAGS) -c bf.cpp -o bf.o
run:
	./interpreter
clean:
	rm *.o interpreter
