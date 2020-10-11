#include <iostream>
struct node {
  node *next;
  int val;
};

int main() {
  node *head = new node;
  node *pt = head;
  for (i = 0; i < l; i++) {
    std::cin >> pt->val;
    pt = pt->next;
  }

  return 0;
}