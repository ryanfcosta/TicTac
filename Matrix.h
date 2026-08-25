#include <vector>
using namespace std;


class Matrix{
private:

    std::vector<std::vector<int>> tictactoe;
    std::vector <bool> dead_cols;
    std::vector<bool> dead_lines;
    bool deadMdiag;
    bool deadSdiag;
    int winner;

public:
    Matrix();

    bool changeElement(int line, int column, int value);

    bool checkLine(int pin);

    bool checkColumn(int pin);

    bool checkMainDiag();

    bool checkSecDiag();

    int checkWinner();
    
    void clear();
};