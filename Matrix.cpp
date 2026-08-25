#include "Matrix.h"

Matrix::Matrix()
:deadMdiag(false), deadSdiag(false),winner(-1){
    tictac.resize(3, std::vector<int>(3, -1));
    dead_cols.resize(3);
    dead_lines.resize(3);
}

bool Matrix::changeElement(int line, int column, int value){
    if(tictac[line][column] == -1){
        tictac[line][column] = value;
        return true;
    }
    return false;
}

bool Matrix::checkLine(int pin){
    if (tictac[pin][0] != -1 && 
        tictac[pin][0] == tictac[pin][1] && 
        tictac[pin][1] == tictac[pin][2]) {
        winner = tictac[pin][0];
        return true;
    }
    bool tem_zero = false, tem_um = false;
    for(int i =0;  i < 3; i++){ 
        if(tictac[pin][i] == 0) tem_zero = true;
        if(tictac[pin][i] == 1) tem_um = true;
        if(tem_zero && tem_um) dead_lines[pin] = true;

    }
    return false;
}


bool Matrix::checkColumn(int pin){
    if (tictac[0][pin] != -1 && 
        tictac[0][pin] == tictac[1][pin] && 
        tictac[1][pin] == tictac[2][pin]) {
        winner = tictac[0][pin];
        return true;
    }
    bool tem_zero = false, tem_um = false;
    for(int i =0;  i < 3; i++){ 
        if(tictac[i][pin] == 0) tem_zero = true;
        if(tictac[i][pin] == 1) tem_um = true;
        if(tem_zero && tem_um) dead_cols[pin] = true;

    }
    return false;
}


bool Matrix::checkMainDiag(){
if (tictac[0][0] != -1 && 
        tictac[0][0] == tictac[1][1] && 
        tictac[1][1] == tictac[2][2]) {
        winner = tictac[0][0];
        return true;
    }

    bool temZero = false, temUm = false;
    for (int i = 0; i < 3; i++) {
        if (tictac[i][i] == 0) temZero = true;
        if (tictac[i][i] == 1) temUm = true;
    }
    if (temZero && temUm) deadMdiag = true;

    return false;
}

bool Matrix::checkSecDiag(){
if (tictac[0][2] != -1 && 
        tictac[0][2] == tictac[1][1] && 
        tictac[1][1] == tictac[2][0]) {
        winner = tictac[0][2];
        return true;
    }

    bool temZero = false, temUm = false;
    for (int i = 0; i < 3; i++) {
        if (tictac[i][2 - i] == 0) temZero = true;
        if (tictac[i][2 - i] == 1) temUm = true;
    }
    if (temZero && temUm) deadSdiag = true;

    return false;
}

int Matrix::checkWinner(){
    for(int i = 0; i < 3; i++){
        if (!dead_lines[i] && checkLine(i)) return winner;
    }
    for(int j = 0; j < 3 ; j++){
        if (!dead_cols[j] && checkColumn(j)) return winner;
    }

    if (!deadMdiag && checkMainDiag()) return winner;
    if (!deadSdiag && checkSecDiag()) return winner;

    return -1;
}

void Matrix::clear(){
    
    for(auto& linha: tictac){
        std::fill(linha.begin(), linha.end(), -1);
    }

    std::fill(dead_lines.begin(), dead_lines.end(), false);
    std::fill(dead_cols.begin(), dead_cols.end(), false);

    deadMdiag = false;
    deadSdiag = false;
    winner = -1;
}