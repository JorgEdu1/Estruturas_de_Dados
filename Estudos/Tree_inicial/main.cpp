#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree tnull;
    BinaryTree t34(34, tnull, tnull);
    BinaryTree t21(21, tnull, tnull);
    BinaryTree t76(76, t34, t21);
    BinaryTree t55(55, tnull, tnull);
    BinaryTree t1(1, t76, t55);

    t1.print_keys();
}