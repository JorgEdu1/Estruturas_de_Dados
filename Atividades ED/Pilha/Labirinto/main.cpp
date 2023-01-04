#include <iostream>
#include <vector> 
#include <stack>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}


int main(){
    int nl = 0, nc = 0, cont = 1;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }

    //procurando caminho
    stack<Pos> pilha;
    pilha.push(inicio);
    while(!pilha.empty()){
        Pos atual = pilha.top();
        pilha.pop();
        if(atual.l == fim.l && atual.c == fim.c){
            break;
        }
        vector<Pos> vizinhos = get_vizinhos(atual);
        for(Pos p : vizinhos){
            if(p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc && mat[p.l][p.c] == ' '){
                pilha.push(p);
                mat[p.l][p.c] = 'X';
                for(int l = 0; l < nl; l++){
                    for(int c = 0; c < nc; c++){
                        cout << mat[l][c];
                    }
                    cout << endl;
                }
                cout << cont << "Vez" << endl;
                cont++;                
            }
        }
    }

    stack<Pos> pilha2;
    pilha2.push(fim);
    while(!pilha2.empty()){
        Pos atual = pilha2.top();
        pilha2.pop();
        if(atual.l == inicio.l && atual.c == inicio.c){
            break;
        }
        vector<Pos> vizinhos = get_vizinhos(atual);
        for(Pos p : vizinhos){
            if(p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc && mat[p.l][p.c] == 'X'){
                pilha2.push(p);
                mat[p.l][p.c] = '.';
                for(int l = 0; l < nl; l++){
                    for(int c = 0; c < nc; c++){
                        cout << mat[l][c];
                    }
                    cout << endl;
                }
                cout << cont << "Vez" << endl;
                cont++;                
            }
        }
    }

    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'X'){
                mat[l][c] = ' ';
            }
        }
    }

    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            cout << mat[l][c];
        }
        cout << endl;
    }

}