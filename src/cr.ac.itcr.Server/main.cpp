#include <iostream>
#include "mServer.h"
#include "../cr.ac.itcr.Algorithms/Backtracking.h"
#include <string>
using namespace std;
int main() {
/*   int mat[15][20];
    for(int i = 0; i < 15; i++) {
        for (int j = 0; j < 20 ; j++)
            mat[i][j] = 1;
    }
    //team 1 players
    mat[5][5] = 0;
    mat[10][5] = 0;
    mat[2][7] = 0;
    mat[13][7] = 0;
    mat[9][7] = 0;
    //team 2 players
    mat[5][18] = 0;
    mat[10][18] = 0;
    mat[2][16] = 0;
    mat[13][16] = 0;
    mat[9][15] = 0;
    for(int i = 0; i < 15; i++) {
        for (int j = 0; j < 20 ; j++)
            printf(" %d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
    Backtracking backtracking(mat,6, 5, 19, 9 );
    backtracking.findPath(mat);
    backtracking.printSol(backtracking.sol);
    JsonParser *jsonParser;

    for (int k = 0; k < 15; k++){
        for (int l = 0; l < 20; l++) {
            if(backtracking.sol[k][l] == 1){
                //printf("(%d, %d)-->\n",k, l);
                jsonParser->writePath(l*10, k*10);
            }
        }
    }*/
    mServer *server = new mServer(54000, 1024);
    server->runServer();

    return 0;
}
