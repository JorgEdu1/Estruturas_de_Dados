#ifndef NODE_H
#define NODE_H
struct Node{
    Node *right;
    Node *down;
    int row;
    int col;
    double value;
    Node(Node *right, Node *down, int row, int col, double value){
        this->right = right;
        this->down = down;
        this->row = row;
        this->col = col;
        this->value = value;
    }
};
#endif