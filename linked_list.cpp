//NAME: JONATHAN RINFRET
//INSTRUCTOR: PAM WIESE
//DATE: 5/26/16
//COMPILER: CODE BLOCKS 16.01
//ASSIGNMENT: VIDEO GAME FINAL

//linked_list.cpp
#include<iostream>
#include "linked_list.h"
#include<cstdlib>
#include<ctime>

string type = "ALPHA";
string build = "0.1.02";
linked_list::linked_list()      //THE CONSTRUCTOR FUNCTION FOR THE LINKED LIST
{
    head_ptr=NULL;
    num_nodes=0;
}

int linked_list::erase(string target)   //ERASE OR GETS RID OFF A NODE
{
    int answer=0;
    Node* target_ptr;

    target_ptr=list_search(head_ptr, target);
    while(target_ptr!=NULL)
    {
        target_ptr->set_character(head_ptr->get_character_name());
        target_ptr=target_ptr->get_link();
        target_ptr=list_search(target_ptr, target);
        list_head_remove(head_ptr);
        num_nodes--;
        answer++;
    }

    return answer;
}

bool linked_list::erase_one(string target)
{
    Node* target_ptr;
    target_ptr=list_search(head_ptr, target);

    if(target_ptr==NULL)
    {
        return false;
    }

    target_ptr->set_character(head_ptr->get_character_name());
    list_head_remove(head_ptr);
    num_nodes--;

    return true;
}


void linked_list::insert(const int& health, string name, string weapon, int damage) //INSERTS A NEW CHARACTER NODE
{
    list_head_insert(head_ptr, health, name, weapon, damage);
    num_nodes++;
}

string linked_list::display_name()      //DISPLAYS THE CHARACTERS NAME
{
    Node* cursor;
    cursor=head_ptr;
    return cursor->get_character_name();
}

int linked_list::display_health(int damage)     //DISPLAYS THE CHARACTER HEALTH
{
    Node*cursor;
    cursor=head_ptr;
    int health=cursor->get_character_health();
    health=health - damage;
    return health;
}

string linked_list::display_weapon()           //DISPLAYS THE CHARACTERS WEAPON
{
    Node* cursor;
    cursor=head_ptr;
    return cursor->get_character_weapon();

}

int linked_list::display_damage()           //DISPLAYS THE WEAPON DAMAGE
{
    Node* cursor;
    cursor=head_ptr;
    return cursor->get_weapon_damage();

}

int linked_list::weapon_choice(linked_list L1)  //FUNCTION FOR THE PLAYER TO CHOOSE THEIR WEAPON
{
    string choice;
    do
    {
        cout<<"\nCHOOSE YOUR WEAPON FOR YOUR QUEST:"<<endl;
        cout<<endl;
        cout<<"CHOICE(A)"<<endl;
        cout<<"SHORTSWORD- A SMALL WEAPON USED BY COMMANDERS \nAS THEY LEAD THEIR ARMIES INTO BATTLE:"<<endl;

        cout<<"CHOICE(B)"<<endl;
        cout<<"SWORD AND SHIELD- THE STANDARD TOOLS OF CHOICE \nFOR ANY SOLDIER GOING ON AN ADVENTURE:"<<endl;

        cout<<"CHOICE(C)"<<endl;
        cout<<"HALBERD- A DANGEROUS WEAPON ON THE BATTLEFIELD \nUSED ONLY BY THE STRONGEST OF WARRIORS:"<<endl;
        cin>>choice;
        if(choice=="a"||choice=="A")
        {
            return 20;
        }
        if(choice=="B"||choice=="b")
        {
            return 25;
        }
        if(choice=="c"||choice=="C")
        {
            return 30;
        }
    }while(choice!="A" || choice!="a" || choice!="B" || choice!="b" || choice!="C" || choice!="c");
}
void Display_Space()        //DISPLAYS A BLANK SPACE FOR ADVANCEMENT OF THE GAME
{
    for(int i=0;i<18;i++)
    {
        cout<<endl;
    }
}

