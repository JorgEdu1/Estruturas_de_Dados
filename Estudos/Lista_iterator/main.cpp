#include <iostream>
#include "List.h"
#include <vector>
using namespace std;

int main(){
    vector<int> vec{1,2,3,4,5,6};
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << endl;
    }

    /*List<float> lista;

    for (int i = 0; i < 9; i++){
        lista.push_back(i);
    }
    for (int i = 0; i < 9; i++){
        cout << lista[i] << endl;
    }*/

    return 0;
}
