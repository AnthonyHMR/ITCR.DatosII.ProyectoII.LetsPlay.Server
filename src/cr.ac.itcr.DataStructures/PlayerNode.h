//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYERNODE_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYERNODE_H
#include <iostream>
#include "../cr.ac.itcr.Algorithms/Player.h"

using namespace std;
class PlayerNode {
    /**
     * @class Node class has a player pointer and next node pointer used for a
     * singly linked list implementation
     */
private:
    PlayerNode *next ;
    Player *data ;
public:
    /**
     * @brief getter method of the next node
     * @returns next
     */
    PlayerNode *getNext() const {
        return next;
    }
    /**
     * @brief setter method of the next node
     */
    void setNext(PlayerNode *next) {
        PlayerNode::next = next;
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
        PlayerNode::data = data;


    }
    /**
     * @brief Constructor that initializes a data and its next node
     * @param data is the player
     * @param next is the pointer to the next Node
     */
    PlayerNode(Player *data, PlayerNode *next){
        this->data = data;
        this->next = next;
    }
    /**
     * @brief Constructor that initializes a data
     * @param data is the player
     */
    PlayerNode(Player *data){
        this->data = data;
        this->next = NULL;
        cout<<"New player adrr: "<< &this->data<<endl;
    }
};

#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_PLAYERNODE_H