void Break_Space(linked_list L1)        //DISPLAYS A BREAK SPACE BETWEEN BATTLES
{
    string value;
    srand(time(NULL));
    int r= rand()&10;

    if(r<4)
    {
        cout<<"SIR "<<L1.display_name()<<" SPENT THE TIME AFTER THE BATTLE RESTING.\nTHE WARRIOR SAW A SQUIRREL CROSS THE PATH\nAND DECIDED TO KILL IT FOR FOOD AND HAVE IT FOR DINNER.\nWITH THE COMING OF THE NEXT DAY, \nTHE GREAT WARRIOR RUSHED OFF TO SAVE THE PRINCESS"<<endl<<endl;
    }
    if(r<7 &&r>4)
    {
        cout<<"AFTER DEFEATING THE FOE "<<L1.display_name()<<"\nRESTED FOR A WHILE BEFORE CONTINUING ON THE PERILOUS RESCUE MISSION\nTO SAVE PRINCESS WHATSHERNAME."<<endl<<endl;
    }
    if(r>7)
    {
        cout<<L1.display_name()<<" STOOD OVER HIS FALLEN ENEMY TRIUMPHANTLY. \nTHE GREAT WARRIOR SHOUTED TO THE WORLD\n\"I CAN TAKE ON ANYTHING THAT COMES MY WAY\".\nAS "<<L1.display_name()<<" TOOK A STEP OFF THE ROTTING CARCASS,\nTHE WARRIOR TRIPPED ON A STONE AND FELL."<<endl<<endl;
    }
    cout<<"ARE YOU READY TO CONTINUE TO THE NEXT BATTLE?"<<endl<<endl;
    cout<<"PRESS ANY BUTTON TO CONTINUE:"<<endl;
    cin>>value;
}
void Display_Battle(linked_list L2) //DISPLAYS THE BATTLE SCENARIO
{
    if(L2.display_name()=="SOLDIER")
    {
        cout<<"                              ()        "<<endl;
        cout<<"                             (  )       "<<endl;
        cout<<"    SOLDIER---->         ___(____)___   "<<endl;
        cout<<"                  ()        ( -_- )     "<<endl;
        cout<<"                  ( )    ___|_____|___  "<<endl;
        cout<<"                   ( )   |  |     |  |  "<<endl;
        cout<<"                    ( )  |  |     |  |  "<<endl;
        cout<<"                    _(_)_|  |     |  |  "<<endl;
        cout<<"                      V  |__|_____|__|  "<<endl;
        cout<<"                           ( ______ )   "<<endl;
        cout<<"                          ( )      ( )  "<<endl;
        cout<<"                        _(_)        (_)_"<<endl;
        cout<<"      ()                                "<<endl;
        cout<<"     (__)    <----PLAYER                "<<endl;
        cout<<"    (____)                              "<<endl;
        cout<<"___(______)____                         "<<endl;
        cout<<"   (      )                             "<<endl;
        cout<<"   |      |                             "<<endl;
    }

    if(L2.display_name()=="GUARD")
    {
        cout<<"                  ()                    "<<endl;
        cout<<"                 (  )        ____       "<<endl;
        cout<<"    GUARD---->  (____)   ___(____)___   "<<endl;
        cout<<"                  ()        ( -_- )     "<<endl;
        cout<<"                  ()     ___|_____|___  "<<endl;
        cout<<"                  ()     | ()_____() |  "<<endl;
        cout<<"                  ()_____| ()_____() |  "<<endl;
        cout<<"                  ()_____| ()     () |  "<<endl;
        cout<<"                  ()     |_()_____()_|  "<<endl;
        cout<<"                  ()       ( ______ )   "<<endl;
        cout<<"                  ()      ( )      ( )  "<<endl;
        cout<<"                  ()    _(_)        (_)_"<<endl;
        cout<<"      ()                                "<<endl;
        cout<<"     (__)    <----PLAYER                "<<endl;
        cout<<"    (____)                              "<<endl;
        cout<<"___(______)____                         "<<endl;
        cout<<"   (      )                             "<<endl;
        cout<<"   |      |                             "<<endl;
    }

    if(L2.display_name()=="WIZARD")
    {
        cout<<"                              ()        "<<endl;
        cout<<"                             (**)       "<<endl;
        cout<<"          WIZARD---->    ___(****)___   "<<endl;
        cout<<"                            ( -_- )     "<<endl;
        cout<<"                         ___|_____|___  "<<endl;
        cout<<"                         |  *     *  |  "<<endl;
        cout<<"                         |  *******  |  "<<endl;
        cout<<"                         |  *     *  |  "<<endl;
        cout<<"                         |__*******__|  "<<endl;
        cout<<"                           ( ______ )   "<<endl;
        cout<<"                          ( )      ( )  "<<endl;
        cout<<"                        _(_)        (_)_"<<endl;
        cout<<"      ()                                "<<endl;
        cout<<"     (__)    <----PLAYER                "<<endl;
        cout<<"    (____)                              "<<endl;
        cout<<"___(______)____                         "<<endl;
        cout<<"   (      )                             "<<endl;
        cout<<"   |      |                             "<<endl;
    }

    if(L2.display_name()=="ORC")
    {
        cout<<"                   ()                  "<<endl;
        cout<<"                  (   )      _^_^_      "<<endl;
        cout<<"    ORC---->     (     )    (() ())     "<<endl;
        cout<<"                  (    )   <( VVV )>    "<<endl;
        cout<<"                   (   ) ___|_____|___  "<<endl;
        cout<<"                    (  ) |           |  "<<endl;
        cout<<"                     (  )|  ()   ()  |  "<<endl;
        cout<<"                      ( )|           |  "<<endl;
        cout<<"                       ()|___________|  "<<endl;
        cout<<"                           ( ______ )   "<<endl;
        cout<<"                          ( )      ( )  "<<endl;
        cout<<"                        _(_)        (_)_"<<endl;
        cout<<"      ()                                "<<endl;
        cout<<"     (__)    <----PLAYER                "<<endl;
        cout<<"    (____)                              "<<endl;
        cout<<"___(______)____                         "<<endl;
        cout<<"   (      )                             "<<endl;
        cout<<"   |      |                             "<<endl;
    }

    if(L2.display_name()=="DRAGON")
    {
        cout<<"                                        "<<endl;
        cout<<"             ___________________        "<<endl;
        cout<<"            |   *INSERT IMAGE*  |       "<<endl;
        cout<<"            |       *OF*        |       "<<endl;
        cout<<"            |*DRAGON FINAL BOSS*|       "<<endl;
        cout<<"            |       HERE*       |       "<<endl;
        cout<<"            |___________________|       "<<endl;
        cout<<"                                        "<<endl;
        cout<<"             (to gain dragon picture    "<<endl;
        cout<<"           purchase extended dlc pack   "<<endl;
        cout<<"              for only $1000000)       "<<endl;
        cout<<"                                        "<<endl;
        cout<<"      ()                                "<<endl;
        cout<<"     (__)    <----PLAYER                "<<endl;
        cout<<"    (____)                              "<<endl;
        cout<<"___(______)____                         "<<endl;
        cout<<"   (      )                             "<<endl;
        cout<<"   |      |                             "<<endl;
    }
    return;
}

