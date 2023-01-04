#include <iostream>
using namespace std;

// Recebe tempo em 'segundos', converte para horas, minutos e seguntos, e 
// retorna o resultado através dos parâmetros 'hor', 'min' e 'seg'.
void converte_tempo(int segundos, int *hor, int *min, int *seg){
    while(segundos >= 0){
        if(*seg > 59){
            (*min)++;
            *seg = 0;
        }
        if(*min > 59){
            (*hor)++;
            *min = 0;
        }
        (*seg)++;
        segundos--;
    }
    (*seg)--;
}

int main(){
    int tempo, h = 0, m = 0, s = 0;
    cin >> tempo;
    // Chame a função 'converte_tempo' para converter o valor de 'tempo' em horas
    // minutos e segundos, gravando o resultado nas variáveis 'h', 'm' e 's'.
    converte_tempo(tempo, &h, &m, &s);
    cout << h << ":" << m << ":" << s;
    
    return 0;
}