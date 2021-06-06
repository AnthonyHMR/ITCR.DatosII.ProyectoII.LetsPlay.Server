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
#define M 63
#define N 42
using namespace std;
class Backtracker {
    /**
     * @class Backtracker class implements a pathfinding algorithm between two points
     * in a matrix, where 0's represent an obstacle and 1's represent a free track
     */
public:
    int min_dist = INT_MAX;
    //Donde 0 es un obstaculo y 1 es camino libre

    int path[M][N];
    int mat[M][N] ;

    int visited[M][N];


public:
    Backtracker();
    ~Backtracker();

    int runExample();
    /**
     * @brief checks if the given position is an obstacle or if it is a visited location
     * @param x integer, x coordinate in a matrix
     * @param y integer, y coordinate in a matrix
     * @return boolean
     */
    bool isSafe(int x, int y);
    /**
     * @brief checks if the given position is out of matrix boundaries
     * @param x integer, x coordinate in a matrix
     * @param y integer, y coordinate in a matrix
     * @return boolean
     */
    bool isValid(int x, int y);
    /**
     * @brief find the shortest path for start point to end in the matrix
     * @param i x-coordinate of start point
     * @param j y-coordinate of start point
     * @param x x-coordinate of end point
     * @param y y-coordinate of end point
     * @param dist distance from start to end
     * @return shortest distance
     */
    int findShortestPath( int i, int j,
                          int x, int y, int dist);
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
