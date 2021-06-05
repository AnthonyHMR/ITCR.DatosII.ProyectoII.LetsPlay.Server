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
    Player *player1 = new Player();
    Player *player2 = new Player();
    Player *player3 = new Player();
    player1->setId(1);
    player2->setId(2);
    player3->setId(3);
    LinkedList *list = new LinkedList();
    list->Add(player1);
    list->Add(player2);
    list->Add(player3);
    int len = list->size;
    for(int i = 0; i < len; i++){
        cout<< "ID player: "<< list->getData(i)->getId()<<endl;
    }

//    mServer *server = new mServer(54000, 1024);
//    server->runServer();*/

    return 0;
}
