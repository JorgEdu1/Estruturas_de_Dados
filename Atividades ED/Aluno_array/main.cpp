#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    //INCOMPLETA

/*
    questao pedia que recebesse 2 alunos por estrutura e verificasse quem tem maior nota.
*/

    //estrutura do aluno

 struct aluno {

    int matricula;
    string nome;
    float nota;

};

    //lendo os dados e botando na variavel da estrutura

aluno ler_aluno(){

    aluno ler;

    cin >> ler.matricula;
    getline(std::cin,ler.nome);
    cin >> ler.nota;
    

    return ler;
}

    //verifica quem tem maior nota.

void verifica(aluno aluno1, aluno aluno2){

    cout << fixed;
    cout << setprecision(1);

    if(aluno1.nota > aluno2.nota){

        cout << aluno1.nome << " , " << aluno1.nota;

    }else if(aluno2.nota > aluno1.nota){

        cout << aluno2.nome << " , " << aluno2.nota;

    }else{

        cout << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota;

    }

}

    //funçao main que chama as anteriores

int main(){

    int n;
    cin >> n;

    aluno a[n];

    for (int i = 0; i < n; i++){

        aluno a[i] = ler_aluno();
        
    }

    return 0;
}
