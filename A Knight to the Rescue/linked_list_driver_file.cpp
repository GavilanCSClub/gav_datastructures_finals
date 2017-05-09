//NAME: JONATHAN RINFRET
//INSTRUCTOR: PAM WIESE
//DATE: 5/26/16
//COMPILER: CODE BLOCKS 16.01
//ASSIGNMENT: VIDEO GAME FINAL

//linked_list_driver_file.cpp
#include<iostream>
#include "node.h"
#include "linked_list.h"
using namespace std;

int main()
{
    string answer="y";      //DO WHILE LOOP TO CONTINUE PLAYING
    do
    {
        intro();
        linked_list Player;     //LINKED LIST FOR THE PLAYER

        string player_name;     //IPUTS THE PLAYERS PARAMETERS
        string player_weapon;
        int health=100;
        int weapon_damage;
        cout<<"WHAT IS YOUR NAME GREAT WARRIOR?"<<endl;
        cin>>player_name;
        weapon_damage=Player.weapon_choice(Player);
        if(weapon_damage==30)
        {
            player_weapon="HALBERD";
        }
        if(weapon_damage==25)
        {
            player_weapon="SWORD AND SHIELD";
        }
        if(weapon_damage==20)
        {
            player_weapon="SHORTSWORD";
        }

        Player.insert(health, player_name, player_weapon, weapon_damage);       //SETS A NODE TO THE PLAYERS INPUTS

        linked_list Enemies;        //THE LINKED LIST OF ENEMIES

        Enemies.insert(100, "DRAGON", "CLAWS", 20);
        Enemies.insert(50, "WIZARD", "SPELLBOOK", 25);
        Enemies.insert(70, "ORC", "CLUB", 15);
        Enemies.insert(55, "GUARD", "SPEAR", 10);
        Enemies.insert(40, "SOLDIER", "SWORD", 8);

        int i=0;
        for(i=0;Enemies.get_head_ptr()!=NULL;i++)       //A FOR LOOP FOR THE BATTLE FUNCTION

            if(Battle(Player, Enemies)==true)   //WIN CONDITION
            {
                Display_Space();        //DISPLAY SPACE TO ADVANCE SPACING
                if(Enemies.display_name()!="DRAGON")
                {
                    Break_Space(Player);    //BREAK SPACE BETWEEN BATTLES
                }
                Enemies.erase_one(Enemies.display_name());  //ERASES AN ENEMY NODE
                if(Enemies.get_head_ptr()==NULL)    //FOR AFTER THE BATTLE FUNCTION
                {
                    if(Player.display_weapon()=="HALBERD")  //WIN CONDITION FOR HALBERD
                    {
                        outro_3();
                        cout<<"\nTHANK YOU FOR PLAYING!!!\nWOULD YOU LIKE TO PLAY AGAIN? Y OR N"<<endl;
                        cin>>answer;
                    }
                    if(Player.display_weapon()=="SHORTSWORD")   //WIN CONDITION FOR SHORTSWORD
                    {
                        outro_2();
                        cout<<"\nTHANK YOU FOR PLAYING!!!\nWOULD YOU LIKE TO PLAY AGAIN? Y OR N"<<endl;
                        cin>>answer;
                    }
                    if(Player.display_weapon()=="SWORD AND SHIELD") //WIN CONDITION FOR SWORD AND SHIELD
                    {
                        outro();
                        cout<<"\nTHANK YOU FOR PLAYING!!!\nWOULD YOU LIKE TO PLAY AGAIN? Y OR N"<<endl;
                        cin>>answer;
                    }
                }
            }
            else        //LOSE CONDITION
            {
                cout<<"\n\n\nYOU HAVE BEEN DEFEATED!!!!!!!!!!!!"<<endl;
                if(Enemies.display_name()=="DRAGON")
                {
                   outro_4();
                }
                cout<<"WOULD YOU LIKE TO PLAY AGAIN?"<<endl;
                cin>>answer;
            }
    }
    while(answer=="Y"|| answer=="y");

    return 0;
}

