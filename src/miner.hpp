#ifndef MINER_H
#define MINER_H
#include <iostream>
using namespace std;

#include "block.hpp"
#include "blockchain.hpp"

class Miner {
 private:
  string name;
  int id;
  Blockchain chain;

 public:
  Miner(string name, int id, int difficulty);
  void mine(string data);
  void display_chain();
};

#endif
