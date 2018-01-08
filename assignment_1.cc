#include <iostream>
using namespace std;

class Node {
  Node *parent;
  Node *firstChild;
  Node *lastChild;
  Node *prev;
  Node *next;

  public:
    void append(Node *node) {
      Node *currentLast;
      currentLast = this->lastChild;

      currentLast->next = node;
      node->prev = currentLast;
      node->parent = this;
    };

    void before(Node *node) {
      Node *currentPrev;
      currentPrev = this->prev;

      currentPrev->next = node;
      node->next = currentPrev;
      node->prev = currentPrev;
    };

    void remove() {
    }
};

int main()
{
  Node *parentNode, *newNode;
  parentNode->append(newNode);
}
