#include <iostream>
using namespace std;

#include "blockchain.hpp"

/* constructs blockchain with genesis block */
Blockchain::Blockchain(int difficulty)
{
  this->set_genesis_block();
  this->difficulty = difficulty;
}

/* sets the very first block with prev hash being null hash */
void Blockchain::set_genesis_block()
{
  string null_hash = "";
  for (int i = 0; i < 64; i++) {
    null_hash += '0';
  }
  Block genesis_block = Block("genesis", null_hash, difficulty);
  this->blocks.push_back(genesis_block);
}

/* gives last blocks hash */
string Blockchain::give_last_hash()
{
  Block last_block = this->blocks.back();
  return last_block.give_hash();
}

/* adds block to the blockchain */
void Blockchain::add_block(string data)
{
  /* mines for a new block */
  Block new_block = Block(data, this->give_last_hash(), difficulty);
  this->blocks.push_back(new_block);
}

void Blockchain::display()
{
  for (Block block : this->blocks) {
    block.display();
  }
}
