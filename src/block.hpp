#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
 private:
  std::string data;
  std::string prev_block_hash;
  std::string hash;
  std::string time;
  int miner_id;
  int difficulty;
  std::string compute_valid_hash();
  bool is_hash_valid(std::string hash);

 public:
  Block(std::string data, std::string previous_block_hash, int difficulty, int miner_id);
  void display();
  std::string give_hash();
  std::string give_prev_hash();
};
#endif
