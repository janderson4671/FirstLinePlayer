#include "Playlist.h"

Playlist::Playlist(string playlistName) {

    this->playlistName = playlistName;

}

string Playlist::GetName() {

    return playlistName;

}

string Playlist::PlayFirstLines() {

    ostringstream oss;
    
    //iterate through songs and get first lines
    for (size_t i = 0; i < songs.size(); i++) {

        oss << songs.at(i)->GetFirstLine() << endl;
        songs.at(i)->incrament();

    }

    return oss.str();

}

void Playlist::addSong(Song * song) {

    songs.push_back(song);

}

void Playlist::removeSong(int index) {

    songs.erase(songs.begin() + index);

}

void Playlist::removeSong(string songName) {

    //run through song vector and erase the one at the found index
    for (size_t i = 0; i < songs.size(); i++) {

        if (songs.at(i)->GetName() == songName) {
            songs.erase(songs.begin() + i);
            break;
        }
    }

}

size_t Playlist::numSongs() {

    return songs.size();

}

vector<Song *> Playlist::GetSongs() {

    return songs;

}