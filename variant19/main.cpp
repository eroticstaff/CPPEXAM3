#include <iostream>
#include <memory>

template <typename T>
class LinkedList {
 private:
  struct Node {
    T data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
  };

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;

 public:
  void push_back(T data) {
    auto new_node = std::make_shared<Node>();
    new_node->data = data;
    new_node->prev = tail;
    new_node->next = nullptr;

    if (!head) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void print() {
    auto current = head;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  LinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.print();

  return 0;
}
