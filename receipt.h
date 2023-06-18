#ifndef receipt_h
#define receipt_h
#include "menu.h"
#include "sorting.h"
#include <iostream>
using namespace std;

class receipt {
private:
  string name;
  int amount;
  int price;
  int bought;

public:
  void sort();
  void type();
  void set_receipt(int s[], int x);
  receipt(string n = "Nothing", int x = 0);
  ~receipt();
};

receipt::receipt(string n, int x) {
  name = n;
  price = x;
}

#endif 