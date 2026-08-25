#include "Matrix.h"
#include <vector>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget janela;
    janela.setWindowTitle("TicTac");
    janela.resize(500, 400);
    
    QVBoxLayout *main_layout = new QVBoxLayout(&janela);

    QLabel *player_label = new QLabel("Vez do Jogador: X", &janela);
    player_label->setAlignment(Qt::AlignCenter);
    player_label->setStyleSheet("font-size: 16px; font-weight: bold;");
    main_layout->addWidget(player_label);

    QGridLayout *tabuleiro = new QGridLayout();
    tabuleiro->setSpacing(5);
    main_layout->addLayout(tabuleiro);

    Matrix *tiktak = new Matrix();
    QPushButton *botoes[3][3];
    int rodada = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            botoes[i][j] = new QPushButton("", &janela);
            botoes[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            tabuleiro->addWidget(botoes[i][j], i, j);
        }
    }

    auto resetGame = [tiktak, &botoes, &rodada, player_label]() {
        tiktak->clear();
        rodada = 0;
        player_label->setText("Vez do Jogador: X");
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                botoes[r][c]->setText("");
            }
        }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QPushButton::connect(botoes[i][j], &QPushButton::clicked, [tiktak, &botoes, &rodada, i, j, player_label, resetGame]() {
                if (!botoes[i][j]->text().isEmpty()) return;

                int jogador = rodada % 2;
                tiktak->changeElement(i, j, jogador);
                botoes[i][j]->setText(jogador == 0 ? "X" : "O");

                int winner = tiktak->checkWinner();

                if (winner != -1) {
                    QMessageBox::information(nullptr, "Fim de Jogo", QString("Jogador %1 venceu!").arg(winner == 0 ? "X" : "O"));
                    resetGame();
                } else if (rodada == 8) {
                    QMessageBox::information(nullptr, "Fim de Jogo", "Empate!");
                    resetGame();
                } else {
                    rodada++;
                    player_label->setText(QString("Vez do Jogador: %1").arg(rodada % 2 == 0 ? "X" : "O"));
                }
            });
        }
    }

    janela.show();
    return app.exec();
}