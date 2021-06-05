//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#include <iostream>
#include "Node.h"


class LinkedList {
public:
    Node *head;
    Node *tail;
    int size = 0;
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void Add(Player *data){
        if (isEmpty()){
            this->head = new Node(data);
            this->tail = this->head;
            size ++;

        }
        else {
            // The list isn't empty
            if(this->tail == this->head) {
                // The list has one element
                this->tail = new Node(data);

                this->head->setNext(this->tail);
                size ++;
            } else {
                // The list has more than one element
                Node* newData = new Node(data);
                this->tail->setNext(newData);
                this->tail = newData;
                size++;
            }
        }
    }
    bool isEmpty(){
        if (this->head == nullptr) return true;
        else return false;
    }
    Player * getData(int index){
        if(index == 0) {
            // Get the first element
            return this->head->getData();
        } else {
            // Get the index'th element
            Node* curr = this->head;
            for(int i = 0; i < index; ++i) {
                curr = curr->getNext();
            }
            return curr->getData();
        }
    }
    Player operator[](int index){
        return *getData(index);
    }

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
