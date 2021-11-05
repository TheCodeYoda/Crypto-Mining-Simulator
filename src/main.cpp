#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#include "miner.hpp"

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

  /* create a miner */
  Miner m("Aditya", 1, difficulty);

  for (int data = 100; data < 100 + no_of_blocks_to_mine; ++data) {
    m.mine(to_string(data));
  }
  cout << "\n\n";

  cout << "Do you want to display the blockchain ?? [y/n]" << endl;
  char choice;
  cin >> choice;
  if (choice == 'y') {
    m.display_chain();
  }
}
