#include <iostream>
#include <string>
using namespace std;

#include "block.hpp"
#include "sha256.hpp"

Block::Block(string data, string previous_block_hash, int difficulty)
{
  this->data = data;
  this->difficulty = difficulty;
  this->prev_block_hash = previous_block_hash;
  this->hash = this->compute_valid_hash(data, previous_block_hash);
}

/* checks whether hash starts with 3 zeroes */
bool Block::is_hash_valid(string hash)
{
  /* cout << "tried hash: " << hash << endl; */
  for (int match = 0; match < this->difficulty; ++match) {
    if (hash[match] != '0') {
      return false;
    }
  }
  return true;
  /* if (hash[0] == '0' && hash[1] == '0' && hash[2] == '0') */
  /*   return true; */
  /* return false; */
}

/* calculates valid hash for the block (similar to mining)*/
string Block::compute_valid_hash(string data, string previous_block_hash)
{
  string hash = "";
  int nonce = 0;

  while (!is_hash_valid(hash)) {
    string input_string = data + "\t" + previous_block_hash + to_string(nonce);
    hash = sha256(input_string);
    ++nonce;
  }

  return hash;
}

void Block::display()
{
  cout << "data: " << this->data << endl;
  cout << "previous block hash: " << this->prev_block_hash << endl;
  cout << "current block hash: " << this->hash << endl;
  cout << endl;
}

string Block::give_hash()
{
  return this->hash;
}
