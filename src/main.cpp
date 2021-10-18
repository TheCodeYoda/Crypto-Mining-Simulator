#include <cstdio>
#include <iostream>
#include <ostream>
using namespace std;

#include "blockchain.hpp"

void welcome_message(int difficulty, int blocks)
{
  cout << "Welcome to the crypto mining simulator using SHA-256....\n";
  cout << "Lets Mine " << blocks << " block[s] with difficulty level " << difficulty
       << ".... ..... .... .... ....\n\n";
}

int main(int argc, char **argv)
{
  if (argc < 3) {
    cerr << "please supply the required arguments" << endl;
  }

  int difficulty = atoi(argv[1]);
  int no_of_blocks_to_mine = atoi(argv[2]);
  welcome_message(difficulty, no_of_blocks_to_mine);
  Blockchain chain(difficulty);

  /* adding blocks to blockchain */
  for (int i = 1; i <= no_of_blocks_to_mine; i++) {
    cout << "\rmining block: " << i << "/" << no_of_blocks_to_mine << flush;
    chain.add_block(to_string(i));
  }
  cout << "\n\n";
  chain.display();
}
