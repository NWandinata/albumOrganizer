// Makenzie Johnson and Nicholas Wandinata
// TA: Christian, Andrew
// Compiled using "make" command; makefile included in tar

/* Description: This program reads info from a file and outputs it as a 
   sorted music library. Artists and albums are in lexicographic order 
   while songs are sorted by track number. All info is stored in maps 
   and structs. */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include "lib_info.h"

using namespace std;

// Returns the time as an int of the total seconds
int timeToSec(string time) {
    int min, sec;
    char colon;
    istringstream iss(time);
    iss >> min >> colon >> sec;
    sec += (min * 60);
    return sec;
}

// Returns the time as a string in min:sec format
string timeToMin(int time) {
    int min, sec;
    string colonTime;
    min = time / 60;
    sec = time - min * 60;
    colonTime = to_string(min) + ":" + to_string(sec);
    if(sec == 0) colonTime += "0";
    return colonTime;
}

int main(int argc, char **argv) {
    string musicInfo, title, songTime, artist, album, genre;
    int track;
    Artist art;
    Album alb;
    Song song;
    map<string, Artist> artists;

	// Iterators a needed to store and output struct values
    map<string, Artist> :: iterator it;
    map<string, Album> :: iterator al_it;
    map<int, Song> :: iterator so_it;

    ifstream file;
    file.open(argv[1]);

	// Continuously takes input and puts info into the structs
    while(!file.eof()) {
        getline(file, musicInfo);
        istringstream iss(musicInfo);
        iss >> title >> songTime >> artist >> album >> genre >> track;

		// Stores artist info
		// If the artist doesnt exists (i.e. new artist)
        it = artists.find(artist);
        if(it == artists.end()){ 
            artists.insert(make_pair(artist, art));
            it = artists.find(artist);
            it -> second.nsongs = 1; 
            it -> second.time = timeToSec(songTime); 
            it -> second.name = artist;
        } 

        // If the artist already exists
		// Keeps running total of nSongs and total time for artist
        else {
            it -> second.nsongs += 1;
			it -> second.time += timeToSec(songTime);
        }

        // Stores album info
		// If the album already exits
        al_it = it -> second.albums.find(album);
        if(al_it == it -> second.albums.end()) {
            it -> second.albums.insert(make_pair(album, alb));
            al_it = it -> second.albums.find(album);
            al_it -> second.name = album;
            al_it -> second.time += timeToSec(songTime);
            al_it -> second.nsongs += 1;
        }

        // If the album doesnt exist (i.e. new album)
		// Keeps running total of nSongs and total time for artist
        else{
            al_it -> second.nsongs = 1;
			al_it -> second.time = timeToSec(songTime);
        }

        // Stores song info
		// No need to convert time since it's stored as a string for songs
        al_it -> second.songs.insert(make_pair(track, song));
        so_it = al_it -> second.songs.find(track);
        so_it -> second.time = songTime;
        so_it -> second.title = title;
    }

	//Once done, print out everything
    for(it = artists.begin(); it != artists.end(); it++){
        string new_name = it -> second.name;
        replace(new_name.begin(), new_name.end(), '_', ' ');

        cout << new_name << ": " << it -> second.nsongs << ", " << it -> second.time << endl;

        //albums
        for(al_it = it -> second.albums.begin(); al_it != it -> second.albums.end(); al_it++){
            string new_name = al_it -> second.name;
            replace(new_name.begin(), new_name.end(), '_', ' ');

            cout << "        " << new_name << ": " << al_it -> second.nsongs << ", " << al_it -> second.time << endl;

            //songs
            for(so_it = al_it -> second.songs.begin(); so_it != al_it -> second.songs.end(); so_it++){
                string new_name = so_it -> second.title;
                replace(new_name.begin(), new_name.end(), '_', ' ');

                cout << "                " << so_it -> first << ". " << new_name
                << ": " << so_it -> second.time << endl;
            }
        }
    }

    file.close();
    return 0;
}
