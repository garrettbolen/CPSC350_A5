#include <iostream>
using namespace std;

template<class T>
class ListNode{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode();
  ListNode(int d);
  ~ListNode();
};
