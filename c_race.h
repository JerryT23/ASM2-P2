#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <string>
#include "c_racer.h"
#include "c_bridge.h"
#include "c_track.h"
#include "c_bonus_object.h"

using namespace std;

class Race {
private:
    vector<Racer> racers;
    vector<Bridge> bridges;
    Track track;
    BonusObject bonus_object;
    int round = 1;
    int laps;
    int optionc;
    int selected_track;

public:
    Race(int r, int t) : laps(r), selected_track(t), track(t) {}

    void add_racer(const Racer& racer) {
        racers.push_back(racer);
    }

    void add_bridge(const Bridge& bridge) {
        bridges.push_back(bridge);
    }

    void playerMove(const string& character) {
        for (auto& racer : racers) {
            if (tolower(racer.getCharacter()) == tolower(character[0])) {
                racer.move();
                return;
            }
        }
    }

    void nonPlayerMove(const string& character) {
        for (auto& racer : racers) {
            if (tolower(racer.getCharacter()) != tolower(character[0])) {
                racer.move();
            }
        }
    }

    void useItem(const string& character) {
        bonus_object.useItem(character, racers);
    }

    void getItem(const string& character) {
        bonus_object.getItem(character, racers);
    }

    void ctrlmenu(const string& character)
    {
        while (true)
        {
            cout << "\n1. Move\n2. Use Item\n3. Get Item\n";
            cout << "Choose an action: ";
            cin >> optionc;
            // Validate input
            while (cin.fail() || optionc < 1 || optionc > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 1, 2, or 3: ";
                cin >> optionc;
            }
    
            switch (optionc) {
                case 1:
                    playerMove(character);
                    break;
                case 2:
                    bonus_object.useItem(character, racers);
                    break;
                case 3:
                    bonus_object.getItem(character, racers);
                    break;
                default:
                    cout << "Invalid option. Try again." << endl;
                    continue; // Restart the loop for valid input
            }
    
            // Non-selected racers move
            nonPlayerMove(character);
            track.display_track(racers, bridges);
        }
    }

    void start(const string& character) {
        cout << "Round 1" << "..." << endl;
        track.display_track(racers, bridges);

        for (int lap = 1; lap <= laps; ++lap) {
            while (true) {
                round++;
                cout << "Round " << round << "..." << endl;
                for (auto& racer : racers) {
                    racer.apply_bridge(bridges);
                }

                ctrlmenu(character);

                bool any_winner = false;
                for (auto& racer : racers) {
                    if (racer.getPosition() >= track.get_track_length()) {
                        cout << racer.getName() << " wins the race for this round!\n" << endl;
                        racer.incrementWins();
                        any_winner = true;
                    }
                }

                if (any_winner) break;
            }
        }
        cout << "Game Over" << endl;

        // Display summary table
        cout << "Player Summary:" << endl;
        cout << "+----------------+-----------------------+--------+-----------+-----------+" << endl;
        cout << "| Name           | Email                 | Racer  | Wins      | Losses    |" << endl;
        cout << "+----------------+-----------------------+--------+-----------+-----------+" << endl;

        for (const auto& racer : racers) {
            int losses = laps - racer.getWins();
            cout << "| " << setw(14) << racer.getName()
                 << " | " << setw(21) << racer.getEmail()
                 << " | " << setw(6) << racer.getCharacter()
                 << " | " << setw(9) << racer.getWins()
                 << " | " << setw(9) << losses
                 << " |" << endl;
        }
        cout << "+----------------+-----------------------+--------+-----------+-----------+" << endl;
    }
};

#endif
