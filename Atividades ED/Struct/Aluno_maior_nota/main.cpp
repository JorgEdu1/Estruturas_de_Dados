#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
    questao pedia que recebesse 2 alunos por estrutura e verificasse quem tem maior nota.
*/

    //estrutura do aluno

 struct aluno {

    string nome;
    int matricula;
    string disciplina;
    double nota;

};

    //lendo os dados e botando na variavel da estrutura

aluno ler_aluno(){

    aluno ler;

    cin >> ler.nome;
    cin >> ler.matricula;
    cin >> ler.disciplina;
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

    aluno a = ler_aluno();
    aluno b = ler_aluno();
    verifica(a,b);

    return 0;
}
