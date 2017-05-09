//NAME: JONATHAN RINFRET
//INSTRUCTOR: PAM WIESE
//DATE: 5/26/16
//COMPILER: CODE BLOCKS 16.01
//ASSIGNMENT: VIDEO GAME FINAL

//linked_list.h
//DEFINITION OF A LINKED_LIST CLASS THAT USES THE NODE CLASS

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class linked_list
{
public:
    linked_list();

    int erase (string target);
    bool erase_one (string target);
    void insert (const int& health, string name, string weapon, int damage);    //INSERTS A LINKED LIST CHARACTER
    Node* get_head_ptr() {return head_ptr;}
    string display_name();              //DISPLAYS THE CHARACTER NAME
    int display_health(int damage);     //DISPLAYS THE CHARACTER HEALTH
    int display_damage();               //DISPLAYS THE WEAPON DAMAGE
    string display_weapon();            //DISPLAYS THE CHARACTER WEAPON
    int weapon_choice(linked_list L1);  //SENDS A LINKED LISTS TO CHOOSE ITS WEAPON
    int get_health();                   //DISPLAYS THE CHARACTERS HEALTH


private:
    Node* head_ptr;
    int num_nodes;

};

bool Battle(linked_list L1, linked_list L2);    //THE BATTLE FUNCTION: SENDS TWO LINKED LISTS TO BATTLE EACH OTHER
void intro();                                   //INTRO TO THE GAME
void outro();                                   //THE FIRST OUTRO TO THE GAME
void outro_2();                                 //THE SECOND OUTRO
void outro_3();                                 //THE THIRD OUTRO
void outro_4();                                 //THE FOURTH OUTRO
void Display_Space();                           //DISPLAYS EMPTY SPACE TO ADVANCE THE GAME
void Break_Space(linked_list L1);               //DISPLAYS A TRANSITION STATEMENT BETWEEN BATTLES
void Display_Battle(linked_list L2);            //DISPLAYS THE BATTLE SCENE
#endif // LINKED_LIST_H
