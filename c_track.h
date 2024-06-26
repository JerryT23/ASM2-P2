#ifndef TRACK_H
#define TRACK_H
#include <iostream>
#include <vector> //for dynamic arrays
#include "c_racer.h"
#include "c_bridge.h"
using namespace std;

class Track {
private:
    int width;
    int height;
    int track_length;
    int selected_track;
    vector<Racer> racers; //store racers participating in the race
    vector<Bridge> bridges; //store bridges in the race

public:
    Track(int selection) : selected_track(selection) 
    {
        set_track_size(); //set the size of the track based on the selection
    }

    void set_track_size()
    {
        switch (selected_track) {
            case 1:
                width = 45;
                height = 17;
                track_length = 49;
                break;
            case 2:
                width = 33;
                height = 25;
                track_length = 42;
                break;
            case 3:
                width = 77;
                height = 19;
                track_length = 74;
                break;
            default:
                cout << "Invalid track selection!" << endl;
                width = 0;
                height = 0;
                track_length = 0;
                break;
        }
    }

    int get_track_length() 
    {
        return track_length;
    }

    void display_track_1(vector<Racer> racers, vector<Bridge> bridges)// Function to display track 1
    {
        char track[17][45];
        //Initialize all to spaces
        for (int i = 0; i < height; i++) // Loop through each row of the track
            for (int j = 0; j < width; j++) // Loop through each column in the current row
                track[i][j] = ' ';
        //Top track
        for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
        {
            for (int j = 4; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 1] = '+';
        }
        for (int j = 4; j < width; j = j + 4) // Loop through each 3 column in the current row
            track[1][j] = '|';
        //Left and right tracks - vertical lines top part
        for (int i = 3; i < height - 8; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][4] = '|';
            track[i][8] = '|';
            track[i][width - 5] = '|';
            track[i][width - 1] = '|';
            //track design
            track[5][width - 17] = '|';
            track[5][width - 13] = '|';
            track[5][width - 9] = '|';
            track[7][width - 17] = '|';
            track[7][width - 13] = '|';
            track[7][width - 5] = ' ';
            track[7][width - 1] = ' ';
            track[5][8] = '|';
            track[5][12] = '|';
            track[5][16] = '|';
            track[5][20] = '|';
            track[5][24] = '|';
            track[7][12] = '|';
            track[7][16] = '|';
            track[7][20] = '|';
            track[7][24] = '|';
        }
        //Left and right tracks - vertical lines bottom part
        for (int i = 9; i < height - 3; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][0] = '|';
            track[i][4] = '|';
            track[i][width - 5] = '|';
            track[i][width - 9] = '|';
            //track design
            track[9][0] = ' ';
            track[9][4] = ' ';
            track[9][20] = '|';
            track[9][24] = '|';
            track[9][28] = '|';
            track[9][32] = '|';
            track[11][8] = '|';
            track[11][12] = '|';
            track[11][16] = '|';
            track[11][20] = '|';
            track[11][24] = '|';
        }
        //Left track - horizontal lines top part
        for (int i = 4; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][4] = '+';
            track[i][5] = '-';
            track[i][6] = '-';
            track[i][7] = '-';
            track[i][8] = '+';
            //track design
            track[i][9] = '-';
            track[i][10] = '-';
            track[i][11] = '-';
            track[i][12] = '+';
            track[i][13] = '-';
            track[i][14] = '-';
            track[i][15] = '-';
            track[i][16] = '+';
            track[i][17] = '-';
            track[i][18] = '-';
            track[i][19] = '-';
            track[i][20] = '+';
            track[i][21] = '-';
            track[i][22] = '-';
            track[i][23] = '-';
            track[i][24] = '+';
            track[i][25] = '-';
            track[i][26] = '-';
            track[i][27] = '-';
            track[i][28] = '+';
            track[i][29] = '-';
            track[i][30] = '-';
            track[i][31] = '-';
            track[i][32] = '+';
            track[i][33] = '-';
            track[i][34] = '-';
            track[i][35] = '-';
            track[i][36] = '+';
            track[i][37] = '-';
            track[i][38] = '-';
            track[i][39] = '-';
            track[4][9] = ' ';
            track[4][10] = ' ';
            track[4][11] = ' ';
            track[4][25] = ' ';
            track[4][26] = ' ';
            track[4][27] = ' ';
            track[6][25] = ' ';
            track[6][26] = ' ';
            track[6][27] = ' ';
            track[8][25] = ' ';
            track[8][26] = ' ';
            track[8][27] = ' ';
            track[8][17] = ' ';
            track[8][18] = ' ';
            track[8][19] = ' ';
        }
        //Left track - horizontal lines bottom part
        for (int i = 10; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][0] = '+';
            track[i][1] = '-';
            track[i][2] = '-';
            track[i][3] = '-';
            track[i][4] = '+';
            //track design
            track[i][5] = '-';
            track[i][6] = '-';
            track[i][7] = '-';
            track[i][8] = '+';
            track[i][9] = '-';
            track[i][10] = '-';
            track[i][11] = '-';
            track[i][12] = '+';
            track[i][13] = '-';
            track[i][14] = '-';
            track[i][15] = '-';
            track[i][16] = '+';
            track[i][17] = '-';
            track[i][18] = '-';
            track[i][19] = '-';
            track[i][20] = '+';
            track[i][21] = '-';
            track[i][22] = '-';
            track[i][23] = '-';
            track[i][24] = '+';
            track[10][28] = '+';
            track[10][29] = '-';
            track[10][30] = '-';
            track[10][31] = '-';
            track[10][32] = '+';
            track[10][33] = '-';
            track[10][34] = '-';
            track[10][35] = '-';
        }
        //Right track - horizontal lines top part
        for (int i = 4; i < height - 10; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][width - 5] = '+';
            track[i][width - 4] = '-';
            track[i][width - 3] = '-';
            track[i][width - 2] = '-';
            track[i][width - 1] = '+';
        }
        //Right track - horizontal lines bottom part
        for (int i = 8; i < height - 3; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][width - 9] = '+';
            track[i][width - 8] = '-';
            track[i][width - 7] = '-';
            track[i][width - 6] = '-';
            track[i][width - 5] = '+';
        }
        //Bottom track
        for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 0; j < width - 5; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 5] = '+';
        }
        for (int j = 0; j < width - 4; j = j + 4) // Loop through each 3 column of the track
            track[height - 2][j] = '|';

        // Highlight the bridges on the track
        for (int i = 0; i < bridges.size(); ++i) 
        {
            int strd = bridges[i].getStart();
            char end = bridges[i].getEnd();
            switch (strd)
            {
                case 0: track[height - 2][2] = '*'; break;
                case 1: track[height - 4][2] = '*'; break;
                case 2: track[height - 6][2] = '*'; break;
                case 3: track[height - 6][6] = '*'; break;
                case 4: track[height - 6][10] = '*'; break;
                case 5: track[height - 6][14] = '*'; break;
                case 6: track[height - 6][18] = '*'; break;
                case 7: track[height - 6][22] = '*'; break;
                case 8: track[height - 8][22] = '*'; break;
                case 9: track[height - 10][22] = '*'; break;
                case 10: track[height - 12][22] = '*'; break;
                case 11: track[height - 12][18] = '*'; break;
                case 12: track[height - 12][width - 31] = '*'; break;
                case 13: track[height - 10][width - 31] = '*'; break;
                case 14: track[height - 10][width - 35] = '*'; break;
                case 15: track[height - 10][width - 39] = '*'; break;
                case 16: track[height - 12][width - 39] = '*'; break;
                case 17: track[height - 14][width - 39] = '*'; break;
                case 18: track[1][width - 39] = '*'; break;
                case 19: track[1][width - 35] = '*'; break;
                case 20: track[1][width - 31] = '*'; break;
                case 21: track[1][width - 27] = '*'; break;
                case 22: track[1][width - 23] = '*'; break;
                case 23: track[1][width - 19] = '*'; break;
                case 24: track[1][width - 15] = '*'; break;
                case 25: track[1][width - 11] = '*'; break;
                case 26: track[1][width - 7] = '*'; break;
                case 27: track[1][width - 3] = '*'; break;
                case 28: track[height - 14][width - 3] = '*'; break;
                case 29: track[height - 12][width - 3] = '*'; break;
                case 30: track[height - 12][width - 7] = '*'; break;
                case 31: track[height - 12][width - 11] = '*'; break;
                case 32: track[height - 12][width - 15] = '*'; break;
                case 33: track[height - 10][width - 15] = '*'; break;
                case 34: track[height - 8][width - 15] = '*'; break;
                case 35: track[height - 8][width - 11] = '*'; break;
                case 36: track[height - 8][width - 7] = '*'; break;
                case 37: track[height - 6][width - 7] = '*'; break;
                case 38: track[height - 4][width - 7] = '*'; break;
                case 39: track[height - 2][width - 7] = '*'; break;
                case 40: track[height - 2][width - 11] = '*'; break;
                case 41: track[height - 2][width - 15] = '*'; break;
                case 42: track[height - 2][width - 19] = '*'; break;
                case 43: track[height - 2][width - 23] = '*'; break;
                case 44: track[height - 2][width - 27] = '*'; break;
                case 45: track[height - 2][width - 31] = '*'; break;
                case 46: track[height - 2][width - 35] = '*'; break;
                case 47: track[height - 2][width - 39] = '*'; break;
                case 48: track[height - 2][width - 43] = '*'; break;
            }

            switch (end) 
            {
                case 0: track[height - 2][2] = '#'; break;
                case 1: track[height - 4][2] = '#'; break;
                case 2: track[height - 6][2] = '#'; break;
                case 3: track[height - 6][6] = '#'; break;
                case 4: track[height - 6][10] = '#'; break;
                case 5: track[height - 6][14] = '#'; break;
                case 6: track[height - 6][18] = '#'; break;
                case 7: track[height - 6][22] = '#'; break;
                case 8: track[height - 8][22] = '#'; break;
                case 9: track[height - 10][22] = '#'; break;
                case 10: track[height - 12][22] = '#'; break;
                case 11: track[height - 12][18] = '#'; break;
                case 12: track[height - 12][width - 31] = '#'; break;
                case 13: track[height - 10][width - 31] = '#'; break;
                case 14: track[height - 10][width - 35] = '#'; break;
                case 15: track[height - 10][width - 39] = '#'; break;
                case 16: track[height - 12][width - 39] = '#'; break;
                case 17: track[height - 14][width - 39] = '#'; break;
                case 18: track[1][width - 39] = '#'; break;
                case 19: track[1][width - 35] = '#'; break;
                case 20: track[1][width - 31] = '#'; break;
                case 21: track[1][width - 27] = '#'; break;
                case 22: track[1][width - 23] = '#'; break;
                case 23: track[1][width - 19] = '#'; break;
                case 24: track[1][width - 15] = '#'; break;
                case 25: track[1][width - 11] = '#'; break;
                case 26: track[1][width - 7] = '#'; break;
                case 27: track[1][width - 3] = '#'; break;
                case 28: track[height - 14][width - 3] = '#'; break;
                case 29: track[height - 12][width - 3] = '#'; break;
                case 30: track[height - 12][width - 7] = '#'; break;
                case 31: track[height - 12][width - 11] = '#'; break;
                case 32: track[height - 12][width - 15] = '#'; break;
                case 33: track[height - 10][width - 15] = '#'; break;
                case 34: track[height - 8][width - 15] = '#'; break;
                case 35: track[height - 8][width - 11] = '#'; break;
                case 36: track[height - 8][width - 7] = '#'; break;
                case 37: track[height - 6][width - 7] = '#'; break;
                case 38: track[height - 4][width - 7] = '#'; break;
                case 39: track[height - 2][width - 7] = '#'; break;
                case 40: track[height - 2][width - 11] = '#'; break;
                case 41: track[height - 2][width - 15] = '#'; break;
                case 42: track[height - 2][width - 19] = '#'; break;
                case 43: track[height - 2][width - 23] = '#'; break;
                case 44: track[height - 2][width - 27] = '#'; break;
                case 45: track[height - 2][width - 31] = '#'; break;
                case 46: track[height - 2][width - 35] = '#'; break;
                case 47: track[height - 2][width - 39] = '#'; break;
                case 48: track[height - 2][width - 43] = '#'; break;
            }
        }

        // Assign racer symbols
        int base_column = 1; // Define the base starting column
        for (int i = 0; i < racers.size(); ++i) 
        {
            int pos = racers[i].getPosition();
            char symbol = racers[i].getCharacter();
            int start_col = base_column + i; // Adjust starting column based on racer index
            // Adjust position to avoid overlap for each racer
            switch (pos) 
            {
                case 0: track[height - 2][start_col] = symbol; break;
                case 1: track[height - 4][start_col] = symbol; break;
                case 2: track[height - 6][start_col] = symbol; break;
                case 3: track[height - 6][start_col + 4] = symbol; break;
                case 4: track[height - 6][start_col + 8] = symbol; break;
                case 5: track[height - 6][start_col + 12] = symbol; break;
                case 6: track[height - 6][start_col + 16] = symbol; break;
                case 7: track[height - 6][start_col + 20] = symbol; break;
                case 8: track[height - 8][start_col + 20] = symbol; break;
                case 9: track[height - 10][start_col + 20] = symbol; break;
                case 10: track[height - 12][start_col + 20] = symbol; break;
                case 11: track[height - 12][start_col + 16] = symbol; break;
                case 12: track[height - 12][start_col + 12] = symbol; break;
                case 13: track[height - 10][start_col + 12] = symbol; break;
                case 14: track[height - 10][start_col + 8] = symbol; break;
                case 15: track[height - 10][start_col + 4] = symbol; break;
                case 16: track[height - 12][start_col + 4] = symbol; break;
                case 17: track[height - 14][start_col + 4] = symbol; break;
                case 18: track[1][start_col + 4] = symbol; break;
                case 19: track[1][start_col + 8] = symbol; break;
                case 20: track[1][start_col + 12] = symbol; break;
                case 21: track[1][start_col + 16] = symbol; break;
                case 22: track[1][start_col + 20] = symbol; break;
                case 23: track[1][start_col + 24] = symbol; break;
                case 24: track[1][start_col + 28] = symbol; break;
                case 25: track[1][start_col + 32] = symbol; break;
                case 26: track[1][start_col + 36] = symbol; break;
                case 27: track[1][start_col + 40] = symbol; break;
                case 28: track[height - 14][start_col + 40] = symbol; break;
                case 29: track[height - 12][start_col + 40] = symbol; break;
                case 30: track[height - 12][start_col + 36] = symbol; break;
                case 31: track[height - 12][start_col + 32] = symbol; break;
                case 32: track[height - 12][start_col + 28] = symbol; break;
                case 33: track[height - 10][start_col + 28] = symbol; break;
                case 34: track[height - 8][start_col + 28] = symbol; break;
                case 35: track[height - 8][start_col + 32] = symbol; break;
                case 36: track[height - 8][start_col + 36] = symbol; break;
                case 37: track[height - 6][start_col + 36] = symbol; break;
                case 38: track[height - 4][start_col + 36] = symbol; break;
                case 39: track[height - 2][start_col + 36] = symbol; break;
                case 40: track[height - 2][start_col + 32] = symbol; break;
                case 41: track[height - 2][start_col + 28] = symbol; break;
                case 42: track[height - 2][start_col + 24] = symbol; break;
                case 43: track[height - 2][start_col + 20] = symbol; break;
                case 44: track[height - 2][start_col + 16] = symbol; break;
                case 45: track[height - 2][start_col + 12] = symbol; break;
                case 46: track[height - 2][start_col + 8] = symbol; break;
                case 47: track[height - 2][start_col + 4] = symbol; break;
                case 48: track[height - 2][start_col] = symbol; break;
                default: track[height - 2][start_col] = symbol; break;
            }
        }
        
        // Display the track
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++)
                if (track[i][j] == '*') 
                {
                    cout << "\033[37;42;1m" << track[i][j] << "\033[0m"; //green background and bold 
                } 
                else if (track[i][j] == '#') 
                {
                    cout << "\033[37;41;1m" << track[i][j] << "\033[0m"; //red background and bold 
                }
                else 
                {
                    cout << track[i][j];
                }
            cout << endl;
        }
        cout << endl;
    }

    void display_track_2(vector<Racer> racers, vector<Bridge> bridges)// Function to display track 2
    {
        char track[25][33];
        //Initialize all to spaces
        for (int i = 0; i < height; i++) // Loop through each row of the track
            for (int j = 0; j < width; j++) // Loop through each column in the current row
                track[i][j] = ' ';
        //Top track
        for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
        {
            for (int j = 0; j < width - 1; j = j + 4) // Loop through each 3 column in the current row
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 1] = '+';
        }
        for (int j = 0; j < width; j = j + 4) // Loop through each 3 column in the current row
            track[1][j] = '|';
        //Left and right tracks - vertical lines top part
        for (int i = 3; i < height - 17; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][0] = '|';
            track[i][4] = '|';
            track[i][width - 5] = '|';
            track[i][width - 1] = '|';
            //track design
            track[7][width - 25] = '|';
            track[7][width - 21] = '|';
            track[7][width - 17] = '|';
            track[7][width - 13] = '|';
        }
        //Left and right tracks - vertical lines middle part
        for (int i = 11; i < height - 8; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][4] = '|';
            track[i][8] = '|';
            track[i][width - 5] = '|';
            track[i][width - 1] = '|';
            //track design
            track[9][width - 17] = '|';
            track[9][width - 13] = '|';
            track[9][width - 5] = '|';
            track[9][width - 1] = '|';
            track[11][width - 21] = '|';
            track[11][width - 17] = '|';
            track[11][width - 13] = '|';
        }
        //Left and right tracks - vertical lines bottom part
        for (int i = 15; i < height; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][12] = '|';
            track[i][16] = '|';
            track[i][width - 5] = '|';
            track[i][width - 1] = '|';
        }
        //Left track - horizontal lines top part
        for (int i = 4; i < height - 15; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][0] = '+';
            track[i][1] = '-';
            track[i][2] = '-';
            track[i][3] = '-';
            track[i][4] = '+';
        }
        //Left track - horizontal lines middle part
        for (int i = 6; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][4] = '+';
            track[i][5] = '-';
            track[i][6] = '-';
            track[i][7] = '-';
            track[i][8] = '+';
            track[i][9] = '-';
            track[i][10] = '-';
            track[i][11] = '-';
                track[i][12] = '+';
                track[i][13] = '-';
            track[i][14] = '-';
            track[i][15] = '-';
            track[i][16] = '+';
            track[i][17] = '-';
            track[i][18] = '-';
            track[i][19] = '-';
            track[i][20] = '+';
            track[14][17] = ' ';
            track[14][18] = ' ';
            track[14][19] = ' ';
            track[14][20] = ' ';
            track[16][17] = ' ';
            track[16][18] = ' ';
            track[16][19] = ' ';
            track[16][20] = ' ';
        }
        //Left track - horizontal lines bottom part
        for (int i = 14; i < height - 4; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][12] = '+';
            track[i][13] = '-';
            track[i][14] = '-';
            track[i][15] = '-';
            track[i][16] = '+';
        }
        //Right track - horizontal lines
        for (int i = 4; i < height - 4; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][width - 5] = '+';
            track[i][width - 4] = '-';
            track[i][width - 3] = '-';
            track[i][width - 2] = '-';
            track[i][width - 1] = '+';
        }
        //Bottom track
        for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 12; j < width - 4; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 1] = '+';
        }
        for (int j = 12; j < width; j = j + 4) // Loop through each 3 column of the track
            track[height - 2][j] = '|';

        // Highlight the bridges on the track
        for (int i = 0; i < bridges.size(); ++i) 
        {
            int std = bridges[i].getStart();
            char end = bridges[i].getEnd();
            switch (std)
            {
                case 0: track[height - 2][14] = '*'; break;
                case 1: track[height - 4][14] = '*'; break;
                case 2: track[height - 6][14] = '*'; break;
                case 3: track[height - 8][14] = '*'; break;
                case 4: track[height - 10][14] = '*'; break;
                case 5: track[height - 10][10] = '*'; break;
                case 6: track[height - 10][6] = '*'; break;
                case 7: track[height - 12][6] = '*'; break;
                case 8: track[height - 14][6] = '*'; break;
                case 9: track[height - 14][10] = '*'; break;
                case 10: track[height - 14][14] = '*'; break;
                case 11: track[height - 14][18] = '*'; break;
                case 12: track[height - 16][18] = '*'; break;
                case 13: track[height - 18][18] = '*'; break;
                case 14: track[height - 18][14] = '*'; break;
                case 15: track[height - 18][10] = '*'; break;
                case 16: track[height - 18][6] = '*'; break;
                case 17: track[height - 18][2] = '*'; break;
                case 18: track[height - 20][2] = '*'; break;
                case 19: track[height - 22][2] = '*'; break;
                case 20: track[height - 24][2] = '*'; break;
                case 21: track[height - 24][6] = '*'; break;
                case 22: track[height - 24][10] = '*'; break;
                case 23: track[height - 24][14] = '*'; break;
                case 24: track[height - 24][18] = '*'; break;
                case 25: track[height - 24][22] = '*'; break;
                case 26: track[height - 24][26] = '*'; break;
                case 27: track[height - 24][30] = '*'; break;
                case 28: track[height - 22][30] = '*'; break;
                case 29: track[height - 20][30] = '*'; break;
                case 30: track[height - 18][30] = '*'; break;
                case 31: track[height - 16][30] = '*'; break;
                case 32: track[height - 14][30] = '*'; break;
                case 33: track[height - 12][30] = '*'; break;
                case 34: track[height - 10][30] = '*'; break;
                case 35: track[height - 8][30] = '*'; break;
                case 36: track[height - 6][30] = '*'; break;
                case 37: track[height - 4][30] = '*'; break;
                case 38: track[height - 2][30] = '*'; break;
                case 39: track[height - 2][26] = '*'; break;
                case 40: track[height - 2][22] = '*'; break;
                case 41: track[height - 2][18] = '*'; break;
                case 42: track[height - 2][14] = '*'; break;
                default: track[height - 2][14] = '*'; break;
            }

            switch (end) 
            {
                case 0: track[height - 2][14] = '#'; break;
                case 1: track[height - 4][14] = '#'; break;
                case 2: track[height - 6][14] = '#'; break;
                case 3: track[height - 8][14] = '#'; break;
                case 4: track[height - 10][14] = '#'; break;
                case 5: track[height - 10][10] = '#'; break;
                case 6: track[height - 10][6] = '#'; break;
                case 7: track[height - 12][6] = '#'; break;
                case 8: track[height - 14][6] = '#'; break;
                case 9: track[height - 14][10] = '#'; break;
                case 10: track[height - 14][14] = '#'; break;
                case 11: track[height - 14][18] = '#'; break;
                case 12: track[height - 16][18] = '#'; break;
                case 13: track[height - 18][18] = '#'; break;
                case 14: track[height - 18][14] = '#'; break;
                case 15: track[height - 18][10] = '#'; break;
                case 16: track[height - 18][6] = '#'; break;
                case 17: track[height - 18][2] = '#'; break;
                case 18: track[height - 20][2] = '#'; break;
                case 19: track[height - 22][2] = '#'; break;
                case 20: track[height - 24][2] = '#'; break;
                case 21: track[height - 24][6] = '#'; break;
                case 22: track[height - 24][10] = '#'; break;
                case 23: track[height - 24][14] = '#'; break;
                case 24: track[height - 24][18] = '#'; break;
                case 25: track[height - 24][22] = '#'; break;
                case 26: track[height - 24][26] = '#'; break;
                case 27: track[height - 24][30] = '#'; break;
                case 28: track[height - 22][30] = '#'; break;
                case 29: track[height - 20][30] = '#'; break;
                case 30: track[height - 18][30] = '#'; break;
                case 31: track[height - 16][30] = '#'; break;
                case 32: track[height - 14][30] = '#'; break;
                case 33: track[height - 12][30] = '#'; break;
                case 34: track[height - 10][30] = '#'; break;
                case 35: track[height - 8][30] = '#'; break;
                case 36: track[height - 6][30] = '#'; break;
                case 37: track[height - 4][30] = '#'; break;
                case 38: track[height - 2][30] = '#'; break;
                case 39: track[height - 2][26] = '#'; break;
                case 40: track[height - 2][22] = '#'; break;
                case 41: track[height - 2][18] = '#'; break;
                case 42: track[height - 2][14] = '#'; break;
                default: track[height - 2][14] = '#'; break;
            }
        }


        // Assign racer symbols
        int base_column = 13; // Define the base starting column
        for (int i = 0; i < racers.size(); ++i) 
        {
            int pos = racers[i].getPosition();
            char symbol = racers[i].getCharacter();
            int start_col = base_column + i; // Adjust starting column based on racer index
            // Adjust position to avoid overlap for each racer
            switch (pos) 
            {
                case 0: track[height - 2][start_col] = symbol; break;
                case 1: track[height - 4][start_col] = symbol; break;
                case 2: track[height - 6][start_col] = symbol; break;
                case 3: track[height - 8][start_col] = symbol; break;
                case 4: track[height - 10][start_col] = symbol; break;
                case 5: track[height - 10][start_col - 4] = symbol; break;
                case 6: track[height - 10][start_col - 8] = symbol; break;
                case 7: track[height - 12][start_col - 8] = symbol; break;
                case 8: track[height - 14][start_col - 8] = symbol; break;
                case 9: track[height - 14][start_col - 4] = symbol; break;
                case 10: track[height - 14][start_col] = symbol; break;
                case 11: track[height - 14][start_col + 4] = symbol; break;
                case 12: track[height - 16][start_col + 4] = symbol; break;
                case 13: track[height - 18][start_col + 4] = symbol; break;
                case 14: track[height - 18][start_col] = symbol; break;
                case 15: track[height - 18][start_col - 4] = symbol; break;
                case 16: track[height - 18][start_col - 8] = symbol; break;
                case 17: track[height - 18][start_col - 12] = symbol; break;
                case 18: track[height - 20][start_col - 12] = symbol; break;
                case 19: track[height - 22][start_col - 12] = symbol; break;
                case 20: track[height - 24][start_col - 12] = symbol; break;
                case 21: track[height - 24][start_col - 8] = symbol; break;
                case 22: track[height - 24][start_col - 4] = symbol; break;
                case 23: track[height - 24][start_col] = symbol; break;
                case 24: track[height - 24][start_col + 4] = symbol; break;
                case 25: track[height - 24][start_col + 8] = symbol; break;
                case 26: track[height - 24][start_col + 12] = symbol; break;
                case 27: track[height - 24][start_col + 16] = symbol; break;
                case 28: track[height - 22][start_col + 16] = symbol; break;
                case 29: track[height - 20][start_col + 16] = symbol; break;
                case 30: track[height - 18][start_col + 16] = symbol; break;
                case 31: track[height - 16][start_col + 16] = symbol; break;
                case 32: track[height - 14][start_col + 16] = symbol; break;
                case 33: track[height - 12][start_col + 16] = symbol; break;
                case 34: track[height - 10][start_col + 16] = symbol; break;
                case 35: track[height - 8][start_col + 16] = symbol; break;
                case 36: track[height - 6][start_col + 16] = symbol; break;
                case 37: track[height - 4][start_col + 16] = symbol; break;
                case 38: track[height - 2][start_col + 16] = symbol; break;
                case 39: track[height - 2][start_col + 12] = symbol; break;
                case 40: track[height - 2][start_col + 8] = symbol; break;
                case 41: track[height - 2][start_col + 4] = symbol; break;
                case 42: track[height - 2][start_col] = symbol; break;
                default: track[height - 2][start_col] = symbol; break;
            }
        }
        
        // Display the track
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++)
                if (track[i][j] == '*') 
                {
                    cout << "\033[37;42;1m" << track[i][j] << "\033[0m"; //green background and bold 
                } 
                else if (track[i][j] == '#') 
                {
                    cout << "\033[37;41;1m" << track[i][j] << "\033[0m"; //red background and bold 
                }
                else 
                {
                    cout << track[i][j];
                }
            cout << endl;
        }
        cout << endl;
    }

    void display_track_3(vector<Racer> racers, vector<Bridge> bridges)// Function to display track 3
    {
        char track[19][77];
        //Initialize all to spaces
        for (int i = 0; i < height; i++) // Loop through each row of the track
            for (int j = 0; j < width; j++) // Loop through each column in the current row
                track[i][j] = ' ';
        //Top track
        for (int i = 0; i <= 2; i = i + 2) // Loop through 0 & 2 row of the track
        {
            for (int j = 0; j < width - 17; j = j + 4) // Loop through each 3 column in the current row
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 17] = '+';
        }
        for (int j = 0; j < width - 16; j = j + 4) // Loop through each 3 column in the current row
            track[1][j] = '|';
        for (int j = 16; j < width - 24; j = j + 4) // Loop through each 3 column in the current row
            track[5][j] = '|';
        for (int j = 24; j < width; j = j + 4) // Loop through each 3 column in the current row
            track[9][j] = '|';
        for (int j = 48; j < width - 4; j = j + 4) // Loop through each 3 column in the current row
            track[15][j] = '|';
        for (int j = 0; j < width - 60; j = j + 4) // Loop through each 3 column in the current row
            track[15][j] = '|';
        for (int j = 12; j < width - 48; j = j + 4) // Loop through each 3 column in the current row
            track[13][j] = '|';
        //Left and right tracks - vertical
        for (int i = 3; i < height - 13; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][0] = '|';
            track[i][4] = '|';
            track[i][width - 21] = '|';
            track[i][width - 17] = '|';
        }
        //Left and right tracks - vertical lines
        for (int i = 7; i < height - 9; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][0] = '|';
            track[i][4] = '|';
            track[i][width - 61] = '|';
            track[i][width - 57] = '|';
        }
        //Left and right tracks - vertical lines
        for (int i = 11; i < height - 4; i = i + 2) // Loop through between 3 & 12 / each 2 row of the track
        {
            track[i][0] = '|';
            track[i][4] = '|';
            track[i][width - 5] = '|';
            track[i][width - 1] = '|';
            track[13][width - 9] = '|';
            track[15][width - 53] = '|';
            track[15][width - 49] = '|';
        }
        //Left track - horizontal lines
        for (int i = 4; i < height - 2; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][0] = '+';
            track[i][1] = '-';
            track[i][2] = '-';
            track[i][3] = '-';
            track[i][4] = '+';
        }
        //Left track - horizontal lines
        for (int i = 4; i < height - 12; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][56] = '+';
            track[i][57] = '-';
            track[i][58] = '-';
            track[i][59] = '-';
            track[i][60] = '+';
        }
        //Right track - horizontal lines
        for (int i = 4; i < height - 8; i = i + 2) // Loop through between 4 & 12 / each 2 row of the track
        {
            track[i][width - 61] = '+';
            track[i][width - 60] = '-';
            track[i][width - 59] = '-';
            track[i][width - 58] = '-';
            track[i][width - 57] = '+';
            track[12][width - 9] = '+';
                track[12][width - 8] = '-';
                track[12][width - 7] = '-';
            track[12][width - 6] = '-';
            track[12][width - 5] = '+';
            track[12][width - 4] = '-';
            track[12][width - 3] = '-';
            track[12][width - 2] = '-';
            track[12][width - 1] = '+';
            track[14][width - 4] = '-';
            track[14][width - 3] = '-';
            track[14][width - 2] = '-';
            track[14][width - 1] = '+';
        }
        for (int i = 4; i < height - 12; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 20; j < width - 24; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 21] = '+';
        }
        for (int i = 8; i < height - 8; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 20; j < width - 1; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 1] = '+';
        }
        for (int i = 12; i < height - 4; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 12; j < width - 50; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 49] = '+';
        }
        for (int i = 14; i < height - 2; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 4; j < width - 64; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 61] = '+';
        }
        for (int i = 14; i < height - 2; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 48; j < width - 8; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 5] = '+';
        }
        //Bottom track
        for (int i = height - 3; i < height; i = i + 2) // Loop through between 12 & 15 / each 2 row of the track
        {
            for (int j = 24; j < width - 28; j = j + 4) // Loop through each 3 column of the track
            {
                track[i][j] = '+';
                track[i][j + 1] = '-';
                track[i][j + 2] = '-';
                track[i][j + 3] = '-';
            }
            track[i][width - 25] = '+';
        }
        for (int j = 24; j < width - 24; j = j + 4) // Loop through each 3 column of the track
            track[height - 2][j] = '|';

        // Highlight the bridges on the track
        for (int i = 0; i < bridges.size(); ++i) 
        {
            int std = bridges[i].getStart();
            char end = bridges[i].getEnd();
            switch (std)
            {
                case 0: track[height - 4][2] = '*'; break;
                case 1: track[height - 6][2] = '*'; break;
                case 2: track[height - 8][2] = '*'; break;
                case 3: track[height - 10][2] = '*'; break;
                case 4: track[height - 12][2] = '*'; break;
                case 5: track[height - 14][2] = '*'; break;
                case 6: track[height - 16][2] = '*'; break;
                case 7: track[height - 18][2] = '*'; break;
                case 8: track[height - 18][6] = '*'; break;
                case 9: track[height - 18][10] = '*'; break;
                case 10: track[height - 18][14] = '*'; break;
                case 11: track[height - 18][18] = '*'; break;
                case 12: track[height - 18][22] = '*'; break;
                case 13: track[height - 18][26] = '*'; break;
                case 14: track[height - 18][30] = '*'; break;
                case 15: track[height - 18][34] = '*'; break;
                case 16: track[height - 18][38] = '*'; break;
                case 17: track[height - 18][42] = '*'; break;
                case 18: track[height - 18][46] = '*'; break;
                case 19: track[height - 18][50] = '*'; break;
                case 20: track[height - 18][54] = '*'; break;
                case 21: track[height - 18][58] = '*'; break;
                case 22: track[height - 16][58] = '*'; break;
                case 23: track[height - 14][58] = '*'; break;
                case 24: track[height - 14][54] = '*'; break;
                case 25: track[height - 14][50] = '*'; break;
                case 26: track[height - 14][46] = '*'; break;
                case 27: track[height - 14][42] = '*'; break;
                case 28: track[height - 14][38] = '*'; break;
                case 29: track[height - 14][34] = '*'; break;
                case 30: track[height - 14][30] = '*'; break;
                case 31: track[height - 14][26] = '*'; break;
                case 32: track[height - 14][22] = '*'; break;
                case 33: track[height - 14][18] = '*'; break;
                case 34: track[height - 12][18] = '*'; break;
                case 35: track[height - 10][18] = '*'; break;
                case 36: track[height - 10][22] = '*'; break;
                case 37: track[height - 10][26] = '*'; break;
                case 38: track[height - 10][30] = '*'; break;
                case 39: track[height - 10][34] = '*'; break;
                case 40: track[height - 10][38] = '*'; break;
                case 41: track[height - 10][42] = '*'; break;
                case 42: track[height - 10][46] = '*'; break;
                case 43: track[height - 10][50] = '*'; break;
                case 44: track[height - 10][54] = '*'; break;
                case 45: track[height - 10][58] = '*'; break;
                case 46: track[height - 10][62] = '*'; break;
                case 47: track[height - 10][66] = '*'; break;
                case 48: track[height - 10][70] = '*'; break;
                case 49: track[height - 10][74] = '*'; break;
                case 50: track[height - 8][74] = '*'; break;
                case 51: track[height - 6][74] = '*'; break;
                case 52: track[height - 6][70] = '*'; break;
                case 53: track[height - 4][70] = '*'; break;
                case 54: track[height - 4][66] = '*'; break;
                case 55: track[height - 4][62] = '*'; break;
                case 56: track[height - 4][58] = '*'; break;
                case 57: track[height - 4][54] = '*'; break;
                case 58: track[height - 4][50] = '*'; break;
                case 59: track[height - 2][50] = '*'; break;
                case 60: track[height - 2][46] = '*'; break;
                case 61: track[height - 2][42] = '*'; break;
                case 62: track[height - 2][38] = '*'; break;
                case 63: track[height - 2][34] = '*'; break;
                case 64: track[height - 2][30] = '*'; break;
                case 65: track[height - 2][26] = '*'; break;
                case 66: track[height - 4][26] = '*'; break;
                case 67: track[height - 6][26] = '*'; break;
                case 68: track[height - 6][22] = '*'; break;
                case 69: track[height - 6][18] = '*'; break;
                case 70: track[height - 6][14] = '*'; break;
                case 71: track[height - 4][14] = '*'; break;
                case 72: track[height - 4][10] = '*'; break;
                case 73: track[height - 4][6] = '*'; break;
                case 74: track[height - 4][2] = '*'; break;
                default: track[height - 4][2] = '*'; break;
            }

            switch (end) 
            {
                case 0: track[height - 4][2] = '#'; break;
                case 1: track[height - 6][2] = '#'; break;
                case 2: track[height - 8][2] = '#'; break;
                case 3: track[height - 10][2] = '#'; break;
                case 4: track[height - 12][2] = '#'; break;
                case 5: track[height - 14][2] = '#'; break;
                case 6: track[height - 16][2] = '#'; break;
                case 7: track[height - 18][2] = '#'; break;
                case 8: track[height - 18][6] = '#'; break;
                case 9: track[height - 18][10] = '#'; break;
                case 10: track[height - 18][14] = '#'; break;
                case 11: track[height - 18][18] = '#'; break;
                case 12: track[height - 18][22] = '#'; break;
                case 13: track[height - 18][26] = '#'; break;
                case 14: track[height - 18][30] = '#'; break;
                case 15: track[height - 18][34] = '#'; break;
                case 16: track[height - 18][38] = '#'; break;
                case 17: track[height - 18][42] = '#'; break;
                case 18: track[height - 18][46] = '#'; break;
                case 19: track[height - 18][50] = '#'; break;
                case 20: track[height - 18][54] = '#'; break;
                case 21: track[height - 18][58] = '#'; break;
                case 22: track[height - 16][58] = '#'; break;
                case 23: track[height - 14][58] = '#'; break;
                case 24: track[height - 14][54] = '#'; break;
                case 25: track[height - 14][50] = '#'; break;
                case 26: track[height - 14][46] = '#'; break;
                case 27: track[height - 14][42] = '#'; break;
                case 28: track[height - 14][38] = '#'; break;
                case 29: track[height - 14][34] = '#'; break;
                case 30: track[height - 14][30] = '#'; break;
                case 31: track[height - 14][26] = '#'; break;
                case 32: track[height - 14][22] = '#'; break;
                case 33: track[height - 14][18] = '#'; break;
                case 34: track[height - 12][18] = '#'; break;
                case 35: track[height - 10][18] = '#'; break;
                case 36: track[height - 10][22] = '#'; break;
                case 37: track[height - 10][26] = '#'; break;
                case 38: track[height - 10][30] = '#'; break;
                case 39: track[height - 10][34] = '#'; break;
                case 40: track[height - 10][38] = '#'; break;
                case 41: track[height - 10][42] = '#'; break;
                case 42: track[height - 10][46] = '#'; break;
                case 43: track[height - 10][50] = '#'; break;
                case 44: track[height - 10][54] = '#'; break;
                case 45: track[height - 10][58] = '#'; break;
                case 46: track[height - 10][62] = '#'; break;
                case 47: track[height - 10][66] = '#'; break;
                case 48: track[height - 10][70] = '#'; break;
                case 49: track[height - 10][74] = '#'; break;
                case 50: track[height - 8][74] = '#'; break;
                case 51: track[height - 6][74] = '#'; break;
                case 52: track[height - 6][70] = '#'; break;
                case 53: track[height - 4][70] = '#'; break;
                case 54: track[height - 4][66] = '#'; break;
                case 55: track[height - 4][62] = '#'; break;
                case 56: track[height - 4][58] = '#'; break;
                case 57: track[height - 4][54] = '#'; break;
                case 58: track[height - 4][50] = '#'; break;
                case 59: track[height - 2][50] = '#'; break;
                case 60: track[height - 2][46] = '#'; break;
                case 61: track[height - 2][42] = '#'; break;
                case 62: track[height - 2][38] = '#'; break;
                case 63: track[height - 2][34] = '#'; break;
                case 64: track[height - 2][30] = '#'; break;
                case 65: track[height - 2][26] = '#'; break;
                case 66: track[height - 4][26] = '#'; break;
                case 67: track[height - 6][26] = '#'; break;
                case 68: track[height - 6][22] = '#'; break;
                case 69: track[height - 6][18] = '#'; break;
                case 70: track[height - 6][14] = '#'; break;
                case 71: track[height - 4][14] = '#'; break;
                case 72: track[height - 4][10] = '#'; break;
                case 73: track[height - 4][6] = '#'; break;
                case 74: track[height - 4][2] = '#'; break;
                default: track[height - 4][2] = '#'; break;
            }
        }

        // Assign racer symbols
        int base_column = 1; // Define the base starting column
        for (int i = 0; i < racers.size(); ++i) 
        {
            int pos = racers[i].getPosition();
            char symbol = racers[i].getCharacter();
            int start_col = base_column + i; // Adjust starting column based on racer index
            // Adjust position to avoid overlap for each racer
            switch (pos) 
            {
                case 0: track[height - 4][start_col] = symbol; break;
                case 1: track[height - 6][start_col] = symbol; break;
                case 2: track[height - 8][start_col] = symbol; break;
                case 3: track[height - 10][start_col] = symbol; break;
                case 4: track[height - 12][start_col] = symbol; break;
                case 5: track[height - 14][start_col] = symbol; break;
                case 6: track[height - 16][start_col] = symbol; break;
                case 7: track[height - 18][start_col] = symbol; break;
                case 8: track[height - 18][start_col + 4] = symbol; break;
                case 9: track[height - 18][start_col + 8] = symbol; break;
                case 10: track[height - 18][start_col + 12] = symbol; break;
                case 11: track[height - 18][start_col + 16] = symbol; break;
                case 12: track[height - 18][start_col + 20] = symbol; break;
                case 13: track[height - 18][start_col + 24] = symbol; break;
                case 14: track[height - 18][start_col + 28] = symbol; break;
                case 15: track[height - 18][start_col + 32] = symbol; break;
                case 16: track[height - 18][start_col + 36] = symbol; break;
                case 17: track[height - 18][start_col + 40] = symbol; break;
                case 18: track[height - 18][start_col + 44] = symbol; break;
                case 19: track[height - 18][start_col + 48] = symbol; break;
                case 20: track[height - 18][start_col + 52] = symbol; break;
                case 21: track[height - 18][start_col + 56] = symbol; break;
                case 22: track[height - 16][start_col + 56] = symbol; break;
                case 23: track[height - 14][start_col + 56] = symbol; break;
                case 24: track[height - 14][start_col + 52] = symbol; break;
                case 25: track[height - 14][start_col + 48] = symbol; break;
                case 26: track[height - 14][start_col + 44] = symbol; break;
                case 27: track[height - 14][start_col + 40] = symbol; break;
                case 28: track[height - 14][start_col + 36] = symbol; break;
                case 29: track[height - 14][start_col + 32] = symbol; break;
                case 30: track[height - 14][start_col + 28] = symbol; break;
                case 31: track[height - 14][start_col + 24] = symbol; break;
                case 32: track[height - 14][start_col + 20] = symbol; break;
                case 33: track[height - 14][start_col + 16] = symbol; break;
                case 34: track[height - 12][start_col + 16] = symbol; break;
                case 35: track[height - 10][start_col + 16] = symbol; break;
                case 36: track[height - 10][start_col + 20] = symbol; break;
                case 37: track[height - 10][start_col + 24] = symbol; break;
                case 38: track[height - 10][start_col + 28] = symbol; break;
                case 39: track[height - 10][start_col + 32] = symbol; break;
                case 40: track[height - 10][start_col + 36] = symbol; break;
                case 41: track[height - 10][start_col + 40] = symbol; break;
                case 42: track[height - 10][start_col + 44] = symbol; break;
                case 43: track[height - 10][start_col + 48] = symbol; break;
                case 44: track[height - 10][start_col + 52] = symbol; break;
                case 45: track[height - 10][start_col + 56] = symbol; break;
                case 46: track[height - 10][start_col + 60] = symbol; break;
                case 47: track[height - 10][start_col + 64] = symbol; break;
                case 48: track[height - 10][start_col + 68] = symbol; break;
                case 49: track[height - 10][start_col + 72] = symbol; break;
                case 50: track[height - 8][start_col + 72] = symbol; break;
                case 51: track[height - 6][start_col + 72] = symbol; break;
                case 52: track[height - 6][start_col + 68] = symbol; break;
                case 53: track[height - 4][start_col + 68] = symbol; break;
                case 54: track[height - 4][start_col + 64] = symbol; break;
                case 55: track[height - 4][start_col + 60] = symbol; break;
                case 56: track[height - 4][start_col + 56] = symbol; break;
                case 57: track[height - 4][start_col + 52] = symbol; break;
                case 58: track[height - 4][start_col + 48] = symbol; break;
                case 59: track[height - 2][start_col + 48] = symbol; break;
                case 60: track[height - 2][start_col + 44] = symbol; break;
                case 61: track[height - 2][start_col + 40] = symbol; break;
                case 62: track[height - 2][start_col + 36] = symbol; break;
                case 63: track[height - 2][start_col + 32] = symbol; break;
                case 64: track[height - 2][start_col + 28] = symbol; break;
                case 65: track[height - 2][start_col + 24] = symbol; break;
                case 66: track[height - 4][start_col + 24] = symbol; break;
                case 67: track[height - 6][start_col + 24] = symbol; break;
                case 68: track[height - 6][start_col + 20] = symbol; break;
                case 69: track[height - 6][start_col + 16] = symbol; break;
                case 70: track[height - 6][start_col + 12] = symbol; break;
                case 71: track[height - 4][start_col + 12] = symbol; break;
                case 72: track[height - 4][start_col + 8] = symbol; break;
                case 73: track[height - 4][start_col + 4] = symbol; break;
                case 74: track[height - 4][start_col] = symbol; break;
                default: track[height - 4][start_col] = symbol; break;
            }
        }
        
        // Display the track
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++)
                if (track[i][j] == '*') 
                {
                    cout << "\033[37;42;1m" << track[i][j] << "\033[0m"; //green background and bold 
                } 
                else if (track[i][j] == '#') 
                {
                    cout << "\033[37;41;1m" << track[i][j] << "\033[0m"; //red background and bold 
                }
                else 
                {
                    cout << track[i][j];
                }
            cout << endl;
        }
        cout << endl;
    }
    
    void display_track(vector<Racer> racers, vector<Bridge> bridges)// Function to display the selected track
    {
        switch (selected_track) 
        {
            case 1:
                display_track_1(racers, bridges);// Display track 1
                break;
            case 2:
                display_track_2(racers, bridges);// Display track 2
                break;
            case 3:
                display_track_3(racers, bridges);// Display track 3
                break;
            default:
                cout << "Invalid track selection!" << endl;
                break;
        }
    }
};

#endif // TRACK_H
