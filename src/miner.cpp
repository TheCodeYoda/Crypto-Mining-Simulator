#include "miner.hpp"
#include "blockchain.hpp"

Miner::Miner(string name, int id, int difficulty)
{
  this->name = name;
  this->id = id;
  this->chain = Blockchain(difficulty);
}

void Miner::mine(string data)
{
  this->chain.add_block(data);
  if (!chain.validate_blockchain()) {
    cerr << "!!!!!!!!!!!!! Blockchain tampered !!!!!!!!!!!!!!!!" << endl;
  }
}

void Miner::display_chain()
{
  this->chain.display();
}
