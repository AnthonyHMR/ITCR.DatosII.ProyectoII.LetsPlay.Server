#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H


#include <string>

using namespace std;

class mServer {
public:
    mServer(int port, int size);
    ~mServer();
    int runServer();
    void getMessage();
    void sendMessage(string message);
private:
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
};



#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_MSERVER_H
