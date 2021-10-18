#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <vector>
using namespace std;

#include "block.hpp"

class Blockchain {
 private:
  vector<Block> blocks;
  int difficulty;
  void set_genesis_block();
  string give_last_hash();

 public:
  Blockchain(int difficulty);
  void add_block(string data);
  void display();
};

#endif