bool Battle(linked_list L1, linked_list L2)     //THE BATTLE FUNCTION OF THE GAME RETURNSS TRUE OR FALSE BASED ON WIN CONDITION
{
    Display_Space();
    Display_Battle(L2);
    cout<<"YOU ARE CHALLENGED BY "<<L2.display_name()<<endl;
    cout<<"YOUR HEALTH: "<<L1.display_health(0)<<endl;
    cout<<"ENEMIES HEALTH: "<<L2.display_health(0)<<endl;
    string option;
    int i;
    int j=0;
    int k=0;
    for(i=0;;i++)
    {
        cout<<"OPTIONS:\n(A)ATTACK WITH "<<L1.display_weapon()<<" ("<<L1.display_damage()<<" DAMAGE)"<<"\n(B) PUNCH"<<" ("<<20<<" DAMAGE)"<<"\n(ANY OTHER KEY) DO NOTHING"<<endl;
        cin>>option;
        Display_Space();
        if(option=="A"||option=="a")
        {
            Display_Battle(L2);
            cout<<"YOU ATTACK THE "<<L2.display_name()<<" WITH THE "<<L1.display_weapon()<<" ("<<L1.display_damage()<<" DAMAGE)"<<endl;
            cout<<"THE ENEMIES HEALTH IS NOW AT ";
            j=j+L1.display_damage();
            if(L2.display_health(j)<=0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<L2.display_health(j)<<endl;
            }
            if(L2.display_health(j)<=0)
            {
                cout<<"YOU WON!!!"<<endl;
                return true;
            }
        }
        if(option=="B"||option=="b")
        {
            Display_Battle(L2);
            cout<<"YOU ATTACK THE "<<L2.display_name()<<" WITH A PUNCH!"<<" ("<<20<<" DAMAGE)"<<endl;
            cout<<"THE ENEMIES HEALTH IS NOW AT ";
            j=j+20;
            if(L2.display_health(j)<=0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<L2.display_health(j)<<endl;
            }
            if(L2.display_health(j)<=0)
            {
                cout<<"YOU WON!!!"<<endl;
                return true;
            }

        }
        if(option!="A"||option!="a" || option!="B"||option!="b")
        {
            Display_Battle(L2);
            cout<<"YOU ATTACK THE "<<L2.display_name()<<" BY DOING NOTHING"<<endl;
            cout<<"THE ENEMIES HEALTH IS NOW AT ";
            if(L2.display_health(j)<=0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<L2.display_health(j)<<endl;
            }
            if(L2.display_health(j)<=0)
            {
                cout<<"YOU WON!!!"<<endl;
                return true;
            }
        }
        cout<<"THE "<<L2.display_name()<<" ATTACKS YOU WITH IT'S "<<L2.display_weapon()<<" ("<<L2.display_damage()<<" DAMAGE)"<<endl;
        cout<<"YOUR HEALTH IS NOW AT ";
        k=k+L2.display_damage();
        if(L1.display_health(k)<0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<L1.display_health(k)<<endl;
        }
        if(L1.display_health(k)<=0)
        {
            cout<<"YOU LOST!!!"<<endl;
            return false;
        }

    }
}

