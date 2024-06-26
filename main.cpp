#include <iostream>
#include <limits> //for numeric_limits
#include <string>
#include "c_bridge.h"
#include "c_racer.h"
#include "c_race.h"
#include "c_track.h"
#include "c_bonus_object.h"

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "--------------------" <<endl;
    cout << "RACE GAME BY GROUP 4" <<endl;
    cout << "--------------------" <<endl;
    cout << "1. Start game" <<endl;
    cout << "2. Quit" <<endl;

    cout << "Select option: ";
    int option;
    cin >> option;

    if (option == 2) {
        return 0;
    }

    string character;
    cout << "Choose your racer (X/Y/Z): ";
    cin >> character;

    int race_laps;
    cout << "Enter number of laps for the race: ";
    cin >> race_laps;

    int track_selection;
    cout << "Select a track (1, 2, or 3): ";
    cin >> track_selection;

    Race race(race_laps, track_selection);// Create a Race object with the specified number of rounds and track choice

    int num_bridges;
    while (true)// Loop to get valid number of bridges
    {
        cout << "Enter the number of bridges (3-5): ";
        cin >> num_bridges;
        if (cin.fail() || num_bridges < 3 || num_bridges > 5)
        {
            cin.clear(); // Clear the error flag set by invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input. Please enter a number between 3 and 5." << endl;
        }
        else
        {
            break; //Valid input, exit the loop
        }
    }

    for (int i = 0; i < num_bridges; ++i) {
        int start, end;
        while (true) { // Loop to ensure start and end locations are different
            cout << "Enter start location for bridge " << i + 1 << ": ";
            cin >> start;
            cout << "Enter end location for bridge " << i + 1 << ": ";
            cin >> end;

            if (start != end) {
                race.add_bridge(Bridge(start, end));// Add the bridge to the race
                break; // Valid input, exit the loop
            } else {
                cout << "Start and end locations cannot be the same. Please enter different values." << endl;
            }
        }
    }

    // Add racers to the race
    race.add_racer(Racer("X Wing", "abc@gamil.com", 'X', 2, 4));
    race.add_racer(Racer("Tie Fighter", "def@gamil.com", 'T', 1, 5));
    race.add_racer(Racer("Soulless One", "ghi@gamil.com", 'S', 3, 6));

    race.start(character);// Start the race

    return 0;
}
