#ifndef WALLET_H
#define WALLET_H

#include <iostream>
using namespace std;

class Wallet {
 private:
  double balance;
  string private_address;

 public:
  string public_address;
  Wallet();
  void deposit(double bucks);
  void withdraw(double bucks);
};
#endif
