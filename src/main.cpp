#include <iostream>
using namespace std;

#include "block.hpp"

int main()
{
  /* testing block creation */
  Block block1 = Block("aditya", "0000");
  Block block2 = Block("aami", "32123");
  Block block3 = Block("beast", "343242");

  block1.display();
  block2.display();
  block3.display();
}
