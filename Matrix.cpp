#include "Matrix.h"

Matrix::Matrix()
:deadMdiag(false), deadSdiag(false),winner(-1){
    for(auto& linha: tictactoe){
        std::fill(linha.begin(), linha.end(), -1);
    }
    dead_cols.resize(3);
    dead_lines.resize(3);
}

bool Matrix::changeElement(int line, int column, int value){
    if(tictactoe[line][column] == -1){
        tictactoe[line][column] = value;
        return true;
    }
    return false;
}

bool Matrix::checkLine(int pin){
    for(int j = 1; j < 3; j++){
        if(tictactoe[pin][j] != tictactoe[pin][0]){
            if((tictactoe[pin][j] != -1) && (tictactoe[pin][0] != -1)){
                dead_lines[pin] = true;
            }
            return false;
        }
    }
    winner = tictactoe[pin][0];
    return true;
}

bool Matrix::checkColumn(int pin){
    for(int i = 1; i < 3; i++){
        if(tictactoe[i][pin] != tictactoe[0][pin]){
            if((tictactoe[i][pin] != -1) && (tictactoe[0][pin] != -1)){
                dead_cols[pin] = true;
            }
            return false;
        }
    }
    winner = tictactoe[0][pin];
    return true;
}


bool Matrix::checkMainDiag(){
    for(int i = 1, j = i; i<3; i++, j++){
        if(tictactoe[i][j] != tictactoe[0][0]){
            if((tictactoe[i][j] != -1) && (tictactoe[0][0] != -1)){
            deadMdiag = true;
        }
            return false;
        }
    }
    winner = tictactoe[0][0];
    return true;
}

bool Matrix::checkSecDiag(){
    for(int i = 2, j = 0; i<0; i--, j++){
        if(tictactoe[i][j] != tictactoe[0][2]){
            if((tictactoe[i][j] != -1) && (tictactoe[0][2] != -1)){
            deadSdiag = true;
        }
            return false;
        }
    }
    winner = tictactoe[0][2];
    return true;
}

int Matrix::checkWinner(){
    for(int i = 0; i < 3; i++){
        if(!dead_lines[i]){
            if(checkLine(i)) return winner;
        }
    }
    for(int j = 0; j < 3 ; j++){
        if(!dead_cols[j]){
            if(checkColumn(j)) return winner;
        }
    }
    if(!deadMdiag){
        if(checkMainDiag) return winner;
    }
    if(!deadSdiag){
        checkSecDiag();
        return winner;
    }
    return -2;
}

void Matrix::clear(){
    
    for(auto& linha: tictactoe){
        std::fill(linha.begin(), linha.end(), -1);
    }

    std::fill(dead_lines.begin(), dead_lines.end(), 0);
    std::fill(dead_cols.begin(), dead_cols.end(), 0);

    deadMdiag = false;
    deadSdiag = false;
    winner = -1;
}