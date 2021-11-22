#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <array>
#include <vector>

#include "merkle_tree.hpp"

class Block {
 private:
  std::vector<std::string> transactions;
  std::string prev_block_hash;
  std::string hash;
  std::string time;
  int miner_id;
  int difficulty;
  int transaction_capacity;
  MerkleTree mtree;
  std::string compute_valid_hash();
  bool is_hash_valid(std::string hash);

 public:
  Block(std::vector<std::string> transactions,
        std::string previous_block_hash,
        int difficulty,
        int transaction_capacity,
        int miner_id);
  void display();
  std::string give_hash();
  std::string give_prev_hash();
};
#endif
