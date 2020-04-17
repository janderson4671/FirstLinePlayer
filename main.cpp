#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Song.h"
#include "Playlist.h"

using namespace std;

void listPlaylist(vector<Playlist>& playlist) {

    for (unsigned int i = 0; i < playlist.size(); i++) {

        cout << setw(3) << right << i << ": " << playlist.at(i).GetName() << endl;

    }

}

void listSongs(const vector<Song *>& library) {

    for (size_t i = 0; i < library.size(); i++) {

        cout << setw(3) << right << i << ": " << library.at(i)->GetName() << endl;

    }

}

void PrintOptions() {

    cout << "add" << "\t" << "Adds a list of songs to the library" << endl;
    cout << "list" << "\t" << "Lists all the songs in the library" << endl;
    cout << "addp" << "\t" << "Adds a new playlist" << endl;
    cout << "addsp" << "\t" << "Adds a song to a playlist" << endl;
    cout << "listp" << "\t" << "Lists all the playlists" << endl;
    cout << "play" << "\t" << "Plays a playlist" << endl;
    cout << "remp" << "\t" << "Removes a playlist" << endl;
    cout << "remsp" << "\t" << "Removes a song from a playlist" << endl;
    cout << "remsl" << "\t" << "Removes a song from the library (and all playlists)" << endl;
    cout << "options" << "\t" << "Prints this options menu" << endl;
    cout << "quit" << "\t" << "Quits the program" << endl;

}

int main() {

    string userOption = "";
    vector<Song *> library;
    vector<Playlist> playlists;

    cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl << endl;

    while (userOption != "quit") {

        //get user input
        cout << "Enter your selection now: ";
        cin >> userOption;
        cin.ignore();
        cout << endl;

        //use if else ladder to process commands
        if (userOption == "add") {
            
            string songName = "";
            string firstLine = "";

            cout << "Enter songs' names and first lines (type \"DONE\" when done): " << endl;
            
            while (songName != "DONE") {
                cout << "Song Name: ";
                getline(cin, songName);

                //if they say stop then break
                if (songName == "DONE") {
                    break;
                }

                cout << endl << "Song's first line: ";
                getline(cin, firstLine);
                cout << endl;

                //add it to the library
                library.push_back(new Song(songName, firstLine));
            }

        }
        else if (userOption == "list") {
            
            //list the songs
            for (size_t i = 0; i < library.size(); i++) {
                cout << library.at(i)->ToString() << endl;
            }

        }
        else if (userOption == "addp") {
            
            string playlistName = "";

            //prompt user for name of playlist
            cout << "Playlist name: ";
            getline(cin, playlistName);
            cout << endl;

            //add playlist to vector
            Playlist currPlaylist(playlistName);
            playlists.push_back(currPlaylist);

        }
        else if (userOption == "addsp") {
            
            int playIndex = 0;
            int songIndex = 0;

            //list the current playlists
            listPlaylist(playlists);
            cout << "Pick a playlist index number: ";
            cin >> playIndex;
            cin.ignore();
            cout << endl;

            //list the songs in library and get index
            listSongs(library);
            cout << "Pick a song index number: ";
            cin >> songIndex;
            cin.ignore();
            cout << endl;

            //find the song at the index and add the pointer to the playlist
            playlists.at(playIndex).addSong(library.at(songIndex));

        }
        else if (userOption == "listp") {
            
            // //iterate through library and call the ToString function
            // for (size_t i = 0; i < library.size(); i++) {
            //     cout << library.at(i)->ToString() << endl;
            // }
            listPlaylist(playlists);

        }
        else if (userOption == "play") {

            int playIndex = 0;

            //print the current playlists
            listPlaylist(playlists);
            cout << "Pick a playlist index number: ";
            cin >> playIndex;
            cin.ignore();
            cout << endl;

            //Play the first lines of all the songs
            cout << "Playing songs from playlist: " << playlists.at(playIndex).GetName() << endl;
            cout << playlists.at(playIndex).PlayFirstLines() << endl;

        }
        else if (userOption == "remp") {
            
            int indexToRemove = 0;

            //remove playlist at the given index
            listPlaylist(playlists);
            cout << "Pick a playlist index number to remove: ";
            cin >> indexToRemove;
            cin.ignore();
            cout << endl;

            playlists.erase(playlists.begin() + indexToRemove);

        }
        else if (userOption == "remsp") {

            int playIndex = 0;
            int songIndex = 0;

            //print playlists
            listPlaylist(playlists);
            cout << "Pick a playlist index number: ";
            cin >> playIndex;
            cin.ignore();
            cout << endl;

            //print songs from chosen playlist
            listSongs(playlists.at(playIndex).GetSongs());
            cout << "Pick a song index number to remove: ";
            cin >> songIndex;
            cin.ignore();
            cout << endl;

            //remove song from playlist
            playlists.at(playIndex).removeSong(songIndex);

        }
        else if (userOption == "remsl") {
            
            int songIndex = 0;

            //get song from user
            listSongs(library);
            cout << "Pick a song index number to remove: ";
            cin >> songIndex;
            cin.ignore();

            //go through all playlists that song
            string songName = library.at(songIndex)->GetName();

            for (size_t i = 0; i < playlists.size(); i++) {
                playlists.at(i).removeSong(songName);
            }

            //Delete and remove song from the library
            delete library.at(songIndex);
            library.erase(library.begin() + songIndex);

        }
        else if (userOption == "options") {
            
            PrintOptions();

        }
        else if (userOption == "quit") {

            break;

        }
        else {

            PrintOptions();

        }

    }

    //delete the vector
    for (size_t i = 0; i < library.size(); i++) {
        delete library.at(i);
    }

    cout << "Goodbye!" << endl;

    return 0;
}
