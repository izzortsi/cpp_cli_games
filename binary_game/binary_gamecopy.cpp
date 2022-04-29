
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#define usi unsigned short int
using namespace std;


// quero gerar X: um vetor de vetores sem qualquer simetria a priori
vector<vector<usi> > genX(usi cardx, usi lenseq) {// os parametros sao a cardinalidade de X e o tamanho m�ximo das sequencias
    srand(time(NULL));


    vector<vector<usi> > X;
    //vector<usi> X (cardx, rand() % 1);

    for (usi n = 0; n < cardx; n++) {



        usi len = rand() % lenseq +1;
        // cout << len << endl;
        vector<usi> x (len);
        generate(x.begin(), x.end(), []() {return rand() %2;});
        X.push_back(x);
        //cout << x[0] << endl;



    }

    return X;

}

vector<vector<usi> > init(usi cardx, usi lenseq) {

    cout << "Esta é uma implementação do jogo topológico conhecido por 'binary game', de autoria de Stanislaw Ulam. \n"
            "Você (o jogador I!) receberá um conjunto X de sequências binárias (sequências cujas coordenadas são 0 ou 1). \n"
            "A cada turno, deverá escolher um número em {0, 1} e, em resposta, o computador (que é o jogador J) escolherá outro. \n"
            "Isso construirá uma sequência S_k i_0, j_0, i_1, j_1... i_k, j_k de jogadas. Se para algum x em X, x for igual a S_k, \n"
            "o jogo termina no turno k com a vitória do jogador I. \n"
            "O número de turnos k é no máximo o tamanho da maior sequência em X, digamos, L. \n"
            "Se k > L e S_k não está em X, você perde. \n";

    vector<vector<usi> > out = genX(cardx, lenseq);

   // cout << out[0,1] << endl << out[0,0] << endl;

    return out;

}

bool isin(vector<vector<usi> > *X, vector<usi> *S)
{
    cout << endl;
    for (auto &i : *X)
    {
        for (auto &j : i)
            cout << j;

        cout << endl;
    }
    return 1;
}

usi* pturns(vector<usi> *S)
{
    //pede inputs dos jogadores
    usi p1; usi p2;
    //coloca os inputs no final da sequencia
    cout << "0 ou 1, jogador I" << endl;
    scanf("%i", &p1);
    cout << "0 ou 1, jogador J" << endl;
    scanf("%i", &p2);
    S->push_back(p1); S->push_back(p2);
    usi out[2] = {p1, p2};
    cout << "S: ";
    for (vector<usi>::iterator it = S->begin(); it != S->end(); it++) {
        cout << *it;
    } 
    cout << endl;
    return out;
}

void loopt(usi cardx, usi lenseq, vector<vector<usi> > *X, usi*turn, vector<usi>*S) {

    while (S->size() < lenseq+1) {
        usi p1, p2;
        usi* plays = pturns(S);
        isin(X, S);
        S->push_back(rand() % 2);
        printf("size %d \n back %d \n", S->size(), S->back());
    }
}

int main() {
    usi cardx = 8;
    usi lenseq = 14;

    usi turn = 1;
    vector<usi> S; 
    vector<vector<usi> > X = init(cardx, lenseq);

    loopt(cardx, lenseq, &X, &turn, &S);
    
    return 0;
}
