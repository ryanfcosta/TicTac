#include "Matrix.h"
#include <vector>

using namespace std;
int main(){
    Matrix *tiktak = new Matrix();

    game(tiktak);
    /*
    Captura na interface se quer jogar novamente
    */
        tiktak->clear();
        game(tiktak);
}

int game(Matrix *tiktak){
    int winner = -1;

    for(int round = 0; winner != -2 || round < 9; round ++){
        std::pair<int, int> play;
        bool jogou = false;

        do{

            /*
        
            Código captura input da jogada
        
            */
            jogou = tiktak->changeElement(play.first, play.second, round % 2);


        }while(jogou == false);


        /*
        
        código adiciona na interface
        
        */
        winner = tiktak->checkWinner();
    }

}