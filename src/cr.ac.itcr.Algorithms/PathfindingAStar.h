//
// Created by juanpr on 13/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PATHFINDINGASTAR_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PATHFINDINGASTAR_H
#include <list>
#include "StarNode.h"
#include <string>
#include <iostream>
class PathfindingAStar {
    /**
     * @class in this class the A* pathfinding algorithm is implemented
     * over a 20x30 matrix
     *
     */
public:
    static const int N = 20;
    static const int M = 30;
    /**
     * @brief Class constructor
     * @param maze is the 20x30 matrix that represents the game field
     * @param startX_ x coordinate of start position
     * @param startY_ y coordinate of start position
     * @param goalX_ x coordinate of end position
     * @param goalY_ y coordinate of end position
     */
    PathfindingAStar(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_);

    int myMaze[N][M];
    int startX;
    int startY;
    int goalX;
    int goalY;
    int sol[N][M]{};
    StarNode * matrix[N][M];
    std::list<StarNode*> openList;
    std::list<StarNode*> closedList;
    /**
     * @brief Pathfinding method that checkss all the possible paths and sets the shortest in
     * a solution matrix
     * @return boolean if there's a path
     */
    bool findPath();
    /**
     * @brief auxiliary method for findPath()
     * @param node_
     * @return bool
     */
    bool solveUtil(StarNode* node_);
    /**
     * @brief adds the nodes around the current one to an open list
     * @param node_ current star node
     */
    void addNeighbors(StarNode *node_);
    /**
     * @brief checks if a node is in the open list
     * @param node_ the star node to check
     * @return boolean if is in the open list or not
     */
    bool existsInOpenList(StarNode *node_);
    /**
     * @brief checks if a cell is out of matrix boundaries
     * @param x horizontal coordinate of the cell
     * @param y vertical coordinate of the cell
     * @return boolean result
     */
    bool isSafe(int x, int y);
    /**
     * @brief initializes a solution matrix
     * @param node_ reference node for the solution matrix
     */
    void createSol(StarNode *node_);
    /**
     * @brief prints result with shortest path
     * @param result in matrix values
     */
    void printSol(int sol[N][M]);
    /**
     * @brief checks if a star node is in the closed list
     * @param node_ check-in
     * @return boolean result
     */
    bool existsInClosedList(StarNode *node_);
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PATHFINDINGASTAR_H
