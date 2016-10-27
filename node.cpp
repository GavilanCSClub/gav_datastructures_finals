//NAME: JONATHAN RINFRET
//INSTRUCTOR: PAM WIESE
//DATE: 5/26/16
//COMPILER: CODE BLOCKS 16.01
//ASSIGNMENT: VIDEO GAME FINAL

//node.cpp

#include<iostream>
#include<string>
#include "node.h"
using namespace std;

Node::Node(int health, string name, string weapon, int damage,  Node* link_ptr)
{
    character_health=health;
    character_name=name;
    character_weapon=weapon;
    weapon_damage=damage;
    link=link_ptr;
}



//functions for linked_list

int list_length(/*const*/ Node* head_ptr)
{
    /*const*/Node* cursor;
    int answer=0;

    for(cursor=head_ptr; cursor!=NULL; cursor=cursor->get_link())
    {
        answer++;
    }
    return answer;
}

void list_head_insert(Node*& head_ptr, int health, string name, string weapon, int damage)
{
    head_ptr=new Node(health, name, weapon, damage, head_ptr);

}

void list_insert(Node*& prev_ptr, const int health, string name, string weapon, int damage)
{
    Node* insert_ptr;

    insert_ptr=new Node(health, name, weapon, damage, prev_ptr->get_link());
    prev_ptr->set_link(insert_ptr);

}
/////////////////////////////////////////////////////
Node* list_search(Node*& head_ptr, string target)
{
    Node* cursor;

    for(cursor=head_ptr; cursor!=NULL; cursor=cursor->get_link())
    {
        if(target==cursor->get_character_name())
        {
            return cursor;
        }
    }

    return NULL;
}

Node* list_locate(Node*& head_ptr, const int position)
{
    Node* cursor;
    int i;

    cursor=head_ptr;

    for(i=1; (i<position)&& (cursor!=NULL); i++)
    {
        cursor=cursor->get_link();
    }
    return cursor;
}

void list_head_remove(Node*& head_ptr)
{
    Node* remove_ptr;
    remove_ptr=head_ptr;
    head_ptr=head_ptr->get_link();
    delete remove_ptr;
}

void list_remove(Node*& prev_ptr)
{
    Node* remove_ptr;
    remove_ptr=prev_ptr->get_link();
    prev_ptr->set_link(remove_ptr->get_link());
    delete remove_ptr;
}

void list_clear(Node*& head_ptr)
{
    while(head_ptr!=NULL)
    {
        list_head_remove(head_ptr);
    }
}


