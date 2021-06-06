//
// Created by juanpr on 15/5/21.
//


#include "Backtracker.h"
int Backtracker::runExample() {
    //Encontrar el camino màs corto desde (0, 0) hasta (7, 7)
    findShortestPath(0, 4, 6, 5, 0);

    if (min_dist != INT_MAX)
    {
        cout << "El camino màs corto toma " << min_dist<< "bloques"<<endl;
    }
    else {
        cout << "No hay camino";
    }
    cout << "\n Found path"<< endl;
    for (int k = 0; k < M; k++){
        for (int l = 0; l < N; l++) {
            if(path[k][l]){
                printf("(%d, %d, %d)-->\n",k, l, path[k][l]);
            }
        }
    }
    return 0;
}

Backtracker::Backtracker() {
    memset(visited, 0, sizeof(visited));
    memset(path, 0, sizeof (path));
}

Backtracker::~Backtracker() {

}
bool Backtracker::isSafe(int x, int y){
    //Validar que un punto (x, y) no se haya visitado o no sea un obstàculo
    if (mat[x][y] == 0 || visited[x][y]) {

        return false;
    }

    return true;
}
bool Backtracker::isValid(int x, int y){
    // validar que se hagan llamadas recursivas validas para los lìmites de la matriz
    if (x < M && y < N && x >= 0 && y >= 0) {

        return true;
    }
    return false;
}
int Backtracker::findShortestPath(int i, int j,
                      int x, int y, int dist){
    // actualizar la distancia minima cuando se llega al destino
    if (i == x && j == y ){

        // En estos ciclos se itera sobrela matriz de visitados para guardar el camino màs corto encontrado
        for (int k = 0; k < M; k++){
            for (int l = 0; l < N; l++) {
                if(visited[k][l] and min_dist > dist){
                    path[k][l] = visited[k][l];
                }
            }
        }
        min_dist = min(dist, min_dist);
        return 0;
    }
    // Fijar el punto (i, j) como visitado
    visited[i][j] = 1;
    // ir abajo
    if (isValid(i + 1, j) && isSafe( i + 1, j)) {
        findShortestPath(i + 1, j, x, y, dist + 1);

    }

    // ir a la derecha
    if (isValid(i, j + 1) && isSafe(i, j + 1)) {
        findShortestPath(i, j + 1, x, y, dist + 1);

    }
    // ir a la izquierda
    if (isValid(i, j - 1) && isSafe(i, j - 1)) {

        findShortestPath(i, j - 1, x, y, dist + 1);

    }
    // backtrack: quitar (i, j) de los visitados
    visited[i][j] = 0;

}

