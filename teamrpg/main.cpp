//File Name: main.cpp
//Purpose: Main source file for the rpg.
//Author: Chris Estes
//Date: 5-20-2016
//Compiler: Code::Blocks 16.01

/*Design Notes:
Basic idea is that the player is a linked list as are the enemies. They're teams.
Unfortunately I ran into a lot of bugs when trying to implement multiple players,
so I scaled it back to having a single player, however the enemy is a team and that's functioning.
Game is over when the player dies.
Features:
- The player can damage the enemy, the enemies can damage the player.
- The battle loops.
- When the battle ends the player enters a recovery phase where they have a change of getting health back
- When in battle you can attempt to flee (though the chances of success are quite low)
- Enemies team is populated with a random size, stats are random (aside from some base values)
- Player's stats are randomly generated
- Game can be exited within battle
- Keeps track of how many turns the player survives for
*/

#include"node.h"
#include"linkedList.h"
#include<iostream>
#include<ctime>
using namespace std;
//used to check if node is "dead"
bool isDead(LinkedList target, int id){
    int currentHP;
    currentHP = target.findHP(id);
    if(currentHP > 0){
        return false;
    }
    else if(currentHP <= 0){
        return true;
    }
    return true;
}
//Populate player team
void populatePlayerTeam(LinkedList& p){
int randomGenHP = 0;
int randomGenAttack = 0;
string name;
srand(time(NULL));
cout << "Enter the name of the hero: " << endl;
cout << ">";
cin >> name;
//Generate random health and attack
randomGenHP = 20;
randomGenHP += (rand() % 10);
randomGenAttack = 5;
randomGenAttack += (rand() % 5);
p.insert(randomGenHP, randomGenAttack, name, 0);
cout << endl;
p.showList();
}
//Populate enemy team
void populateEnemyTeam(LinkedList& e){
int randomNumEnemies = 0;
int randomGenHP = 0;
int randomGenAttack = 0;
randomNumEnemies = 2;
srand(time(NULL));
randomNumEnemies += (rand() % 3);
for (int i = 0; i<randomNumEnemies; i++){
    //Generate random health and attack
    randomGenHP = 4;
    randomGenHP += (rand() % 4);
    randomGenAttack = 3;
    randomGenAttack += (rand() % 2);
    e.insert(randomGenHP, randomGenAttack, "Goblin", i);
}
cout << endl;
}
//Battle loop
bool battle(LinkedList& p, LinkedList& e, int& turns, int id, bool& exit){
int playerChoice;
int select = 0;
int escape = 0;
int targetPlayer = 0;
int damage = 0;
bool inBattle = true;
//Pre-loop info
cout << "You enter combat." << endl;
cout << e.getnumNodes() << " enemies approach." << endl;
cout << "Enemies: " << endl;
e.showList();
cout << endl << endl;
srand(time(NULL));
//the battle loop
while(inBattle == true){
turns++;
//Exit battle if no enemy nodes are left
if(e.getnumNodes()== 0){
        return true;
}
//Get user's action choice
cout << "Current turn: " << turns << endl;
cout << "Would you like to: " << endl;
cout << "[1] Attack, [2] Flee, [3] Exit Game" << endl;
cout << ">";
cin >> playerChoice;
cout << endl;
//Attacking
if(playerChoice == 1){
    cout << "You attack!" << endl;
    //get damage from target player id
    damage = p.findAttack(id);
    damage -= (rand()%3);
    //randomly pick enemy (using id)
    srand(time(NULL));
    select = (e.getnumNodes()-1);
    //apply damage
    e.damage(select,damage);
    cout << "Goblin #" << (select + 1) << " takes " << damage << " damage!" << endl;
    //check if the goblin died
    if(isDead(e, select) == true){
        cout << "Goblin #" << (select + 1) << " has perished." << endl << endl;
        e.eraseOne(select);
        if(select == 0){
            return true;
			}
    }
    //Show remaining enemies
    cout << "Enemies: " << endl;
    e.showList();
}
//Fleeing
else if(playerChoice == 2){
        cout << "You attempt to flee!" << endl;
        //Generate value to see if fleeing succeeds
        escape += (rand() % 10);
        if(escape <= 4){
            cout << "You escape!" << endl << endl;
            return true;
        }
        else{
            cout << "You failed to flee." << endl << endl;
            }
}
//Exit choice
else if(playerChoice == 3){
    char ans;
    cout << "Are you sure you want to quit?" << endl;
    cout << "y/n" << endl;
    cout << ">";
    cin >> ans;
    if(ans == 'y'){
        exit = true;
        return true;
    }
}
//Enemy attack
//select a random enemy id
select = (rand() % e.getnumNodes());
targetPlayer = 0;
//generate damage
damage = e.findAttack(select);
damage -= (rand()%3);
cout << "Goblin #" << (select+1) << " deals " << damage << " damage to the hero!" << endl << endl;
//update player health with damage
p.damage(targetPlayer, damage);
//check if the player dies
if(isDead(p, targetPlayer) == true){
    cout << "The hero has perished!" << endl;
    return false;
}
p.showList();
}
return true;
}
//after a battle occurs you have a chance to recover some health
void recover(LinkedList& p, int& t){
    int encounterChance = 0;
    string ans;
    bool recovering = true;
    srand(time(NULL));
    cout << "You take a moment to rest." << endl;
    while(recovering == true){
        t++;
        //uses random number generation to determine if you get to heal or go back into a fight
        encounterChance = (rand()%100);
        if(encounterChance >= 60){
            cout << "Oh no! More enemies are coming..." << endl;
            cout << "(Enter something to continue...)" << endl;
            cin >> ans;
            recovering = false;
        }
        else if(encounterChance < 60){
            cout << "Current Turn: " << t << endl;
            p.recoverHP();
            p.showList();
            cout << "(Enter something to continue...)" << endl;
            cin >> ans;
        }
    }
    return;
}
//main
int main(){
LinkedList player;
LinkedList e1;
int numTurns = 0;
int currentPlayerID = 0;
string ans;
bool success;
bool gameLoop = false;
bool exit = false;
cout << "Welcome to the RPG Prototype!" << endl;
//populate player team
populatePlayerTeam(player);
//populate enemy team
populateEnemyTeam(e1);
gameLoop = true;
//main game loop
while(gameLoop == true){
    //run first battle
    success = battle(player, e1, numTurns, currentPlayerID, exit);
    //exit check
    if(exit == true){
        cout << "You played for: " << numTurns << " turns." << endl;
        cout << "Thank you for playing!" << endl;
        gameLoop = false;
    }
    //if the player survives the battle
    else if(success == true){
    cout << "You survived the battle!" << endl;
    cout << "(Enter something to continue...)" << endl;
    cin >> ans;
    cout << endl;
    //recover phrase
    recover(player, numTurns);
    //clear enemy linked list
    e1.delList();
    //re-populate it
    populateEnemyTeam(e1);
    }
    //if the player dies
    else if (success == false){
        cout << "You survived: " << numTurns << " turns." << endl;
        cout << "Thank you for playing!" << endl;
        gameLoop = false;
    }
}
return 0;
}
