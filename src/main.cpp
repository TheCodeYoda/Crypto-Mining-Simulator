#include <iostream>
using namespace std;

#include "blockchain.hpp"

int main()
{
  Blockchain chain(3);

  /* adding blocks to blockchain */
  for (int i = 1; i < 11; i++) {
    cout << "mining block " << i << "....." << endl;
    chain.add_block(to_string(i));
  }
  chain.display();
}
