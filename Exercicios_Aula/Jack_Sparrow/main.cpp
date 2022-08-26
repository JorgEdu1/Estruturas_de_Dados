#include <string>
#include <iostream>
using namespace std;

char paraMaiusculo(char inverter){

    if(inverter >= 'a' && inverter <= 'z'){

        return inverter - 32;

    }

}

char paraMinisculo(char inverter){

    if(inverter >= 'A' && inverter <= 'Z'){

        return inverter + 32;

    }

}

int main() {

    int n;
    cin >> n;
    string line;
    int recuo;

    cin.ignore();
    
    for(int i = 0; i < n; i++) {
    
        
        getline(cin, line);

        for(int i = 1; i < line.size(); i++) {

            recuo = 1;

            if(line[i-recuo] == ' '){

                recuo = 2;

            }   
        
            if(line[i-recuo] >= 'a' && line[i-recuo] <= 'z'){

                line[i] = paraMaiusculo(line[i]);

            }else if(line[i-recuo] >= 'A' && line[i-recuo] <= 'Z'){

                line[i] = paraMinisculo(line[i]);

            }

        recuo = 1;

    }

    cout << line << endl;

    }

    return 0;
}
