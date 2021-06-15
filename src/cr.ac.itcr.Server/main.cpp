#include <iostream>
#include "mServer.h"
#include <cstring>
using namespace std;
int mat[20][30];
int main() {

    mServer *server = new mServer(54000, 1024);
    server->runServer();

    return 0;
}
