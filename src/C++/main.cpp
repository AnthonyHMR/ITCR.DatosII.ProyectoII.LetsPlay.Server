#include <iostream>
#include "mServer.h"

int main() {
    mServer *server = new mServer(54000, 1024);
    server->runServer();

    return 0;
}
