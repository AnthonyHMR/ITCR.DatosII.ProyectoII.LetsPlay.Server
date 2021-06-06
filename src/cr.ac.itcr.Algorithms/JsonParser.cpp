//
// Created by juanpr on 29/5/21.
//

#include <fstream>
#include "JsonParser.h"
using namespace std;
void JsonParser::readGameSetUp(json gameSet, LinkedList *team1, LinkedList *team2){

    for (int i = 0; gameSet["Players"].size() != i; i++) {
        Player *currentPlayer = new Player();
        currentPlayer->setId(gameSet["Players"][i]["ID"]);
        currentPlayer->setPosX(gameSet["Players"][i]["PosX"]);
        currentPlayer->setPosY(gameSet["Players"][i]["PosY"]);
        currentPlayer->setTeam(gameSet["Players"][i]["Team"]);
        cout << "Player ID: " << currentPlayer->getId() << " Player addr: " << &currentPlayer<<endl;
        if(currentPlayer->getTeam() == 1){
            team1->Add(currentPlayer);
        }
        else if (currentPlayer->getTeam() == 2){
            team2->Add(currentPlayer);
        }
    }

}

void JsonParser::writePath(int M, int x, int y){
    //
    int pathExample[4][2] = { {1,0},{1,1}, {1,2}, {1,3} };
    ofstream shortestPath("../shortestPath.json");
    json myPath;
    myPath["Path"] = pathExample;
    myPath >> shortestPath;
}