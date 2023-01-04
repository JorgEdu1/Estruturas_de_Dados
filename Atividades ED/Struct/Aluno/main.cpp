#include <iostream>
#include <string>
using namespace std;

/*
    questao pedia que fosse criado um estrutura de aluno, e que verificasse se o aluno
    foi aprovado ou reprovado.
 */

//criando estrutura aluno
 struct aluno {
    string nome;
    int matricula;
    string disciplina;
    double nota;
};
//lendo os dados
aluno ler_aluno(){
    aluno ler;
    cin >> ler.nome;
    cin >> ler.matricula;
    cin >> ler.disciplina;
    cin >> ler.nota;
    return ler;
}
//verificando se foi aprovado ou reprovado
void verifica(aluno aluno1){
    if(aluno1.nota >= 7){
        cout << aluno1.nome << " aprovado(a) em " << aluno1.disciplina;
    }else {
        cout << aluno1.nome << " reprovado(a) em " << aluno1.disciplina;
    }
}

//funçao main que chama as anteriores.
int main(){
    aluno a = ler_aluno();
    verifica(a);

    return 0;
}
