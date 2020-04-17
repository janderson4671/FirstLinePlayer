#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Song {

private:
    string songName;
    string firstLine;
    int numPlayed;

public:

    Song(string songName, string firstLine);
    string ToString();
    string GetFirstLine();
    string GetName();
    void incrament();


};

#endif