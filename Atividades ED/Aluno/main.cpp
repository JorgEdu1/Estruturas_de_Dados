#include <iostream>
#include <string>
using namespace std;

 struct aluno {

    string nome;
    int matricula;
    string disciplina;
    double nota;

};

aluno ler_aluno(){

    aluno ler;

    cin >> ler.nome;
    cin >> ler.matricula;
    cin >> ler.disciplina;
    cin >> ler.nota;

    return ler;
}

int main(){

    aluno a = ler_aluno();

    if(a.nota >= 7){

        cout << a.nome << " aprovado(a) em " << a.disciplina;

    }else {

        cout << a.nome << " reprovado(a) em " << a.disciplina;

    }

    return 0;
}
