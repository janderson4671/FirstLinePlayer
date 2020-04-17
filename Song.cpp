#include "Song.h"

Song::Song(string songName, string firstLine) {

    this->songName = songName;
    this->firstLine = firstLine;
    numPlayed = 0;

}

string Song::ToString() {

    ostringstream oss;

    oss << songName << ": \"" << firstLine << "\", " << numPlayed << " play(s).";

    return oss.str();

}

string Song::GetFirstLine() {

    return firstLine;

}

string Song::GetName() {

    return songName;

}

void Song::incrament() {

    numPlayed += 1;

}