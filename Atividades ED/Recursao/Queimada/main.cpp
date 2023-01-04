#include <iostream>
using namespace std;
/*
Dado uma matriz que representa espaços vazios e árvores e um ponto inicial onde começa o fogo, retorne a matriz com as árvores queimadas. O fogo não se espalha nas diagonais, apenas nas 4 direções cardeais.

A matriz está codificada assim:

1a linha: nl, nc, l, c respectivamente - número de linhas e colunas da matriz, linha e coluna onde começa o fogo.

- Nas linhas subsequentes:

‘#’ representa uma árvore
‘.’ representa um espaço vazio
‘o’ representa uma árvore queimada
*/

void queimada(char **mat, int l, int c, int nl, int nc){
    if(l < 0 || l >= nl || c < 0 || c >= nc || mat[l][c] == '#' || mat[l][c] == 'o')
        return;
    mat[l][c] = 'o';
    queimada(mat, l-1, c, nl, nc);
    queimada(mat, l+1, c, nl, nc);
    queimada(mat, l, c-1, nl, nc);
    queimada(mat, l, c+1, nl, nc);
}

int main(){
    int nl, nc, l, c;
    cin >> nl >> nc >> l >> c;
    char **mat = new char*[nl];
    for(int i = 0; i < nl; i++){
        mat[i] = new char[nc];
        for(int j = 0; j < nc; j++)
            cin >> mat[i][j];
    }
    queimada(mat, l, c, nl, nc);
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++)
            cout << mat[i][j];
        cout << endl;
    }
    for(int i = 0; i < nl; i++)
        delete[] mat[i];
    delete[] mat;
    return 0;
}
