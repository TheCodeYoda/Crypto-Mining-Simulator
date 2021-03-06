#include <iostream>
using namespace std;

#include "blockchain.hpp"

/* Default constructor */

Blockchain::Blockchain()
{
  this->difficulty = 3;
  this->transaction_capacity = 4;
}

/* constructs blockchain with given difficulty*/
Blockchain::Blockchain(int difficulty)
{
  this->difficulty = difficulty;
  this->transaction_capacity = 4;
}

/* constructs blockchain with given difficulty and given transaction capacity*/
Blockchain::Blockchain(int difficulty, int transaction_capacity)
{
  this->difficulty = difficulty;
  this->transaction_capacity = transaction_capacity;
}

/* add transaction to the blockchain returns 1 if creating new block*/

int Blockchain::add_transaction(string transaction, int miner_id)
{
  this->mpool.add_transaction_to_pool(transaction);
  /* create block if mpool has 4 transactions */
  if (this->mpool.size() == this->transaction_capacity) {
    vector<string> slice(mpool.transaction_pool.begin(), mpool.transaction_pool.end());
    if (this->blocks.size() == 0) {
      this->set_genesis_block(slice, miner_id);
    }
    else {
      this->add_block(slice, miner_id);
    }
    this->mpool.clear();
    return 1;
  }
  return 0;
}

/* sets the very first block with prev hash being null hash */
void Blockchain::set_genesis_block(vector<string> transaction_slice, int miner_id)
{
  string null_hash = "";
  for (int i = 0; i < 64; i++) {
    null_hash += '0';
  }
  Block genesis_block = Block(
      transaction_slice, null_hash, this->difficulty, this->transaction_capacity, miner_id);
  this->blocks.push_back(genesis_block);
}

/* gives last blocks hash */
string Blockchain::give_last_hash()
{
  Block last_block = this->blocks.back();
  return last_block.give_hash();
}

/* adds block to the blockchain */
void Blockchain::add_block(vector<string> transactions, int miner_id)
{
  /* mines for a new block */
  Block new_block = Block(transactions,
                          this->give_last_hash(),
                          this->difficulty,
                          this->transaction_capacity,
                          miner_id);
  this->blocks.push_back(new_block);
}

/* validates blockchain */
bool Blockchain::validate_blockchain()
{
  if (!this->blocks.size()) {
    return true;
  }
  Block prev = blocks[0];
  for (int i = 1; i < blocks.size(); i++) {
    Block curr = blocks[i];
    if (curr.give_prev_hash() != prev.give_hash())
      return false;
    prev = curr;
  }
  return true;
}

/* transaction capacity getter */
int Blockchain::get_transaction_capacity()
{
  return this->transaction_capacity;
}

void Blockchain::display()
{
  for (Block block : this->blocks) {
    block.display();
  }
}
