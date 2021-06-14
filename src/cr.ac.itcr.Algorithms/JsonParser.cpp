//
// Created by juanpr on 29/5/21.
//

#include <fstream>
#include "JsonParser.h"
using namespace std;
void JsonParser::readGameSetUp(json gameSet, LinkedList *team1, LinkedList *team2){

    for (int i = 0; i < gameSet["Players"].size() ; i++) {
        Player *currentPlayer = new Player();
        currentPlayer->setId(gameSet["Players"][i]["ID"]);
        currentPlayer->setPosX(gameSet["Players"][i]["PosY"]);
        currentPlayer->setPosY(gameSet["Players"][i]["PosX"]);
        currentPlayer->setTeam(gameSet["Players"][i]["Team"]);
        cout << "Player ID: " << currentPlayer->getId() << " Player addr: " << &currentPlayer<<endl;
        if(currentPlayer->getTeam() == 1){
            cout<<"Adding player to team 1"<<endl;
            team1->Add(currentPlayer);
        }
        else if (currentPlayer->getTeam() == 2){
            cout<<"Adding player to team 2"<<endl;
            team2->Add(currentPlayer);
        }
    }

}

void JsonParser::writePath(int x, int y){
    //
    int path[2] = {x, y};
    ifstream shortestPath("../shortestPath.json");
    json myPath;
    shortestPath >> myPath;
    myPath["Path"] += path;

    ofstream writeJson;
    writeJson.open("../shortestPath.json");
    writeJson << myPath;
    writeJson.close();

}

string JsonParser::sendPath() const {
    ifstream shortest("../shortestPath.json");
    json sendPath;
    shortest >> sendPath;
    shortest.close();
    return to_string(sendPath);
}

void JsonParser::cleanPath() {
    ofstream shortest;
    shortest.open("../shortestPath.json");
    ifstream cleaner("../cleanPath.json");
    json clean;
    cleaner >> clean;
    shortest << clean;
    shortest.close();
    cleaner.close();
}
