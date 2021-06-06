//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#include <iostream>
#include "../cr.ac.itcr.Algorithms/Player.h"

class Node {
    /**
     * @class Node class has a player pointer and next node pointer used for a
     * singly linked list implementation
     */
private:
    Node *next ;
    Player *data ;
public:
    /**
     * @brief getter method of the next node
     * @returns next
     */
    Node *getNext() const {
        return next;
    }
    /**
     * @brief setter method of the next node
     */
    void setNext(Node *next) {
        Node::next = next;
    }
    /**
     * @brief getter method of the data (Player)
     * @returns data
     */
    Player *getData() const {
        return data;
    }
    /**
     * @brief setter method of the dataa
     */
    void setData(Player *data) {
        Node::data = data;
    }
    /**
     * @brief Constructor that initializes a data and its next node
     * @param data is the player
     * @param next is the pointer to the next Node
     */
    Node(Player *data, Node *next){
        this->data = data;
        this->next = next;
    }
    /**
     * @brief Constructor that initializes a data
     * @param data is the player
     */
    Node(Player *data){
        this->data = data;
        this->next = NULL;
    }
};

#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
