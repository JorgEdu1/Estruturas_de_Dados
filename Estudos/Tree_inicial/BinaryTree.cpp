#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 * 
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    root = new Node(value, lchild.root, rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    return !is_empty() && root->left == nullptr && root->right == nullptr;
}

/**
 * @brief Indicate if the tree contains the given value
 * 
 * @param value The value to search for
 * @return true if the value is found
 * @return false if the value is not found
 */
bool contains_recursive(Node *node, int value){
    if(node == nullptr)
        return false;
    if(node->key == value)
        return true;
    return contains_recursive(node->left, value) || contains_recursive(node->right, value);
}

/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    return contains_recursive(root, value);
}

/**
 * @brief Print the keys saved on the tree
 */
void print_keys_recursive(Node *node) {
    if(node == nullptr){
        return;
    }
    else{
        cout << node->key << " ";
        print_keys_recursive(node->left);
        print_keys_recursive(node->right);
    }
}
/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const {
    print_keys_recursive(root);
}

Node* clear_recursive(Node *node){
    if(node == nullptr)
        return nullptr;
    clear_recursive(node->left);
    clear_recursive(node->right);
    delete node;
    return nullptr;
}

/**
 * @brief empties the tree
 */
void BinaryTree::clear() {
    root = clear_recursive(root);
}

BinaryTree::~BinaryTree() {
    clear();
}