//
// Created by juanpr on 29/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
#include <string>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include "Player.h"
#include <iostream>
using namespace std;
using json = nlohmann::json;

class JsonParser {
private:
    Player *player = new Player();
public:
    void readGameSetUp();
    void readPlayerPath();
    static void writePath();

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_JSONPARSER_H
