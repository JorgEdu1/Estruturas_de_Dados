#include "ForwardList.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    ForwardList lst;
    for(int i=1; i<10; i++){
        lst.push_back(i);
    }
    cout << lst.toString() << endl;
    //lst.~ForwardList();

    return 0;
}