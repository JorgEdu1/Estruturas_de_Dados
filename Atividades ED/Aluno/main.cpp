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

void verifica(aluno aluno1){

    if(aluno1.nota >= 7){

        cout << aluno1.nome << " aprovado(a) em " << aluno1.disciplina;

    }else {

        cout << aluno1.nome << " reprovado(a) em " << aluno1.disciplina;

    }

}

int main(){

    aluno a = ler_aluno();
    verifica(a);

    return 0;
}
