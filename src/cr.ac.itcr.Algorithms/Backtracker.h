//
// Created by juanpr on 15/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <cstring>



// `M × N` matriz
#define M 10
#define N 10
using namespace std;
class Backtracker {
private:
    int min_dist = INT_MAX;
    //Donde 0 es un obstaculo y 1 es camino libre

    int path[M][N];
    int mat[M][N] =
            {
                    1, 1, 1, 1, 1, 1, 0, 1, 1, 1 ,
                    0, 1, 1, 1, 1, 1, 0, 1, 0, 1 ,
                    0, 0, 1, 0, 1, 1, 1, 0, 1, 1 ,
                    1, 0, 1, 1, 1, 0, 1, 1, 0, 1 ,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,
                    1, 1, 0, 0, 1, 1, 0, 1, 0, 1 ,
                    0, 1, 1, 1, 1, 1, 1, 1, 0, 0 ,
                    1, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,
                    1, 1, 1, 0, 1, 1, 1, 0, 1, 1 ,
            };

    int visited[M][N];


public:
    Backtracker();
    ~Backtracker();
    int runExample();
    bool isSafe(int x, int y);
    bool isValid(int x, int y);
    int findShortestPath( int i, int j,
                          int x, int y, int dist);
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
