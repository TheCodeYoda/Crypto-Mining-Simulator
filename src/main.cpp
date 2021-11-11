#include "blockchain.hpp"
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

  /* create a Blockchain */

  shared_ptr<Blockchain> chain(new Blockchain(difficulty));

  /* create miners */
  Miner m1("Aditya", 1, chain);

  Miner m2("Mike", 2, chain);

  /*Block addition by multiple miners*/
  for (int data = 100; data < 100 + no_of_blocks_to_mine * 4; ++data) {
    /* m1.display_details(); */
    /* cout << "the above miner is mining... .... .... ...\n"; */
    m1.mine(to_string(data));
  }
  cout << "\n\n";

  /* Displaying the blockchain */
  cout << "Do you want to display the blockchain ?? [y/n]" << endl;
  char choice;
  cin >> choice;
  if (choice == 'y') {
    chain->display();
  }
}
