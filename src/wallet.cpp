#include "wallet.hpp"

Wallet::Wallet()
{
  this->balance = 0.0;
  this->private_address = "";
  this->public_address = "";
}

void Wallet::deposit(double bucks)
{
  this->balance += bucks;
}

void Wallet::withdraw(double bucks)
{
  this->balance -= bucks;
}
