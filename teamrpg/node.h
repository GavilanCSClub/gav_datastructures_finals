//File Name: node.h
//Purpose: Node class specification file for the rpg.
//Author: Chris Estes
//Date: 5-20-2016
//Compiler: Code::Blocks 16.01
#ifndef NODE_H
#define NODE_H
#include<cstdlib>
#include<string>
using namespace std;
class Node {
public:
    //Constructor (contains default values)
    Node(const int h = 10, const int a = 5, string n = "", const int i = 0, Node* initLink = NULL);
    //Mutators
    void setHP(const int& h){HP = h;}
    void setAttack(const int& a){attack = a;}
    void setLink(Node* l){link = l;}
    void setID(const int& i){id = i;}
    void setName(string n){name = n;}
    //Accessors
    int getHP() const {return HP;}
    int getAttack() const {return attack;}
    string getName() const {return name;}
    int getID() const {return id;}
    Node* getLink() const{return link;}
private:
    //Nodes now have HP, attack, a name and an id
    int HP;
    int attack;
    string name;
    int id;
    Node* link;
};
//linked list functions
void listHeadInsert(Node*& headPtr, int h, int a, string n, int i);
void listHeadRemove(Node*& headPtr);
Node* listSearch(Node*& headPtr, const int target);
void listRemove(Node*& prevPtr);
void listClear(Node*& headPtr);
#endif // NODE_H
