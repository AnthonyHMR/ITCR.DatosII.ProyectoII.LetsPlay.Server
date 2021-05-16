//
// Created by juanpr on 15/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class Backtracker {
private:
    //Donde 0 es un obstaculo y 1 es camino libre
    int grid[4][4] = {
            1 ,1 ,0 ,1,
            1 ,0 ,1 ,0,
            1 ,1 ,1 ,0,
            0 ,0 ,1 ,1
    };
    int path[4][4] = {
            0 ,0 ,0 ,0,
            0 ,0 ,0 ,0,
            0 ,0 ,0 ,0,
            0 ,0 ,0 ,0
    };
public:
    Backtracker();
    ~Backtracker();
    int findPath(int i, int j, int rows);
    int runExample();
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKER_H
