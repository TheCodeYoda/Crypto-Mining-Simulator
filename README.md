# Crypto-mining-simulator-
* A Simple blockchain simulator built using c++.
* Currently using *SHA256* *single* hashing algorithm.
* Difficulty level is defined by the prefix number of zeroes in the hash.
* The network keeps mining the block till it finds a block whose hash matches the difficulty level.
* Current **Bitcoin** difficulty level is **17** !!!!! (Do not try this!)

## Usage

1. Build using **make** (release and debug supported)
2. ./mining_simulator [**difficulty level**] [**no of blocks to be mined**]. 
3. Example : ./mining_simulator 4 20

## Features
1. Has an option to display the blocks.
2. Displays number of tries to mine each block.
3. First block is *genesis* block, this is not counted.
