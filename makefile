p01_chainCC=g++ -std=c++20
CFLAGS=-O0 -g -Wall
DEPS = biginteger.h bigunsigned.h
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o p01_bigint


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: chain

busqueda: main.o
	g++ -o p01_bigint main.cc biginteger.cc bigunsigned.cc $(CFLAGS)

clean:
	rm -f *.o
