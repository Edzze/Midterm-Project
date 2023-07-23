// from sorted linked list
#include <iomanip>
#include <string>
class Node {
private:
  string name;
  int value;
  Node *nextPtr;
  Node *pPtr;

public:
  Node(int x = 0, string n="nothing");
  ~Node();
  Node *get_next();
  int get_data();
  void set_next(Node *t);
  void print();

  Node *get_prev();
  void set_prev(Node *t);
};

typedef Node *NodePtr;

Node::Node(int x, string n) {
  value = x;
  name = n;
  nextPtr = NULL;
  pPtr=NULL;
}

Node::~Node() { cout << name << " deleted" << endl; }

NodePtr Node::get_next() { return nextPtr; }

int Node::get_data() { return value; }

void Node::set_next(Node *t) {
  this->nextPtr = t; 
}

void Node::set_prev(Node *t)
{
  this->pPtr=t;
}

NodePtr Node::get_prev() {return pPtr;}

void Node::print(){
  cout << setw(7) << name;
  cout << setw(3) << value<<endl;
}