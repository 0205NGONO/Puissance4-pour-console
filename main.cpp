#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>


void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
int win(int grid[7][6]);
int IA_play(int grid[7][6]);

int main(int argc, char** argv){
    int grille[7][6] = {};
    std::string choix;
    int mode;

    int player = 1;
        drawGrid(grille);

    
    std::cout <<"Game mode : \n Multiplayer : 1 \n VS Computer : 2 \n Exit : 0 \n";
    std::cin >> mode;
    while (true)
    {
    
            if (mode == 1)
            {

                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;

                if (choix == "exit"){
                    break;
                }

                bool success = false;

                if (choix.size() == 1){
                    if (choix[0] >= '0' && choix[0] <= '7'){
                        int col = choix[0]  - '0';

                        success = playTurn(grille, col, player);
                    }
                }

                system("CLS");

                if (!success){
                    std::cout << "votre choix est incorrect\n";
                } else{
                    if (player == 1) player = 2;
                    else player = 1;
                }

                drawGrid(grille);

                if (win(grille) == 1){
                    std::cout <<"Player 1 won";
                    break;
                } else if (win(grille) == 2)
                {
                    std::cout <<"Player 2 won";
                    break;
                }
            }else if (mode == 2)
            {
                if (player == 1)
                {
                    std::cout << "player_" << player << " -> col :";
                    std::cin >> choix;
                    bool success = false;

                    if (choix.size() == 1){
                        if (choix[0] >= '0' && choix[0] <= '7'){
                            int col = choix[0]  - '0';

                            success = playTurn(grille, col, player);
                        }
                    }

                    if (choix == "exit"){
                    break;
                    }

                    system("CLS");

                    if (!success){
                        std::cout << "votre choix est incorrect\n";
                    } else{
                        if (player == 1) player = 2;
                        else player = 1;
                    }
                    }else if (player == 2)
                    {
                        choix = IA_play(grille);
                        bool success = false;
                        int col = choix[0]  ;
                        success = playTurn(grille, col, player);
                        system("CLS");
                        if (success)
                        {
                            player = 1 ;
                        }

                    drawGrid(grille);
                    
                    if (win(grille) == 1){
                        std::cout <<"Player 1 won";
                        break;
                    } else if (win(grille) == 2)
                    {
                        std::cout <<"Player 2 won";
                        break;
                    }
                    
                }           

                
            }
            else
                break;  

    }
    

    return 0;
}


