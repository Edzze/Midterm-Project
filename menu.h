#ifndef menu_h
#define menu_h
#include <iostream>
using namespace std;

class snack 
{
private:
string name;
int price;
int amount;
bool isBought = false;
int bought;

public:
int get_price() {return price;}
string get_name() {return name;}
int get_amount() {return amount;}
void set_empty();
void return_price(int c);
void check();
bool return_check(){return isBought;}
string return_string();
pair<string, int> get_snack();
int return_bought();
int buy(int x);
snack(string n="Nothing", int p=0, int x= rand()%20+1, int b=0);
~snack();
};

snack::snack(string n, int p, int x,int b)
{
  name=n;
  price=p;
  amount=x;
  bought=b;
}

void snack::set_empty()
{
  name="Out of Stock";
}

int snack::buy(int x)
{
  amount -= x;
  return amount;
}

void snack::check()
{
  isBought=true;
}

void snack::return_price(int c)
{
  bought += price*c;
}

pair<string, int> snack::get_snack() {
    return make_pair(name, bought); 
}

int snack::return_bought()
{
  return bought;
}


snack::~snack()
{
  //cout<<"Order for "<<amount<<name<<"(s) has been destroyed"<<endl;
}


#endif