#ifndef RACER_H
#define RACER_H

#include <iostream>
#include <string>
#include <vector> //for dynamic arrays
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

    int generateRandomSteps(int min_speed, int max_speed) 
    {
    return rand() % (max_speed - min_speed + 1) + min_speed;
    }

public:
    Racer(string n, string e, char c, int min_sp, int max_sp) 
    : name(n), email(e), character(c), position(0), min_speed(min_sp), max_speed(max_sp), wins(0), boostAmount(0), gunAmount(0), swapAmount(0) {}
    //constructor initializing the racer's name, email, character, position, min_speed, max_speed, and wins
    
    string getName() const{
        return name;
    }

    string getEmail() const{ 
        return email; 
    }

    int getPosition() const{
        return position;
    }

    void incrementWins() {
        wins++;
    }

    int getWins() const{
        return wins;
    }

    char getCharacter() const{
        return character;
    }

    void incrementBoots() {
        boostAmount++;
    }

    void decrementBoots() {
        boostAmount--;
    }

    int getBoostAmount() const{
        return boostAmount;
    }

    void incrementGun() {
        gunAmount++;
    }

    void decrementGun() {
        gunAmount--;
    }

    int getGunAmount() const{
        return gunAmount;
    }

    void incrementSwap() {
        swapAmount++;
    }

    void decrementSwap() {
        swapAmount--;
    }

    int getSwapAmount() const{
        return swapAmount;
    }

    void move() 
    {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps;
        cout << name << " moved " << steps << " steps" << endl; //move the racer by a random step between min_speed and max_speed
    }

    void reset_position()// Function to reset racer's position to 0
    {
        position = 0;
    }

    bool apply_bridge(const vector<Bridge>& bridges) 
    {
        for (const auto& bridge : bridges) //loop through each bridge
        {
            if (position == bridge.getStart()) {
                position = bridge.getEnd();
                cout << name << " used a bridge!" << endl;
                return true;
            }
        }
        return false;
    }

    void useBoost() {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps + 2;
        cout << name << " used boost and moved " << steps + 2 << " steps" << endl;
    }
    
    void usegun() {
        int steps = generateRandomSteps(min_speed, max_speed);
        position += steps - 2;
        cout << name << "uses gun on designated racers" << steps - 2 << " steps" << endl;
    }
   
    void useswap(int& position1, int& position2) 
    {
        swap(position1, position2);
        cout << "Racers swapped positions" << endl;
    }

};

#endif // RACER_H
