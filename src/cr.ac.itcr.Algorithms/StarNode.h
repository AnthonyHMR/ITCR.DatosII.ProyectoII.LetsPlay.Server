//
// Created by juanpr on 13/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_STARNODE_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_STARNODE_H

#include <iostream>
class StarNode {
/**
 * @class StarNode class represents all cells in a matrix that can and can not be used
 * for pathfinding
 */
public:
    /**
     * @brief Class constructor
     * @param x_ horizontal coordinate
     * @param y_ vertical coordinate
     * @param safe_ boolean that checks a cell
     * @param parent_ pointer to the parent StarNode
     */
    StarNode(int x_, int y_, bool safe_, StarNode *parent_);
    /**
     * @brief Class constructor
     * @param x_ horizontal coordinate
     * @param y_ vertical coordinate
     * @param safe_ boolean that checks a cell
     * @param H_ Heuristic function
     */
    StarNode(int x_, int y_, bool safe_, int H_);

    StarNode * parent;
    int x;
    int y;
    bool safe;

    int H;
    int G;
    int F;
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_STARNODE_H
