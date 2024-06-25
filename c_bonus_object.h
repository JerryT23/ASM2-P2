#ifndef BONUS_OBJECT_H
#define BONUS_OBJECT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "c_race.h"
#include "c_racer.h"
#include "c_bridge.h"

class bonusObject
{
private:
    Race race;
    vector<Racer> racers; //store racers participating in the race
    vector<Bridge> bridges; //store bridges in the race
    int boostAmount;
    int gunAmount;
    int swapAmount;

public:
    void useItem(const string& character, vector<Racer> racers)
    {   
        for (auto& racer : racers)
        {
            string item;
            boostAmount = racer.getBoostAmount();
            gunAmount = racer.getGunAmount();
            swapAmount = racer.getSwapAmount();
            cout << "\nEnter item (boost/gun/swap): ";
            cout << "\nBoost" << setw(10) << boostAmount;
            cout << "\nGun" << setw(10) << gunAmount;
            cout << "\nswap" << setw(10) << swapAmount << endl;
            cin >> item;

            if (item == "boost" && boostAmount > 0) {
                racer.decrementBoots();
                if (character == "X" || character == "x") {
                    racers[1].useBoost();
                } else if (character == "Y" || character == "y") {
                    racers[2].useBoost();
                } else if (character == "Z" || character == "z") {
                    racers[3].useBoost();
                }
            } else if (item == "gun" && gunAmount > 0) {
                racer.decrementGun();
                string attack;
                cout << "\nWho do you want to use it on?(X,Y,Z)";
                if (attack == "X" || attack == "x"){
                    racers[1].usegun();
                }
                else if (attack == "y" || attack == "Y"){
                    racers[2].usegun();
                }
                else if (attack == "z" || attack == "Z"){
                    racers[3].usegun();
                }
                else{
                    cout << "\ninvalid option";
                }

            } else if (item == "swap" && swapAmount > 0) {
                racer.decrementSwap();
                int pos1 = racers[1].getPosition();
                int pos2 = racers[2].getPosition();
                int pos3 = racers[3].getPosition();
                int rng = rand() % 101;
                if (character == "x" || character == "X"){
                    if (rng <= 50){
                        racers[1].useswap(pos1, pos2);
                        cout << "\nxwing have swap with tiefighter";
                    } else if (rng > 50){
                        racers[1].useswap(pos1, pos3);
                        cout << "\nxwing have swap with soullessone";
                    }
                }
                else if (character == "y" || character == "Y"){
                    if (rng <= 50){
                        racers[2].useswap(pos2, pos1);
                        cout << "\ntiefighter have swap with xwing";
                    } else if (rng > 50){
                        racers[2].useswap(pos2, pos3);
                        cout << "\ntiefighter have swap with soullesone";
                    }
                }
                else if (character == "z" || character == "Z"){
                    if (rng <= 50){
                        racers[3].useswap(pos3, pos2);
                        cout << "\nsoullesone have swap with tiefighter";
                    } else if (rng > 50){
                        racers[3].useswap(pos3, pos1);
                        cout << "\nsoullesone have swap with xwing";
                    }
                }
            } else {
                cout << "Invalid item or not enough items. Try again." << endl;
            }
        }
    }

    bool getItem(vector<Racer>& racers) {
        cout << "\nWaste one turn to get items. Confirm? (yes/no): ";
        string confirm;
        cin >> confirm;

        if (confirm == "yes") {
            // Randomly assign items to each racer
            for (auto& racer : racers) {
                int rng = rand() % 3 + 1;
                switch (rng) {
                    case 1:
                        racer.incrementBoots();
                        cout << "\n" << racer.getName() << " got a booster!";
                        break;
                    case 2:
                        racer.incrementGun();
                        cout << "\n" << racer.getName() << " got a gun!";
                        break;
                    case 3:
                        racer.incrementSwap();
                        cout << "\n" << racer.getName() << " got a swap!";
                        break;
                }
            }
            return true; // Items obtained
        } else if (confirm == "no") {
            return false; // Items not obtained
        } else {
            cout << "Invalid input. Returning to menu.\n";
            return false; // Items not obtained
        }
    }

};


#endif