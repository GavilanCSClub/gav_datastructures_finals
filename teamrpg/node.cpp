//File Name: node.cpp
//Purpose: Node class implementation file for the rpg.
//Author: Chris Estes
//Date: 5-20-2016
//Compiler: Code::Blocks 16.01
#include"node.h"
#include<cstdlib>

using namespace std;
//hp, attack, name, id, link
Node::Node(const int h, const int a, string n, const int i, Node* initLink){
    HP = h;
    attack = a;
    name = n;
    id = i;
    link = initLink;
}
//insert head node
void listHeadInsert(Node*& headPtr, int h, int a, string n, int i){
    headPtr = new Node(h, a, n, i, headPtr);
}
//remove head node
void listHeadRemove(Node*& headPtr){
    Node* removePtr;
    removePtr = headPtr;
    headPtr = headPtr->getLink();
    delete removePtr;
}
//search the list for an id
Node* listSearch(Node*& headPtr, const int target){
    Node* cursor = headPtr;
    if(target == 0){
        return cursor;
    }
    for(cursor = headPtr; cursor!= NULL; cursor = cursor->getLink()){
        if (target == cursor->getID()){
            return cursor;
        }
        return NULL;
    }
    return NULL;
}
//remove a node
void listRemove(Node*& prevPtr){
    Node* removePtr;
    removePtr = prevPtr ->getLink();
    prevPtr->setLink(removePtr->getLink());
    delete removePtr;
}
//complete clear a linked list
void listClear(Node*& headPtr){
    while(headPtr!= NULL){
        listHeadRemove(headPtr);
    }
}
