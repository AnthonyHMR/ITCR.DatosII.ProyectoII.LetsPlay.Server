//
// Created by juanpr on 2/6/21.
//

#ifndef ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#define ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
#include <iostream>
template <class T>
class Node {
private:
    Node<T> *next ;
    T data ;
public:
    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        Node::data = data;
    }
    Node(T data, Node<T> &next){
        this->data = data;
        this->next = next;
    }
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

#endif //ITCR_DATOSII_PROYECTOII_LETSPLAY_SERVER_NODE_H
