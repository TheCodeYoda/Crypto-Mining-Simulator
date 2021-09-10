#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
 private:
  std::string data;
  std::string prev_block_hash;
  std::string hash;
  std::string compute_valid_hash(std::string, std::string);
  bool is_hash_valid(std::string hash);

 public:
  Block(std::string data, std::string previous_block_hash);
  void display();
  std::string give_hash();
};
#endif
