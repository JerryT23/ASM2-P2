#ifndef RACER_H
#define RACER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "c_bridge.h"

using namespace std;

class Racer {
    string name;
    string email;
    char character;
    int min_speed;
    int max_speed;
    int position;
    int wins;
    int boostAmount;
    int gunAmount;
    int swapAmount;

    int generateRandomSteps(int min_speed, int max_speed) {
        return rand() % (max_speed - min_speed + 1) + min_speed;
    }

public:
    Racer() = default;  // Default constructor

    Racer(string n, string e, char c, int min_sp, int max_sp)
        : name(n), email(e), character(c), min_speed(min_sp), max_speed(max_sp), position(0), wins(0), boostAmount(0), gunAmount(0), swapAmount(0) {}

    void resetPosition() {
        position = 0;
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    int getPosition() const {
        return position;
    }

    void incrementWins() {
        wins++;
    }

    int getWins() const {
        return wins;
    }

    void setWins(int win) {
        wins = win;
    }

    char getCharacter() const {
        return character;
    }

    int getBoostAmount() const {
        return boostAmount;
    }

    int getGunAmount() const {
        return gunAmount;
    }

    int getSwapAmount() const {
        return swapAmount;
    }

    void setPosition(int pos) {
        position = pos;
    }

    void setBoostAmount(int amount) {
        boostAmount = amount;
    }

    void setGunAmount(int amount) {
        gunAmount = amount;
    }

    void setSwapAmount(int amount) {
        swapAmount = amount;
    }

    void useBoost() {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps + 2;
        cout << name << " used a boost and moved " << steps + 2 << " steps" << endl;
    }

    void useGun() {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps - 2;
        cout << name << " used a gun and moved " << steps - 2 << " steps" << endl;
    }

    void useSwap(int& position1, int& position2) {
        int temp = position1;
        position1 = position2;
        position2 = temp;
        cout << "Racers swapped positions!" << endl;
    }

    void move() {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps;
        cout << name << " moved " << steps << " steps" << endl;
    }

    bool apply_bridge(const vector<Bridge>& bridges) {
        for (const auto& bridge : bridges) {
            if (position == bridge.getStart()) {
                position = bridge.getEnd();
                cout << name << " used a bridge!" << endl;
                return true;
            }
        }
        return false;
    }
};

#endif // RACER_H
