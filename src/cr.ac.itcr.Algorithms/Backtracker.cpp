//
// Created by juanpr on 15/5/21.
//


#include "Backtracker.h"
int Backtracker::findPath(int i, int j, int rows) {
    if ( i  == rows -1 && j == rows - 1) return 1;

    if (this->grid[i][j] == 1){
        path[i][j] = 1;
        if (findPath(i, j + 1, rows) == 1) return 1;
        if (findPath(i + 1, j, rows) == 1) return 1;
        path[i][j] = 0;

    }
    return 0;
}
int Backtracker::runExample() {
    findPath(0, 0, 4);
    cout << "Found path"<< endl;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; ++j) {
            if (path[i][j]) printf("(%d, %d)-->",i, j);

        }
    }
}

Backtracker::Backtracker() {

}

Backtracker::~Backtracker() {

}
