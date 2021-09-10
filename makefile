debug: block.o main.o sha256.o blockchain.o
	g++ -g block.o main.o sha256.o blockchain.o -o debug

sha256.o: src/sha256.cpp src/sha256.hpp
	g++ -c src/sha256.cpp	

block.o: src/block.cpp src/block.hpp
	g++ -c src/block.cpp

blockchain.o: src/blockchain.cpp src/blockchain.hpp
	g++ -c src/blockchain.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm *.o

clean_all:
	rm *.o debug
