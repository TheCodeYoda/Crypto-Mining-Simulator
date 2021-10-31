#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
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
    cout << "mining block: " << i << "/" << no_of_blocks_to_mine << endl;
    chain.add_block(to_string(i));
  }
  cout << "\n\n";

  cout << "Do you want to display the blockchain ?? [y/n]" << endl;
  char choice;
  cin >> choice;
  if (choice == 'y') {
    chain.display();
  }

  if (!chain.validate_blockchain()) {
    cerr << "!!!!!!!!!!!!! Blockchain tampered !!!!!!!!!!!!!!!!" << endl;
  }
}
