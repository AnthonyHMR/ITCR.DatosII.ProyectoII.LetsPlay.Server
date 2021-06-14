//
// Created by juanpr on 13/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H

class Backtracking {
public:
    static const int N = 20;
    static const int M = 30;
    /**
     *
     * @brief Constructor de clase Backtracking
     * @param maze
     * @param startX_
     * @param startY_
     * @param goalX_
     * @param goalY_
     */
    Backtracking(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_);

    int myMaze[N][M];
    int startX;
    int startY;
    int goalX;
    int goalY;
    int sol[N][M];

    /**
     * @brief funcion de inicio
     * @param maze
     * @return bool segun se encuentre o no un camino
     */
    bool findPath(int maze[N][M]);
    /**
     * @brief imprime la solucion
     * @param sol
     */
    void printSol(int sol[N][M]);

private:
    /**
     * @brief revisa si un espacio es seguro
     * @param maze
     * @param x
     * @param y
     * @return bool
     */
    bool isSafe(int maze[N][M], int x, int y);
    /**
     * @brief funcion auxiliar de findPath
     * @param maze
     * @param x
     * @param y
     * @return bool
     */
    bool solveUtil(int maze[N][M], int x, int y);

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H