// Construction et affichage de la grille de jeu
void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}
//Mise à jour de la grille
bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}
//Détermination d'un éventuel gagnant
int win(int grid[7][6]){
    int result = 0;
    //Alignement horizontal
    for (int line = 0 ; line < 7 ; line++){
        for (int column = 0 ; column < 3 ; column++){
            if ((grid[line][column] == 1) && (grid[line][column + 1] == 1) && (grid[line][column + 2] == 1) && (grid[line][column + 3] == 1))
            {
                result = 1 ;
            }else if ((grid[line][column] == 2) && (grid[line][column + 1] == 2) && (grid[line][column + 2] == 2) && (grid[line][column + 3] == 2))
            {
                result = 2 ;
            }
        }
    } 
    //Alignement vertical
    for (int column = 0; column < 6; column++)
    {
       for (int line = 0; line < 4; line++)
       {
        if ((grid[line][column] == 1) && (grid[line + 1][column] == 1) && (grid[line + 2][column] == 1) && (grid[line  + 3][column] == 1))
            {
                result = 1 ;
            }else if ((grid[line][column] == 2) && (grid[line + 1][column] == 2) && (grid[line + 2][column] == 2) && (grid[line  + 3][column] == 2))
            {
                result = 2 ;
            }
       }
    }
    //Alignement oblique descendant
    for (int line = 0; line < 4 ; line++)
    {
        for (int column = 0; column < 3; column++)
        {
            if ((grid[line][column] == 1) && (grid[line + 1][column + 1] == 1) && (grid[line + 2][column + 2] == 1) && (grid[line  + 3][column + 3] == 1))
            {
                result = 1 ;
            }else if ((grid[line][column] == 2) && (grid[line + 1][column + 1] == 2) && (grid[line + 2][column + 2] == 2) && (grid[line  + 3][column + 3] == 2))
            {
                result = 2 ;
            }
        }
    }
    //Alignement oblique ascendant
    for (int line = 0; line < 4 ; line++)
    {
        for (int column = 5 ; column > 2 ; column--)
        {
            if ((grid[line][column] == 1) && (grid[line + 1][column - 1] == 1) && (grid[line + 2][column - 2] == 1) && (grid[line  + 3][column - 3] == 1))
            {
                result = 1 ;
            }else if ((grid[line][column] == 2) && (grid[line + 1][column - 1]  == 2) && (grid[line + 2][column - 2] == 2) && (grid[line  + 3][column - 3] == 2))
            {
                result = 2 ;
            }
        }
    }
        return result ;
}
/*Jeu de l'IA
Elle se concentre d'abord à bloquer le jeu de l'adversaire, s'il compte déjà 02 pions alignés
que ce soit verticalement, horizontalement ou obliquement. Et s'il n'est pas possible de le bloquer,
elle joue de façon aléatoire.*/
int IA_play(int grid[7][6]) {
    int col ;
    bool block = false;
    for (int line = 0 ; line < 7 ; line++){
        if (!block)
        {
            for (int column = 0 ; column < 4 ; column++){
                if ((grid[line][column] == 1) && (grid[line][column + 1] == 1) && (grid[line][column + 2] == 0))
                {
                    col = column + 3 ;
                    block = true ;
                    break;
                }
            }
            for (int column = 6 ; column > 2 ; column--){
                if ((grid[line][column] == 1) && (grid[line][column - 1] == 1) && (grid[line][column - 2] == 0) && (grid[line][column - 2] == 0) )
                {
                    col = column - 2 ;
                    block = true ;break;
                }
            }
        }
    }
    if (!block)
    {
        for (int column = 0; column < 6; column++)
        {
        for (int line = 6; line > 3; line--)
        {
            if ((grid[line][column] == 1) && (grid[line - 1][column] == 1) && (grid[line - 2][column] == 1) && (grid[line  - 3][column] == 0))
                {
                    col = column ;
                    break;
                }
        }
        }
    }
    
    for (int line = 6; line >= 0 ; line--)
    {
        if (!block)
        {
    
            for (int column = 5 ; column > 2; column--)
            {
                if ((grid[line][column] == 1) && (grid[line - 1][column - 1] == 1) && (grid[line - 2][column - 2] == 0) )
                {
                    col = column - 2 ;
                    block = true ;
                    break;
                }
            }
            for (int column = 0; column < 2; column++)
            {
                if ((grid[line][column] == 1) && (grid[line + 1][column + 1] == 1) && (grid[line + 2][column + 2] == 1) )
                {
                    col = column + 2 ;
                    block = true ;
                    break;
                }
            }
        }
    }
    for (int line = 0 ; line < 4 ; line++)
    {
        if (!block)
        {
            for (int column = 0; column > 2; column++)
            {
                if ((grid[line][column] == 1) && (grid[line + 1][column + 1] == 1) && (grid[line + 2][column + 2] == 0) )
                {
                    col = column + 2 ;
                    block = true ;
                    break;
                }
            }
            for (int column = 5 ; column > 2; column--)
            {
                if ((grid[line][column] == 1) && (grid[line - 1][column - 1] == 1) && (grid[line - 2][column - 2] == 0) )
                {
                    col = column - 2 ;
                    block = true ;
                    break;
                }
            }
        }
    }
    if (!block)
    {
        col = rand()%7 ;
    }

    return col;
}