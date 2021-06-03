//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
#include <iostream>
#include "Node.h"
template<class T>
class LinkedList {
public:
    Node<T> *head;
    Node<T> *tail;
    int size = 0;
    LinkedList<T>(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void Add(T data){
        if (isEmpty()){
            this->head = new Node<T>(data);
            this->tail = this->head;
            size ++;

        }
        else {
            // The list isn't empty
            if(this->tail == this->head) {
                // The list has one element
                this->tail = new Node<T>(data);

                this->head->setNext(this->tail);
                size ++;
            } else {
                // The list has more than one element
                Node<T>* newData = new Node<T>(data);
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
    T getData(int index){
        if(index == 0) {
            // Get the first element
            return this->head->getData();
        } else {
            // Get the index'th element
            Node<T>* curr = this->head;
            for(int i = 0; i < index; ++i) {
                curr = curr->getNext();
            }
            return curr->getData();
        }
    }
    T operator[](int index){
        return getData(index);
    }

};


#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_LINKEDLIST_H
