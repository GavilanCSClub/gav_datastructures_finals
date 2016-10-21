//File Name: linkedList.cpp
//Purpose: Linked list class implementation file for the rpg.
//Author: Chris Estes
//Date: 5-20-2016
//Compiler: Codeblocks 16.01
#include"linkedList.h"
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
//Constructor
LinkedList::LinkedList(){
    headPtr = NULL;
    numNodes = 0;
}

//used for removing enemy nodes
void LinkedList::eraseOne(const int& target){
    Node* targetPtr;
    if(target == 0){
        cout << "You killed their leader! Any remaining goblins flee." << endl;
    }
    else if(target > 0){
    targetPtr = listSearch(headPtr, target);
    targetPtr->setAttack(headPtr->getAttack());
    targetPtr->setHP(headPtr->getHP());
    targetPtr->setID(headPtr->getID());
    targetPtr->setName(headPtr->getName());
    listHeadRemove(headPtr);
    numNodes--;
    }
}
//inserts a new node
void LinkedList::insert(const int& hp, const int& a, string n, int i){
    listHeadInsert(headPtr, hp, a, n, i);
    numNodes++;
}
//Function used for finding the attack of a node with the passed in id#
int LinkedList::findAttack(const int& id){
    int targetAttack;
    Node* cursor;
    if (id == 0){
        cursor = headPtr;
        targetAttack = cursor->getAttack();
    }
    else if (id > 0){
        for(cursor = headPtr; cursor != NULL; cursor = cursor->getLink()){
            if(id == cursor->getID()){
            targetAttack = cursor->getAttack();
            }
        }
    }
    return targetAttack;
}
//Function used for finding the HP of a node with the passed in id#
int LinkedList::findHP(const int& id){
    int targetHP;
    Node* cursor;
    if (id == 0){
        cursor = headPtr;
        targetHP = cursor->getHP();
    }
    else if (id > 0){
        for(cursor = headPtr; cursor != NULL; cursor = cursor->getLink()){
            if(id == cursor->getID()){
            targetHP = cursor->getHP();
            }
        }
    }
    return targetHP;
}
//Prints out the linked list
void LinkedList::showList(){
    Node* cursor;
    for(cursor = headPtr; cursor != NULL; cursor = cursor->getLink()){
        cout << cursor->getName() << ":" << endl;
        cout << "HP: " << cursor->getHP() << " | Atk: " << cursor->getAttack() << endl << endl;
    }
    cout << endl;
}
//function called when applying damage to a player or enemy, finds them via id#
void LinkedList::damage(const int& id, const int dmg){
    Node* cursor;
    if (id == 0){
        cursor = headPtr;
        cursor->setHP((cursor->getHP()-dmg));
    }
    else {
    for(cursor = headPtr; cursor != NULL; cursor = cursor->getLink()){
        if(cursor->getID() == id){
            //update health
            cursor->setHP((cursor->getHP()-dmg));
            }
        }
    }
}
//function called when in the recovery phase and recovering hp
void LinkedList::recoverHP(){
int randHP = 0;
Node* cursor;
srand(time(NULL));
//generate random value to add back to player health
randHP = (rand()%10);
cursor = headPtr;
cursor->setHP(cursor->getHP()+randHP);
cout << "Recovered: " << randHP << " HP!" << endl;
}

//function for clearing a list
void LinkedList::delList(){
    listClear(headPtr);
    numNodes = 0;
}
