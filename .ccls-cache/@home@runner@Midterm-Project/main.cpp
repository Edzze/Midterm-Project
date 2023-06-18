#include "menu.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "sorting.h"
using namespace std;

int main() {
  const int MAX_SNACKS = 10;
  pair<string, int>* s[MAX_SNACKS]; // Array of pointers to store snacks
  snack n[MAX_SNACKS];
  n[0] = snack("Sherlock's Sleuth Snacks", 10);
  n[1] = snack("Nancy Drew's Nutty Delights", 20);
  n[2] = snack("Poirot's Chocolate Mysteries", 50);
  n[3] = snack("Miss Marple's Tea-Time Treats", 40);
  n[4] = snack("Hardy Boys' Mystery Munchies", 60);
  n[5] = snack("Magnum P.I.'s Tropical Trail Mix", 10);
  n[6] = snack("Veronica Marshmallow Delights", 90);
  n[7] = snack("Monk's Obsessive Crisps", 20);
  n[8] = snack("Jessica Fletcher's Murder Mystery Macarons", 45);
  n[9] = snack("Columbo's Crumbled Clues Cookies", 85);

  int i, m, c, total_amount = 0, total_cost = 0, x = 0;
  cout << "Welcome to the Detective Snack Bar!!!" << endl<<endl;
  cout
      << "What would you like to order? Please enter the number of the product."
      << endl;

  do {
    for (i = 0; i < 10; i++) {
      cout << i + 1 << ". " << n[i].get_name() << " Price: " << n[i].get_price()<< " Amount Left: " << n[i].get_amount() << endl;
    }
    cout << "Amount: " << total_amount << endl;
    cout << "Total cost: " << total_cost << endl<<endl;
    cout << "What else would you like to order?"<< endl;
    cout<< "If your order is finished, please enter 0."<<endl;
    cin >> m;
    if (m == 0)
      break;
    cout << n[m - 1].get_name() << endl;
    cout << "What is the amount you would like to buy?" << endl;
    do {
      c=0;
      cin >> c;
      if (c > n[m - 1].get_amount()) {
        cout << "Cannot complete the request due to amount exceeding the stock."<< endl;
        cout << "Please try again." << endl;
      } 
      else if (c <= n[m - 1].get_amount()) {
        n[m - 1].buy(c);
        total_cost += n[m - 1].get_price() * c;
        total_amount += c;
        n[m - 1].check();
        n[m - 1].return_price(c);
        break;
      }
    } while (c > n[m - 1].get_amount());

  } while (m != 0);

  for (i = 0; i < 10; i++) {
    if (n[i].return_check() == true) {
      s[x] = new pair<string, int>(n[i].get_name(), n[i].get_price() * c);
      x++;
    }
  }
  sorting(s,x);
  cout<<"====================="<<endl;
  cout<<"      Receipt      "<<endl;
  cout<<"====================="<<endl<<endl;
  display (s,x);
  cout<<"Total: "<<total_cost<<" Baht"<<endl;
  cout<<"Thank you for visting us. Hope you would come again!!!"<<endl;

  for (int i = 0; i < x; i++) {
  delete s[i];
}
}