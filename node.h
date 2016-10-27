//NAME: JONATHAN RINFRET
//INSTRUCTOR: PAM WIESE
//DATE: 5/26/16
//COMPILER: CODE BLOCKS 16.01
//ASSIGNMENT: VIDEO GAME FINAL

//node.h

#ifndef NODE_H
#define NODE_H

#include<cstdlib>
#include<string>
using namespace std;

class Node      //NODE CLASS FOR THE LINKED LIST
{
public:
    Node(int init_health=100, string init_name=" ", string init_weapon=" ",int damage=0, Node* init_link=NULL);     //CONSTRUCTOR FUNCTION FOR A NODE: SETS INTITAL VALUES
    void set_link (Node* link_ptr) {link=link_ptr;}             //SETS THE LINK FOR THE LINKED LIST
    void set_character (string name) {character_name=name;}     //SETS CHARACTERS NAME
    void set_weapon (string weapon) {character_weapon=weapon;}  //SETS CHARACTERS WEAPON
    void set_health (int health) {character_health=health;}     //SETS CHARACTERS HEALTH
    void set_damage (int damage) {weapon_damage=damage;}        //SETS THE DAMAGE A WEAPON DOES

    int get_character_health() {return character_health;}       //RETURNS CHARACTER HEALTH
    int get_weapon_damage() {return weapon_damage;}             //RETURNS THE WEAPONS DAMAGE VALUE
    string get_character_name() {return character_name;}        //RETURNS CHARACTERS NAME
    string get_character_weapon() {return character_weapon;}    //RETURNS THE NAME OF THE CHARACTER WEAPON
    Node* get_link() {return link;}                             //RETURNS THE LINK

private:
    int character_health;
    int weapon_damage;
    string character_name;
    string character_weapon;
    Node* link;

};

//functions to use with linked_list class
// all functions manipulate node objects


int list_length (const Node* head_ptr);
void list_head_insert (Node*& head_ptr, int health, string name, string weapon, int damage);
void list_insert (Node*& prev_ptr, const int health, string name, string weapon);
Node* list_search (Node*& head_ptr, string target);
Node* list_locate (Node*& head_ptr, const int position);
void list_head_remove (Node*& head_ptr);
void list_remove (Node*& prev_ptr);
void list_clear (Node*& head_ptr);

#endif // NODE_H
