#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct Pos{//struct para marcar posição
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

int main(){
    int nl, nc, l, c;
    cin >> nl >> nc >> l >> c;
    char **mat = new char*[nl];
    for(int i = 0; i < nl; i++)
        mat[i] = new char[nc];
    for(int i = 0; i < nl; i++)
        for(int j = 0; j < nc; j++)
            cin >> mat[i][j];

    stack<Pos> pilha;
    pilha.push({l, c});
    if(mat[l][c] == '#'){//verifico se as coordenadas para tocar fogo é de uma arvore 
        mat[l][c] = 'o';
        while(!pilha.empty()){//enquanto a pilha tem elemento, faça
            Pos atual = pilha.top();
            pilha.pop();
            vector<Pos> vizinhos = get_vizinhos(atual);//recebo os vizinhos em lista
            for(Pos p : vizinhos){
                if(p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc && mat[p.l][p.c] == '#'){//verifico se os vizinhos sao arvores
                    pilha.push(p);
                    mat[p.l][p.c] = 'o';//fogo neles
                }
            }
        }
    }

    for(int i = 0; i < nl; i++){//print
        for(int j = 0; j < nc; j++)
            cout << mat[i][j];
        cout << endl;
    }
    return 0;
}