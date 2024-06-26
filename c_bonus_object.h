#ifndef BONUS_OBJECT_H
#define BONUS_OBJECT_H

#include "c_racer.h"
#include "c_race.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class BonusObject {
private:
    Racer race;
    void applySwap(const string& character, vector<Racer>& racers) {
        int rng = rand() % 101;
        for (auto& racer : racers) {
            if (tolower(racer.getCharacter()) == tolower(character[0])) {
                for (auto& targetRacer : racers) {
                    if (&racer != &targetRacer) {
                        if (rng <= 50) {
                            int pos1 = racer.getPosition();
                            int pos2 = targetRacer.getPosition();
                            racer.useSwap(pos1, pos2);
                            cout << "\n" << racer.getCharacter() << " has swapped with " << targetRacer.getCharacter();
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
public:
    BonusObject() = default;  // Default constructor

    void useItem(const string& character, vector<Racer>& racers) {
        string item;
        cout << "\nEnter item (boost/gun/swap): ";
        
        for (auto& racer : racers) {
            if (tolower(racer.getCharacter()) == tolower(character[0])) {
                cout << "\nBoost" << setw(10) << racer.getBoostAmount();
                cout << "\nGun" << setw(10) << racer.getGunAmount();
                cout << "\nSwap" << setw(10) << racer.getSwapAmount() << endl;
                break;
            }
        }
        
        cin >> item;

        for (auto& racer : racers) {
            if (tolower(racer.getCharacter()) == tolower(character[0])) {
                if (item == "boost" && racer.getBoostAmount() > 0) {
                    racer.setBoostAmount(racer.getBoostAmount() - 1);
                    racer.useBoost();
                } else if (item == "gun" && racer.getGunAmount() > 0) {
                    racer.setGunAmount(racer.getGunAmount() - 1);
                    string attack;
                    cout << "\nWho do you want to use it on? (X, Y, Z): ";
                    cin >> attack;
                    
                    for (auto& targetRacer : racers) {
                        if (tolower(targetRacer.getCharacter()) == tolower(attack[0])) {
                            targetRacer.useGun();
                            break;
                        }
                    }
                } else if (item == "swap" && racer.getSwapAmount() > 0) {
                    racer.setSwapAmount(racer.getSwapAmount() - 1);
                    applySwap(character, racers);
                } else {
                    cout << "Invalid item or not enough items. Try again." << endl;
                }
                break;
            }
        }
    }

    void getItem(const string& character, vector<Racer>& racers) {
        cout << "\nWaste one turn to get items. Confirm? (yes/no): ";
        string confirm;
        cin >> confirm;

        if (confirm == "yes") {
            // Randomly assign items to each racer
            for (auto& racer : racers) {
                if (tolower(racer.getCharacter()) == tolower(character[0])) {
                int rng = rand() % 3 + 1;
                    switch (rng) {
                        case 1:
                            racer.setBoostAmount(racer.getBoostAmount() + 1);
                            cout << "\n" << racer.getName() << " got a booster!" << endl;
                            break;
                        case 2:
                            racer.setGunAmount(racer.getGunAmount() + 1);
                            cout << "\n" << racer.getName() << " got a gun!" << endl;
                            break;
                        case 3:
                            racer.setSwapAmount(racer.getSwapAmount() + 1);
                            cout << "\n" << racer.getName() << " got a swap!" << endl;
                            break;
                    }
                }
            }
        } else if (confirm == "no") {
            cout << "Returning to menu.\n";
        } else {
            cout << "Invalid input. Returning to menu.\n";
        }
    }
};

#endif // BONUS_OBJECT_H
