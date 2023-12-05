//
// Created by james on 12/3/2023.
//

#ifndef WEEK10DI_CUSTOMLINKEDLIST_H
#define WEEK10DI_CUSTOMLINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
    T value;
    Node* next;

    Node(T aValue, Node* aNextPtr = nullptr){
        value = aValue;
        next = aNextPtr;
    }
};

// TODO: Given a first and last node as a section of linked list, find the middle node
template<class T>
Node<T>* findMiddle(Node<T>*& first, Node<T>*& last){

    if(nullptr == first){
        return nullptr;
    }
    Node<T>* averageNode = first;
    Node<T>* quickNode = first->next;
        while((last != averageNode) && (last != quickNode)){
            quickNode = quickNode->next;
            if(last != quickNode){
                quickNode = quickNode->next;
                averageNode = averageNode->next;
            }
        }
        return averageNode;


}


template<class T>
class UnsortedLinkedList {
private:
    Node<T>* head = nullptr;

public:
    void printList(){
        Node<T>* nodePtr = head;
        while(nodePtr != nullptr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

    // TODO: Append aValue to the end of the list
    void append(T aValue){
        Node<T>* tempNode = new Node(aValue);
        Node<T>* currentNode = head;
        if(nullptr == head){
            head = tempNode;
        } else {
            while(nullptr != currentNode->next){
                currentNode = currentNode->next;
            }
            currentNode->next = tempNode;
        }

    }

    // TODO: Search for aValue using linear search, return if the value is in the list or not.
    bool linearSearch(T aValue){
        Node<T>* currentNode = head;
        if(nullptr == head){
            return false;
        } else if(aValue == head->value){
            return true;
        } else {
            while(nullptr != currentNode){
                if(aValue == currentNode->value){
                    return true;
                }
                currentNode = currentNode->next;
            }
        }
        return false;
    }
};

template<class T>
class SortedLinkedList {
private:
    Node<T>* head = nullptr;

public:

    // Inserts a node in ascending order to the linked list
    void insertSorted(T aValue){
        Node<T>* newNode = new Node(aValue);
        Node<T>* nodePtr;
        Node<T>* prevNode = nullptr;

        if (head == nullptr){
            head = newNode;
        }
        else {
            nodePtr = head;

            // Skip all nodes less than the new value
            while(nodePtr != nullptr && nodePtr->value < aValue){
                prevNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // If the new node needs to be inserted as head
            if (prevNode == nullptr){
                head = newNode;
                newNode->next = nodePtr;
            }
            else { // insert after previous node
                prevNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
    }

    void printList(){
        Node<T>* nodePtr = head;
        while(nodePtr != nullptr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

    // TODO: Uses binary search to find aValue, return if the value is found or not.
    bool binarySearch(T aValue) {
        Node<T> *start = head;
        Node<T> *end = nullptr;
        Node<T> *middle;
        do {
            middle = findMiddle(start, end);
            if (nullptr == middle) {
                return false;
            } else {
                if (aValue == middle->value)
                    return true;
                else if (middle->value < aValue)
                    start = middle->next;
                else
                    end = middle;
            }
        } while(nullptr == end || end != start);
        return false;
    }
};


#endif //WEEK10DI_CUSTOMLINKEDLIST_H
