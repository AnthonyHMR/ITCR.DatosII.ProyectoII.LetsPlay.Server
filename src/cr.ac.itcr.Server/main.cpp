#include <iostream>
#include "mServer.h"
#include "../cr.ac.itcr.Algorithms/JsonParser.h"
#include "../cr.ac.itcr.Algorithms/Backtracker.h"
#include <string>
using namespace std;
int main() {
    auto *backtracker = new Backtracker();
    backtracker->runExample();
    auto *parser = new JsonParser();
    string data = "Game set up";
    parser->readGameSetUp();
    parser->readPlayerPath();
    parser->writePath();

//    mServer *server = new mServer(54000, 1024);
//    server->runServer();*/

    return 0;
}
