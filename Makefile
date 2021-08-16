all: bf main
	g++ -g -O3 -o interpreter bf.o main.o
main:
	g++ -g -O3 -c main.cpp -o main.o

bf:
	g++ -g -O3 -c bf.cpp -o bf.o
run:
	./interpreter
clean:
	rm *.o interpreter