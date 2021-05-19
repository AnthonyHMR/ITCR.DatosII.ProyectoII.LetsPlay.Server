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

    findShortestPath(0, 0, 7, 5, 0);

    if (min_dist != INT_MAX)
    {
        cout << "The shortest path from source to destination "
                "has length " << min_dist;
    }
    else {
        cout << "Destination can't be reached from a given source";
    }
    cout << "\n Found path"<< endl;
    return 0;
}

Backtracker::Backtracker() {
    memset(visited, 0, sizeof(visited));
    memset(path, 0, sizeof (path));
}

Backtracker::~Backtracker() {

}
bool Backtracker::isSafe(int x, int y){
    if (mat[x][y] == 0 || visited[x][y]) {

        return false;
    }

    return true;
}
bool Backtracker::isValid(int x, int y){
    if (x < M && y < N && x >= 0 && y >= 0) {

        return true;
    }

    return false;
}
int Backtracker::findShortestPath(int i, int j,
                      int x, int y, int dist){
    // if the destination is found, update min_dist
    if (i == x && j == y ){

        cout << "pasada fin: " << dist<<endl;
        min_dist = min(dist, min_dist);
        for (int k = 0; k < M; k++){
            for (int l = 0; l < N; l++) {
                if(visited[k][l]){
                    printf("(%d, %d, %d)-->\n",k, l, visited[k][l]);
                }
            }
        }

        return 0;
    }

    // set (i, j) cell as visited
    visited[i][j] = 1;
    // go to the bottom cell
    if (isValid(i + 1, j) && isSafe( i + 1, j)) {

        findShortestPath(i + 1, j, x, y, dist + 1);

    }

    // go to the right cell
    if (isValid(i, j + 1) && isSafe(i, j + 1)) {

        findShortestPath(i, j + 1, x, y, dist + 1);

    }

    // go to the left cell
    if (isValid(i, j - 1) && isSafe(i, j - 1)) {

        findShortestPath(i, j - 1, x, y, dist + 1);

    }

    // backtrack: remove (i, j) from the visited matrix

    visited[i][j] = 0;

}

