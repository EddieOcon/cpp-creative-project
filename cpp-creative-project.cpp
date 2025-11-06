/*
Author: Eddie O'Con
Assignment: cpp-creative-project: Dungeon and Dragons
Description: Have fun and stay alive.  Raited R for maturity
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Functions
void gameIntro();
void fightZombie();
void searchWeapon(string weapons[], int size);
void fightDragon(string weapon);
void saveResult(string result);

// fight functions
void fight(string enemy);
void fight(string enemy, string weapon);

int main() {
    srand(time(0));
    string weapons[3] = {"sword", "knife", "axe"};
    string foundWeapon = weapons[0];

    gameIntro();
    fightZombie();
    searchWeapon(weapons, 3);
    foundWeapon = weapons[2]; 
    fightDragon(foundWeapon);

    return 0;
}

void gameIntro() {
    cout << "Welcome to Dragon Dungeon!\n";
    cout << "You will face zombies and a horific dragon that might eat you.\n";
    cout << "Make smart choices to survive.\n\n";
}

void fightZombie() {
    char choice;
    cout << "You enter the first room... zombies appear!\n";
    cout << "Do you (F)ight or (R)un? ";
    cin >> choice;

    if (toupper(choice) == 'F')
        fight("zombie");
    else
        cout << "You run away and hide in the next room.\n";
}

void searchWeapon(string weapons[], int size) {
    int spot;
    cout << "\nYou find three spots to dig for a weapon (1-3): ";
    cin >> spot;

    if (spot == 3)
        cout << "You found the " << weapons[2] << "!\n";
    else
        cout << "Nothing here... you move on empty-handed.\n";
}

void fightDragon(string weapon) {
    char choice;
    cout << "\nA DRAGON appears!\n";
    cout << "Do you (F)ight or (R)un? ";
    cin >> choice;

    if (toupper(choice) == 'F')
        fight("dragon", weapon);
    else
        cout << "You escaped... barely!\n";
}

void fight(string enemy) {
    cout << "You swing your weapon at the " << enemy << "!\n";
    cout << "You win the battle!\n";
    saveResult("Won against zombie");
}

void fight(string enemy, string weapon) {
    string area;
    cout << "You attack the " << enemy << " with your " << weapon << "!\n";
    cout << "Where do you strike? (head/body/neck): ";
    cin >> area;

    if (area == "neck") {
        cout << "Critical hit! You defeated the dragon!\n";
        saveResult("Victory! Defeated dragon");
    } else {
        cout << "The dragon strikes back... you lose.\n";
        saveResult("Defeated by dragon");
    }
}

void saveResult(string result) {
    ofstream file("results.txt");
    if (file.is_open()) {
        file << result;
        file.close();
    }
}
