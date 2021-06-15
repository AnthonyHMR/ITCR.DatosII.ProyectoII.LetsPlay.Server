//
// Created by juanpr on 13/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H

class Backtracking {
    /**
     * @class in this class a backtracking algorithm is implemented over a 20x30 matrix
     */
public:
    static const int N = 20;
    static const int M = 30;
    /**
     *
     * @brief Constructor de clase Backtracking
     * @param maze is the 20x30 matrix that represents the game field
     * @param startX_ x coordinate of start position
     * @param startY_ y coordinate of start position
     * @param goalX_ x coordinate of end position
     * @param goalY_ y coordinate of end position
     */
    Backtracking(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_);

    int myMaze[N][M];
    int startX;
    int startY;
    int goalX;
    int goalY;
    int sol[N][M];

    /**
     * @brief init method that calls an auxiliary method for backtracking in the matrix
     * @param maze matrix
     * @return boolen if there's a path or not
     */
    bool findPath(int maze[N][M]);
    /**
     * @brief prints the sulution matrix
     * @param sol
     */
    void printSol(int sol[N][M]);

private:
    /**
     * @brief checks if a cell in the matrix is inside the matrix or has been visited
     * @param maze current matrix
     * @param x horizontal coordinate
     * @param y vertical coordinate
     * @return boolean result
     */
    bool isSafe(int maze[N][M], int x, int y);
    /**
     * @brief auxiliary method that backtracks inside the matrix
     * @param maze
     * @param x
     * @param y
     * @return bool
     */
    bool solveUtil(int maze[N][M], int x, int y);

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_BACKTRACKING_H
