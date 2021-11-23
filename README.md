# Crypto-mining-simulator-
* A Simple blockchain simulator built using c++.
* Current **Bitcoin** difficulty level is **17** !!!!! (Do not try this!)

## Usage

1. Build using **make** (release and debug supported)
2. ./mining_simulator [**difficulty level**] [**no of blocks to be mined**]. 
3. Example : ./mining_simulator 4 20

## Features
1. Has an option to display the blocks.
2. Displays number of tries to mine each block.
3. Currently using *SHA256* *single* hashing algorithm.
4. Difficulty level is defined by the prefix number of zeroes in the hash.
5. **Proof of Work** Implemented as the Consensus Algorithm.
6. **Merkle Trees** implemented
7. Mining reward for a single block - **25** coins
8. Wallets supported for miners
