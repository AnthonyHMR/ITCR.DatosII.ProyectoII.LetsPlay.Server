//
// Created by juanpr on 29/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
#include <string>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include "Player.h"
#include "../cr.ac.itcr.DataStructures/LinkedList.h"
#include <iostream>
using namespace std;
using json = nlohmann::json;

class JsonParser {
    /**
     * @class this class performs serialization methods in order to
     * read and write messages in json format
     */

public:
    /**
     * @brief reads the game settings sent by the client and
     * @param gameSet settings that include the game mode and the amount of players to be
     * added
     * @param team1 team number one
     * @param team2 team number two
     */
    void readGameSetUp(json gameSet, LinkedList *team1, LinkedList *team2);
    /**
     * @brief writes the shortest path found by the algorithm
     * @param M integer, represents the amount of blocks the path has
     * @param x integer, x-coordinate of a given block
     * @param y integer, y-coordinate of a given block
     */
    void writePath(int x, int y);
    /**
     * @brief Reads a jsonfile that has the shortest path found by backtrack
     * @return string-json format array of the path
     */
    string sendPath() const;
};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
