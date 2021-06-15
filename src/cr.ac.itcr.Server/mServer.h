#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H

#include <string>
#include <nlohmann/json.hpp>
#include "../cr.ac.itcr.DataStructures/LinkedList.h"
#include "../cr.ac.itcr.Algorithms/Player.h"
#include "../cr.ac.itcr.Algorithms/JsonParser.h"
#include "../cr.ac.itcr.Algorithms/Backtracking.h"
#include "../cr.ac.itcr.Algorithms/PathfindingAStar.h"
#define M 20
#define N 30
using namespace std;
using json = nlohmann::json;
/**
 * @class Server that manages the game flow, executes the pathfinding algorithms,
 * put players in position and stores them in a linked list according to their team
 */
class mServer {
public:
    /**
     * @brief Constructor that has a port where the server is listening requests
     * @param port integer that opens the server connection for a client
     */
    mServer(int port, int size);
    /**
     * @brief object destructor
     */
    ~mServer();
    /**
     * @brief runServer method implements a IP/TCP protocol in the server so that a required client can
     * send and receive data if needed
     */
    int runServer();
    /**
     * @brief getMessage method takes the bytesRecv attribute and stores a given chain of bytes received
     * from a client and casts them into a human readable format (string)
     */
    void getMessage();
    /**
     * @brief sendMessage method sends a stream message to the client with a given response for its request
     * @param message
     */
    void sendMessage(string message);
    /**
     * @brief processMessage searches for the kind of request is made from the client and sets up each request
     * to keep game flow
     * @param message represents a json-formatted string
     */
    void processMessage(string message);
    /**
     * @brief searchPlayer in order to execute a pathfinding algorithm its required to specify a start position
     * in this method, we search a player according to its team and ID provided by the client
     * @param team integer that shows which team the player is in
     * @param ID integer that represents player label
     */
    Player * searchPlayer (int team, int ID);
    /**
     * @brief right after the game set up the player's location is required to
     * specify the obstacles in the matrix
     * @param team list of players
     */
    void storePlayerLocation(LinkedList *team);
private:
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    LinkedList *team1 = new LinkedList();
    LinkedList *team2 = new LinkedList();
    JsonParser *jsonParser = new JsonParser();
    int gameMode = 0;
    int mat[M][N];


};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
