#include <iostream>
#include "mServer.h"
#include "../cr.ac.itcr.Algorithms/JsonParser.h"
#include "../cr.ac.itcr.Algorithms/Backtracker.h"
#include "../cr.ac.itcr.DataStructures/LinkedList.h"
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
    LinkedList<std::string> list;
    list.Add("prueba0");
    list.Add("prueba1");
    list.Add("prueba2");
    std::cout << list[1] << std::endl;


//    mServer *server = new mServer(54000, 1024);
//    server->runServer();*/

    return 0;
}
