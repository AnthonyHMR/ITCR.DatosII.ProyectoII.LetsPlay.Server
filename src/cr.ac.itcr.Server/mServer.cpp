#include "mServer.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>


using namespace std;

mServer::mServer(int listenPort, int memSize) : port(listenPort), size(memSize) {
    for(int i = 0; i < M; i++) {
        for (int j = 0; j < N ; j++)
            mat[i][j] = 1;
    }
}

int mServer::runServer() {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << "can't create a socket!";
        return -1;
    }

    // Bind the socket to IP / port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr *) &hint, sizeof(hint)) == -1) {
        cerr << "Can't bind to IP/port";
        return -2;
    }

    // Mark to socket for listening in
    if (listen(listening, SOMAXCONN) == -1) {
        cerr << "Can't listen!";
        return -3;
    }
    cout << "\n Listening for a call..."<<endl;
    // Accept a call
    sockaddr_in client;
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    socklen_t clientSize = sizeof(client);

    clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

    if (clientSocket == -1) {
        cerr << "Problem with client connecting!";
        return -4;
    }

    // Close the listening socket
    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr *) &client, clientSize, host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (result) {
        cout << host << "connected on" << svc << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "connected on" << ntohs(client.sin_port) << endl;
    }

    // While receiving display message, echo message

    while (true) {
        // Clear the buffer
        memset(buf, 0, 4096);

        // Wait for a message
        bytesRecv = recv(clientSocket, buf, 4096, 0);

        if (bytesRecv == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0) {
            cout << "The client disconnected" << endl;
            break;
        }

        // Display message
        getMessage();

    }

    // Close socket
    close(clientSocket);
}

void mServer::getMessage() {
    string received = string(buf, 0, bytesRecv);
    cout << "Received: \n" << string(buf, 0, bytesRecv) << endl;
    processMessage(received);
}
void mServer::processMessage(string message){
    json jsonReader = json::parse(message);
    //Revisar json cuando el juego va a inicio, equipos, jugadores
    if (message.find("Players") != string::npos){
        this->jsonParser->readGameSetUp(jsonReader, team1, team2);
        storePlayerLocation(team1);
        storePlayerLocation(team2);
        for(int i = 0; i < M; i++){
            for (int j = 0; j< N; j++)
                printf(" %d ", this->mat[i][j]);
            printf("\n");
        }
        jsonReader["GameMode"].get_to(this->gameMode);
    }
    //Revisar json cuando un jugador va a tirar para generar el camino màs corto
    if (message.find("Shoot") != string::npos){
        jsonParser->cleanPath();
        cout << "Found shooter\n"<<endl;
        Player *Shooter = searchPlayer(jsonReader["Shoot"]["Team"], jsonReader["Shoot"]["ID"]);
        int x = Shooter->getPosX();
        int y = Shooter->getPosY();
        if(gameMode == 1){
            if (Shooter->getTeam() == 1){
                PathfindingAStar aStar(this->mat, x, y, 29, 10);
                aStar.findPath();

                for (int k = 0; k < M; k++){
                    for (int l = 0; l < N; l++) {
                        if(aStar.sol[k][l] == 1){
                            jsonParser->writePath(l*10, k*10);
                        }
                    }
                }
                string shortestPath = jsonParser->sendPath();
                sendMessage(shortestPath);
            }
            else if (Shooter->getTeam() == 2){
                PathfindingAStar aStar(this->mat, 1, 10, x, y);
                aStar.findPath();

                for (int k = 0; k < M; k++){
                    for (int l = 0; l < N; l++) {
                        if(aStar.sol[k][l] == 1){
                            jsonParser->writePath(l*10, k*10);
                        }
                    }
                }
                string shortestPath = jsonParser->sendPath();
                sendMessage(shortestPath);
            }
        }
        else if(gameMode == 2){
            if (Shooter->getTeam() == 1 ){
                Backtracking backtracking(this->mat, x+1, y, 29, 10);
                backtracking.findPath(this->mat);
                for (int k = 0; k < M; k++){
                    for (int l = 0; l < N; l++) {
                        if(backtracking.sol[k][l] == 1){
                            jsonParser->writePath(l*10, k*10);
                        }
                    }
                }
                string shortestPath = jsonParser->sendPath();
                sendMessage(shortestPath);

            }
            else if (Shooter->getTeam() == 2 ){
                Backtracking backtracking(this->mat, 1, 10, x-1, y);
                backtracking.findPath(this->mat);

                for (int k = 0; k < M; k++){
                    for (int l = 0; l < N; l++) {
                        if(backtracking.sol[k][l] == 1){
                            jsonParser->writePath(l*10, k*10);
                        }
                    }
                }
                string shortestPath = jsonParser->sendPath();
                sendMessage(shortestPath);
            }
        }
    }

}
void mServer::sendMessage(string message) {
    // Enter lines of text

    int sendRes = send(clientSocket, message.c_str(), message.size() + 1, 0);
    if (sendRes == -1) {
        cout << "Could not send to client!\r\n";
    }
}
//Recorre la lista de jugadores segùn equipo
Player * mServer::searchPlayer(int team, int ID) {
    if (team == 1){
        int len = team1->size;

        for (int i = 0; i < len; i++){
            Player *current = this->team1->getData(i);
            if(current->getId() == ID){
                return current;
            }
        }
    }
    else if (team == 2){
        int len = team2->size;

        for (int i = 0; i < len; i++){
            Player *current = this->team2->getData(i);
            if(current->getId() == ID){
                return current;
            }
        }
    }
}
void mServer::storePlayerLocation(LinkedList *team){
    for (int i = 0; i < team->size; i ++){
        int x = team->getData(i)->getPosX();
        int y = team->getData(i)->getPosY();
        this->mat[x][y] = 0;
    }
}

mServer::~mServer() {}