void intro()        //THE INTRO TO THE VIDEO GAME
{
    string value;
    Display_Space();
    cout<<"\t\t\t::::A KNIGHT TO THE RESCUE!::::"<<endl;
    cout<<"\t\t\t\t\t"<<type<<endl;
    cout<<"\t\t\t\t\t"<<build<<endl<<endl<<endl<<endl;

    cout<<"PRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;
    cout<<"IN THE MID-1100'S, A PRINCESS FROM A ROYAL FAMILY IN EUROPE\nWAS CAPTURED BY AN EVIL DRAGON!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;
    cout<<"THE PRINCESSE'S FATHER, THE ROYAL KING, DESPARATELY WANTED HER BACK.\nHE SENT HIS BEST AND BRAVEST SOLDIER TO RESCUE HER FROM THE DRAGONS DUNGEON.\n"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"THE ROYAL KING SENT HIS ONE AND ONLY BLACK KNIGHT TO RESCUE HIS DAUGHTER.\nUNFORTUNATELY THE GREAT WARRIOR DID NOT KNOW THAT THE EVIL DRAGON\nHAD ALREADY SENT HIS EVIL MINIONS TO STOP THE RESCUE."<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"YOU, ARE THE BLACK KNIGHT,\nAND THIS IS YOUR JOURNEY.\nGOOD LUCK!!!!!!!!!!!!!!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    Display_Space();
}
void outro()    //THE OUTRO TO THE VIDEO GAME: PERFECT WIN
{
   string value;
   Display_Space();
   cout<<"THE BLACK KNIGHT GAVE A MIGHTY SWING AND THE HEAD OF THE DRAGON WAS LOPPED OFF!\nWITH THE DRAGON DEFEATED, ALL WAS WELL."<<endl;
   cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"THE PRINCESS WAS SAFE BACK IN HER CASTLE WITH THE KING.\nTHE BLACK KNIGHT WAS COMMENDED FOR HIS HEROISM\nAND WAS GIVEN THE TITLE OF PROTECTOR OF THE LAND\n"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    Display_Space();
}
void outro_2()     //THE SECOND OUTRO: SHORTSWORD WIN CONDITION
{
    string value;
    Display_Space();
    cout<<"THE BLACK KNIGHT GAVE A MIGHTY SWING BUT SINCE THE SWORD WAS SO SHORT\nHE MISED THE DRAGON'S HEAD AND WAS KILLED."<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    Display_Space();
}

void outro_3()      //THE THIRD OUTRO: HALBERD WIN CONDITION
{
    string value;
    Display_Space();
    cout<<"THE BLACK KNIGHT GAVE A MIGHTY SWING AND LOPPED OFF THE HEAD OF THE DRAGON!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"THE PRINCESS LOOKED INTO THE WARRIORS EYES AND STATED\n\"UMM, LIKE, I ONLY DATE THE GREATEST WARRIORS,\nTHAT, UMM, DON'T USE OVERPOWERED WEAPONS\nAND LIKE, OMG, ARE YOU SERIOUS, LIKE NO WAY!\nI WOULD NEVER DATE SOMEONE LIKE YOU!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"WITHOUT A WORD, THE BLACK KNIGHT SEVERED HER HEAD!\nTHE BLACK KNIGHT REPORTED BACK TO THE KING\nTHAT THE DRAGON KILLED HIS DAUGHTER\nTHE END!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    Display_Space();
}

void outro_4()     //THE FOURTH OUTRO: LOSE CONDITION
{
    string value;
    Display_Space();
    cout<<"MOM: LARRY STOP PLAYING WITH YOUR FRIENDS AND COME OUT OF THE BASEMENT!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"LARRY: BUT MOM!!! IM LARPING WITH MY FRIEND FROM SWEDEN ON SKYPE!!!!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"MOM: LARRY! YOU ARE 28 YEARS OLD!\nMOM: GET OUT OF THE BASEMENT!\nMOM: FIND A JOB\nMOM: AND GET!\nMOM: OUT!\nMOM: OF!\nMOM: MY!\nMOM: HOUSE!"<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    cout<<"LARRY: OH COME ON!!!!\nLARRY: SORRY DUDE I GOT TO GO...."<<endl;
    cout<<"\nPRESS ANY KEY TO CONTINUE:"<<endl;
    cin>>value;
    cout<<endl;

    Display_Space();
}

