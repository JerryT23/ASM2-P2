#ifndef RACE_H
#define RACE_H

#include <iostream>
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
    bonusObject bonus_object;
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

    void playerMove(Racer& racer) {
        char character = racer.getCharacter();
        if (character == 'X' || character == 'x') {
            racer.move();
        } else if (character == 'Y' || character == 'y') {
            racer.move();
        } else if (character == 'Z' || character == 'z') {
            racer.move();
        }
    }

    void nonPlayerMove(Racer& racer) {
        char character = racer.getCharacter();
        if (character != 'X' && character != 'x') {
            racer.move();
        } else if (character != 'Y' && character != 'y') {
            racer.move();
        } else if (character != 'Z' && character != 'z') {
            racer.move();
        }
    }

    void ctrlmenu()
    {
        while (true)
        {
            cout << "\n1. Move\n2. Use Item\n3. Get Item\n";
                cout << "Choose an action: ";
                cin >> optionc;

                switch (optionc) {
                    case 1:
                        // Assuming you have a way to select a specific racer here
                        // For example, let's select the first racer for simplicity
                        playerMove(racers[0]);
                        break;
                    case 2:
                        bonus_object.useItem(std::string(1, racers[0].getCharacter()), racers);
                        break;
                    case 3:
                        if (!getItem()) {
                            return; // Return to the main game loop
                        }
                        break;
                    default:
                        cout << "Invalid option. Try again." << endl;
                        continue;
                }
                
                for (auto& racer : racers) {
                    nonPlayerMove(racer);
                }
        }
    }

    void start() {
        cout << "Round 1" << "..." << endl;
        track.display_track(racers, bridges);

        for (int lap = 1; lap <= laps; ++lap) {
            while (true) {
                round++;
                cout << "Round " << round << "..." << endl;
                for (auto& racer : racers) {
                    racer.apply_bridge(bridges);
                }

                ctrlmenu();

                track.display_track(racers, bridges);

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
