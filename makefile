# debug: block.o main.o sha256.o blockchain.o
# 	g++ -g block.o main.o sha256.o blockchain.o -o debug

# sha256.o: src/sha256.cpp src/sha256.hpp
# 	g++ -c src/sha256.cpp	

# block.o: src/block.cpp src/block.hpp
# 	g++ -c src/block.cpp

# blockchain.o: src/blockchain.cpp src/blockchain.hpp
# 	g++ -c src/blockchain.cpp

# main.o: src/main.cpp
# 	g++ -c src/main.cpp

# clean:
# 	rm *.o

# clean_all:
# 	rm *.o debug
CC = g++
ifeq (%{mode}, release)
	FLAGS = -O3 -march=native -std=c++17
else
	mode = debug
	FLAGS = -O0 -g -std=c++17
endif

INCLUDES = 
LIB_FLAGS =
OBJS = block.o blockchain.o sha256.o
PROJECT_NAME = mining_simulator

ifeq (${mode}, debug)
	PROJECT = ${PROJECT_NAME}_debug
else
	PROJECT = ${PROJECT_NAME}
endif

${PROJECT}: ${OBJS} main.o clean_emacs_files
	@echo "Building on "${mode}" mode"
	@echo ".........................."
	${CC} ${INCLUDES} ${FLAGS} ${OBJS} main.o -o $@
	-make clean

main.o:
	${CC} ${INCLUDES} ${FLAGS} -c src/main.cpp -o $@

blockchain.o:
	${CC} ${INCLUDES} -c src/blockchain.cpp -o $@

sha256.o:
	${CC} ${INCLUDES} -c src/sha256.cpp -o $@

block.o:
	${CC} ${INCLUDES} -c src/block.cpp -o $@

.PHONEY: clean clean_emacs_files clean_all
clean:
	-rm -rf ${OBJS} main.o
clean_emacs_files:
	-rm -rf *~
clean_all: clean clean_emacs_files
	-rm -rf ${PROJECT_NAME} ${PROJECT_NAME}_debug

