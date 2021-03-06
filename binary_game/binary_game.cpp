#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define USI unsigned short int
using namespace std;

vector<USI> genX(unsigned short int cardx, USI lenseq) {// os parametros sao a cardinalidade de X e o tamanho m�ximo das sequencias
    srand(time(NULL));


    vector<vector<USI>> X;
    //vector<USI> X (cardx, rand() % 1);

    for (USI n = 0; n < cardx; n++) {



        USI len = rand() % lenseq +1;
        // cout << len << endl;
        vector<USI> x (len, rand() % 2);
        X.push_back(x);
        cout << x[0] << endl;



    }

    return X;

}

vector<USI> init(USI cardx, USI lenseq) {

    cout << "Esta é uma implementação do jogo topológico conhecido por 'binary game', de autoria de Stanislaw Ulam. \n"
            "Você (o jogador I!) receberá um conjunto X de sequências binárias (sequências cujas coordenadas são 0 ou 1). \n"
            "A cada turno, deverá escolher um número em {0, 1} e, em resposta, o computador (que é o jogador J) escolherá outro. \n"
            "Isso construirá uma sequência S_k i_0, j_0, i_1, j_1... i_k, j_k de jogadas. Se para algum x em X, x for igual a S_k, \n"
            "o jogo termina no turno k com a vitória do jogador I. \n"
            "O número de turnos k é no máximo o tamanho da maior sequência em X, digamos, L. \n"
            "Se k > L e S_k não está em X, você perde.";

    vector<USI> out = genX(cardx, lenseq);

   // cout << out[0,1] << endl << out[0,0] << endl;

    return out;

}

int main() {
    USI cardx = 30;
    USI lenseq = 7;
    vector<USI> X = init(cardx, lenseq);
  //  cout << X[0, 0] << endl;
    return 0;
}
