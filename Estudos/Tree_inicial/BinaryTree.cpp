#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    
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
    
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    
}

/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    
}

/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const {
    
}

/**
 * @brief empties the tree
 */
void BinaryTree::clear() {
    
}

BinaryTree::~BinaryTree() {
    
}