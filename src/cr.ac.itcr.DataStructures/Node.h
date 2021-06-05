//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#include <iostream>
#include "../cr.ac.itcr.Algorithms/Player.h"

class Node {
private:
    Node *next ;
    Player *data ;
public:
    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    Player *getData() const {
        return data;
    }

    void setData(Player *data) {
        Node::data = data;
    }
    Node(Player *data, Node *next){
        this->data = data;
        this->next = next;
    }
    Node(Player *data){
        this->data = data;
        this->next = NULL;
    }
};

#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
