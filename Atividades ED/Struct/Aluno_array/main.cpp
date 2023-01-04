#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    /*
        questao pede que leia o numero de alunos que ele quer (vetor), e dps ele pede par ler
        mais uma matricula para fazer uma verificacao no vetor, se tiver um aluno com essa matricula,
        print, se nao, "nao encontrada".
    */
//cria estrutura e "funcao" ou "metodo" que le os alunos.
 struct aluno {
    int matricula;
    string nome;
    float nota;
    void ler_aluno(){
        cin >> matricula;
        cin.ignore();
        getline(std::cin, nome);
        cin >> nota;
    }
};
//verifica se existe aluno com essa matricula.
int verifica(aluno a, int aux){
    if(a.matricula == aux){
        return 1;
    }else {
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    aluno a[n];
    for (int i = 0; i < n; i++){

        a[i].ler_aluno();
        
    }
    //parte da verificacao
    int mat_check;
    cin >> mat_check;
    bool check_print = false;
    for (int i = 0; i < n; i++){ 
        if(verifica(a[i], mat_check)){
            cout << fixed;
            cout << setprecision(1);
            cout << a[i].nome << endl;
            cout << a[i].nota;
            check_print = true;
        }
     }
    if(check_print == false){
        cout << "NAO ENCONTRADA";
    }

    return 0;
}
