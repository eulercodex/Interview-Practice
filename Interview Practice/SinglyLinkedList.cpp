//
//  LinkedList.cpp
//  Interview Practice
//
//  Created by Jesse Mihigo on 1/30/19.
//  Copyright © 2019 Jesse. All rights reserved.
//

#include <stdio.h>

template <class T>
struct LinkedListNode {
    T data;
    LinkedListNode<T> * next = nullptr;
};

template<class T>
class SinglyLinkedList {
public:
    SinglyLinkedList(T data);
    LinkedListNode<T> * head;
    void appendToTail(T data);
    void deleteNodeWithData(T data);
    static void print(LinkedListNode<T> * node);
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T data) {
    head = new LinkedListNode<T>;
    head->data = data;
}

template <class T>
void SinglyLinkedList<T>::appendToTail(T data) {
    LinkedListNode<T> * node = head;
    while(node->next != nullptr)
        node = node->next;
    LinkedListNode<T> * newNode = new LinkedListNode<T>;
    newNode->data = data;
    node->next = newNode;
}

template <class T>
void SinglyLinkedList<T>::deleteNodeWithData(T data) {
    if(head == nullptr)
        return;
    LinkedListNode<T> * node = head;
    if(node->data == data) {
        LinkedListNode<T> * temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(node->next != nullptr) {
        if(node->next->data == data) {
            LinkedListNode<T> * temp = node->next;
            node->next = node->next->next;
            delete temp;
            return;
        }
        node = node->next;
    }
    return;
}

template <class T>
void SinglyLinkedList<T>::print(LinkedListNode<T> * node) {
    std::cout <<"Linked List: ";
    while(node != nullptr) {
        std::cout << node->data <<"->";
        node = node->next;
    }
    std::cout<<"nullptr"<<std::endl;
}
