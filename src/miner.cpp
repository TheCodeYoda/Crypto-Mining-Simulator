#include "miner.hpp"
#include "blockchain.hpp"

Miner::Miner(string name, int id, shared_ptr<Blockchain> chain)
{
  this->name = name;
  this->id = id;
  this->pointer_to_chain = chain;
}

void Miner::mine(string data)
{
  /* status 1 siginifies a new block was mined(proof of work) */
  int status = this->pointer_to_chain->add_transaction(data, this->id);
  if (!pointer_to_chain->validate_blockchain()) {
    cerr << "!!!!!!!!!!!!! Blockpointer_to_chain tampered !!!!!!!!!!!!!!!!" << endl;
    return;
  }
  if (status) {
    this->wallet.deposit(25.00);
  }
}

void Miner::display_details()
{
  cout << "Miner name : " << this->name << endl;
  cout << "Miner id: " << this->id << endl;
  this->wallet.display();
  cout << "\n";
}
