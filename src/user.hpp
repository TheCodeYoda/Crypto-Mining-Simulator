#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
 private:
  string name;
  string uid;

 public:
  void add_transaction();
};
#endif
