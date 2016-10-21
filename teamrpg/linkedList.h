//File Name: linkedList.h
//Purpose: Linked list class specification file for the rpg.
//Author: Chris Estes
//Date: 5-20-2016
//Compiler: Codeblocks 16.01
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"node.h"

class LinkedList{
public:
    LinkedList();
    //deletes a node (using id)
    void eraseOne(const int& target);
    //adding a new node to team
    void insert(const int& hp, const int& a, string n, int i);
    int listSize() const {return numNodes; }
    //displaying entire team
    void showList();
    //update health
    void damage(const int& id, const int dmg);
    //use id to get correct attack val
    int findAttack(const int& id);
    //use id to get correct hp val
    int findHP(const int& id);
    //used for recovering hp between battles
    void recoverHP();
    //clear list
    void delList();
    //accessors
    Node* getHeadPtr(){return headPtr;}
    int getnumNodes(){return numNodes;}

private:
    Node* headPtr;
    int numNodes;
};
#endif // LINKEDLIST_H
