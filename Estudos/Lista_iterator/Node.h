#ifndef NODE_H
#define	NODE_H
#include <iostream>
template <typename T>
struct Node {
        T value;
        Node<T> *next;
        Node<T> *prev;

        Node(const T& value, Node *prev, Node *next) {
            this->value = value;
            this->next = prev;
            this->prev = prev;
        }
        ~Node() {
            std::cout << "Node " << value << " destroyed" << std::endl;
        }
};
#endif