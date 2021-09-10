#include <iostream>
using namespace std;

#include "blockchain.hpp"

int main()
{
  Blockchain chain;

  /* adding blocks to blockchain */
  for (int i = 1; i < 11; i++) {
    chain.add_block(to_string(i));
  }
  chain.display();
}
