#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main(){
    SparseMatrix m(3, 3);
    m.insert(1,2,1);
    //m.insert(1,2,2);
    //m.insert(1,3,3);
    //m.insert(2,1,4);
    //m.insert(2,2,5);
    //m.insert(2,3,6);
    //m.insert(3,1,7);
    //m.insert(3,2,8);
    //m.insert(3,3,9);
    m.print();
    return 0;
}
