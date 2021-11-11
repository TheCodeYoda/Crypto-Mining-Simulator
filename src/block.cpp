#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
using namespace std;

#include "block.hpp"
#include "sha256.hpp"

Block::Block(vector<string> transactions, string previous_block_hash, int difficulty, int miner_id)
{

  this->difficulty = difficulty;
  this->prev_block_hash = previous_block_hash;
  /* setting index for the freshblock and filling the transaction array */
  int index = 0;
  while (index != 4) {
    this->transactions[index] = transactions[index];
    ++(index);
  }
  /* initializing merkle tree */
  mtree.initialize(transactions);
  this->hash = compute_valid_hash();
  /* setting timestamp */
  time_t res = std::time(nullptr);
  this->time = ctime(&res);
  usleep(1000000); /*  to avoid duplicate time stamps*/

  /* set creator_id */
  this->miner_id = miner_id;
}

/* checks whether hash starts with 3 zeroes */
bool Block::is_hash_valid(string hash)
{
  for (int match = 0; match < this->difficulty; ++match) {
    if (hash[match] != '0') {
      return false;
    }
  }
  return true;
}

/* calculates valid hash for the block (similar to mining)*/
string Block::compute_valid_hash()
{
  string hash = "";
  int nonce = 0;
  unsigned long long trie = 1;

  /* Merkle tree hashing process */
  this->mtree.build();
  this->mtree.display();
  string merkle_root_hash = this->mtree.root->data;

  while (!is_hash_valid(hash)) {
    cout << "\rtries: " << trie << flush;
    string input_string = merkle_root_hash + "\t" + this->time + "\t" + this->prev_block_hash +
                          to_string(nonce);
    hash = sha256(input_string);
    ++nonce;
    ++trie;
  }
  cout << "\n\n";

  return hash;
}

void Block::display()
{
  cout << "data: "
       << "{";
  for (auto transaction : this->transactions) {
    cout << transaction << ", ";
  }
  cout << "}" << endl;

  cout << "previous block hash: " << this->prev_block_hash << endl;
  cout << "current block hash: " << this->hash << endl;
  cout << "timestamp: " << this->time;
  cout << "Created by miner: " << this->miner_id << endl;
  cout << endl;
}

string Block::give_hash()
{
  return this->hash;
}

string Block::give_prev_hash()
{
  return this->prev_block_hash;
}
