debug: block.o main.o sha256.o
	g++ block.o main.o sha256.o -o debug

sha256.o: src/sha256.cpp src/sha256.hpp
	g++ -c src/sha256.cpp	

block.o: src/block.cpp src/block.hpp
	g++ -c src/block.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm *.o

clean_all:
	rm *.o debug
