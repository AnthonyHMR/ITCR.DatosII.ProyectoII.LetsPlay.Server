//
// Created by juanpr on 29/5/21.
//

#include <fstream>
#include "JsonParser.h"
using namespace std;
void JsonParser::readGameSetUp(){
    ifstream gameSU("../Player.json");
    json gameSetUp;
    gameSU >> gameSetUp;
    for (int i = 0; gameSetUp["Players"].size() != i; i++) {
        player->setId(gameSetUp["Players"][i]["ID"]);
        player->setPosX(gameSetUp["Players"][i]["PosX"]);
        player->setPosY(gameSetUp["Players"][i]["PosY"]);
        player->setTeam(gameSetUp["Players"][i]["Team"]);
        cout << "Player ID: " << player->getId() <<endl;
    }

    if (gameSetUp["GameMode"] == 1) {
        cout << "Set the A-star pathfinding algorithm"<<endl;
    }
    if (gameSetUp["GameMode"] == 2) {
        cout << "Set the backtracking algorithm "<<endl;
    }
}
void JsonParser::readPlayerPath(){
    //Search for the player in the list and use the pathfnding algorithm

}
void JsonParser::writePath(){
    //
    int pathExample[4][2] = { {1,0},{1,1}, {1,2}, {1,3} };
    ofstream shortestPath("../shortestPath.json");
    json myPath;
    myPath["Path"] = pathExample;
    myPath >> shortestPath;
}