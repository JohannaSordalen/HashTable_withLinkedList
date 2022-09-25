#pragma once
#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node<T>() {
        next = NULL;
    };
};
template <class T>
class SingleLinkedList : public Node<T> {

public:
    Node<T>* head;
    Node<T>* tail;

    SingleLinkedList<T>() {
        head = new Node<T>();
        tail = new Node<T>();
        head = tail;
    }
    void add(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    void printData() {
        Node<T>* p = head;
        while (p != NULL) {
            std::cout << p->data << " " << std::endl;
            p = p->next;
        }
    }

    void  insertAt(int index, T data) {
        Node<T>* p = head;
        int i = 0;
        while (p->next != NULL && i < index - 1) {
            p = p->next;
            i++;
        }

        Node<T>* ANewNode = new Node<T>();
        ANewNode->data = data;
        ANewNode->next = p->next;
        p->next = ANewNode;
    }

    void  RemoveAt(int index) {
        Node<T>* p = head;
        int i = 0;
        while (p->next != NULL && i < index - 1) {
            p = p->next;
            i++;
        }

        Node<T>* tempNode = p->next;
        p->next = p->next->next;
        tempNode->next = NULL;
        delete tempNode;
    }

};