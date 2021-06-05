#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H


#include <string>
#include <nlohmann/json.hpp>
#include "../cr.ac.itcr.DataStructures/LinkedList.h"
#include "../cr.ac.itcr.Algorithms/Player.h"
#include "../cr.ac.itcr.Algorithms/JsonParser.h"
using namespace std;
using json = nlohmann::json;
class mServer {
public:
    mServer(int port, int size);
    ~mServer();
    int runServer();
    void getMessage();
    void sendMessage(string message);
    void processMessage(string message);
private:
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    LinkedList<Player> *team1;
    LinkedList<Player> *team2;
    JsonParser *jsonParser = new JsonParser();
    int gameMode = 0;

};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
