//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#include <iostream>
#include "PlayerNode.h"

using namespace std;

class LinkedList {
    /**
     * @class Stores a list of players, implemented as a singly linked list
     */
public:
    PlayerNode *head;
    PlayerNode *tail;
    int size = 0;
    /**
     * @brief Constructor that initializes head and tail nodes
     */
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    /**
     * @brief Add nodes to the front of the list
     * @param data the player to be added
     */
    void Add(Player *data){
        if (isEmpty()){
            this->head = new PlayerNode(data);
            this->tail = this->head;
            size ++;
        }
        else {
            // The list isn't empty
            if(this->tail == this->head) {
                // The list has one element
                this->tail = new PlayerNode(data);

                this->head->setNext(this->tail);
                size ++;
            } else {
                // The list has more than one element
                PlayerNode* newData = new PlayerNode(data);
                this->tail->setNext(newData);
                this->tail = newData;
                size++;
            }
        }
        cout << "Player added"<< endl;
    }
    /**
     * @brief boolean method that checks if the list is empty
     */
    bool isEmpty(){
        if (this->size == 0) return true;
        else return false;
    }
    /**
     * @brief a data getter in list according to its index
     * @param index represents the location of a node in the list
     */
    Player * getData(int index){
        if(index == 0) {
            // Get the first element
            return this->head->getData();
        } else {
            // Get the index-th element
            PlayerNode* curr = this->head;
            for(int i = 0; i < index; ++i) {
                curr = curr->getNext();
            }
            return curr->getData();
        }
    }
    /**
     * @brief Overloading the [] operator in order to get
     * an element in the position required
     * @param index represents the location of a node
     */
    Player operator[](int index){
        return *getData(index);
    }

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
