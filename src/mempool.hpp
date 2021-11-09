#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <vector>
#include <iostream>
using namespace std;

class Mempool {
 public:
  vector<string> transaction_pool;
  void add_transaction_to_pool(string transaction)
  {
    transaction_pool.push_back(transaction);
  }
  int size()
  {
    return transaction_pool.size();
  }

  void clear()
  {
    transaction_pool.clear();
  }
};

#endif
