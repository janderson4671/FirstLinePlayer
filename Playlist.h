#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Song.h"

using namespace std;

class Playlist {

private:

    string playlistName;
    vector<Song *> songs;

public:

    Playlist(string playlistName);
    string GetName();
    vector<Song *> GetSongs();
    void addSong(Song * song);
    void removeSong(int index);
    void removeSong(string songName);
    string PlayFirstLines();
    size_t numSongs();

};


#endif