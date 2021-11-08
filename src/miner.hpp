#ifndef MINER_H
#define MINER_H
#include <iostream>
using namespace std;

#include "block.hpp"
#include "blockchain.hpp"
#include "wallet.hpp"

#include <memory>

class Miner {
 private:
  string name;
  int id;
  shared_ptr<Blockchain> pointer_to_chain;
  Wallet wallet;

 public:
  Miner(string name, int id, shared_ptr<Blockchain> chain);
  void mine(string data);
  void display_details();
};

#endif
