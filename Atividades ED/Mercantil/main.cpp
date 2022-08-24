    #include <iostream>
    using namespace std;

    /*
       Essa questao pedia que fizessemos um programa que contabiliza os pontos de um jogo do silvio santos, mercantil
       Regras do jogo:
       
            Pedro e João foram no Silvio Santos. O programa era aquele que o Silvio mostrava um produto do mercantil e a 
            pessoa que chegasse mais próximo do preço real ganhava.João e Pedro são concorrentes. O objetivo do seu programa 
            é informar quem ganhou a disputa.
            O primeiro jogador informa o preço e o segundo jogador informa maior ou menor.  
            Quem vencer mais disputas ganha o jogo. Se o valor do produto for igual ao chute, ganha o primeiro concorrente.
            Se ambos vencerem a mesma quantidade então acontece o empate.  
    */

    int main() {

        //lendo a quantidade de rodadas, e logo apos criando e lendo o valor dos produtos no primeiro for, 
        //no segundo lendo os chutes do jogador 1 e no terceiro limpando o buffer com o cin.ignore() e lendo os chutes do jogador 2

        int n;
        cin >> n;

        float precos[n], chute1[n];
        char chute2[n];

        int win1 = 0, win2 = 0;

        for (int i = 0; i < n; i++) {

            cin >> precos[i];

        }
        
        for (int i = 0; i < n; i++) {

            cin >> chute1[i];

        }

        for (int i = 0; i < n; i++) {

            cin.ignore();
            cin >> chute2[i];

        }

        //checkando por meio de condicionais quem pontua em cada rodada e armazenando esses pontos 
        //em variaveis contadoras e que se incrementam, win1 e win2

        for (int i = 0; i < n; i++) {

            if(precos[i] == chute1[i]){

                win1++;

            }else if((precos[i] > chute1[i]) && (chute2[i] == 'M')){

                win2++;

            }else if((precos[i] < chute1[i]) && (chute2[i] == 'm')){

                win2++;

            }else if((precos[i] < chute1[i]) && (chute2[i] == 'M')){

                win1++;

            }else if((precos[i] > chute1[i]) && (chute2[i] == 'm')){

                win1++;

            }

        }

         //verificando quem tem mais pontos ou se empatou para printar.

        if(win1 == win2){

            cout << "empate";

        }else if(win1 > win2){

            cout << "primeiro";

        }else if(win1 < win2){

            cout << "segundo";

        }
        
        return 0;
    }