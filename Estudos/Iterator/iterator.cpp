#include <iostream>
#include <vector>
using namespace std;
//site com todas as funcoes do vector -> cplusplus.com

void print(const vector<int>& vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec {1,2,3,4,5,5,5,5,6,7,5,5,5,5,5,8};
    print(vec);
    auto it = vec.begin();
    while (it != vec.end()){
        if(*it == 5){
            it = vec.erase(it);
        }else {
            it++;
        }
    }  
    print(vec);

    return 0;
}