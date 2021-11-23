#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <vector>
using namespace std;

#include "block.hpp"
#include "mempool.hpp"

class Blockchain {
 private:
  vector<Block> blocks;
  Mempool mpool;
  int difficulty;
  int transaction_capacity;
  void set_genesis_block(vector<string> transaction_slice, int miner_id);
  void add_block(vector<string> transactions, int miner_id);
  string give_last_hash();

 public:
  Blockchain();
  Blockchain(int difficulty);
  Blockchain(int difficulty, int transaction_capacity);
  int add_transaction(string transaction, int miner_id);
  bool validate_blockchain();
  void display();
  int get_transaction_capacity();
};
#endif
