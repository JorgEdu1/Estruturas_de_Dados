#include <iostream>
using namespace std;

//torre de hanoi 4 pinos
void hanoi(int n, int origem, int destino, int auxiliar1, int auxiliar2)
{
    if (n == 1)
    {
        cout << "Mova o disco " << n << " do pino " << origem << " para o pino " << destino << endl;
    }
    else
    {
        hanoi(n - 1, origem, auxiliar1, auxiliar2, destino);
        cout << "Mova o disco " << n << " do pino " << origem << " para o pino " << destino << endl;
        hanoi(n - 1, auxiliar2, destino, origem, auxiliar1);
    }
}  

int main()
{
    int n;
    cout << "Digite o numero de discos: ";
    cin >> n;
    hanoi(n, 1, 4, 2, 3);
    return 0;
}