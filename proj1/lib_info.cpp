// Makenzie Johnson and Nicholas Wandinata
// TA: Christian, Andrew
// Compile: g++ -o lib_info lib_info.cpp

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
    else if(sec < 10) {
        int position = colonTime.find(":") + 1;
        colonTime.insert(position, "0");
    }
    return colonTime;
}

/*We create a third map in order to gain access to the Artist struct.
 * Each iterator will iterate through each map.*/

int main(int argc, char **argv) {
    string musicInfo, title, songTime, artist, album, genre;
    int track;
    Artist art;
    Album alb;
    Song song;
    map<string, Artist> artists;
    map<string, Artist> :: iterator it;
    map<string, Album> :: iterator al_it;
    map<int, Song> :: iterator so_it;

    ifstream file;
    file.open(argv[1]);
    
    while(getline(file, musicInfo)) {
        istringstream iss(musicInfo);
        iss >> title >> songTime >> artist >> album >> genre >> track;
		
		//After reading in the information, we replaced '_' with spaces
			
        replace(artist.begin(), artist.end(), '_', ' ');
        replace(album.begin(), album.end(), '_', ' ');
        replace(title.begin(), title.end(), '_', ' ');

        // process for the artist 
        // if the artist doesnt exists, we insert the artist into the map and point the 
		// iterator back to the artist so we can initialize each member in the struct

        it = artists.find(artist);
        if(it == artists.end()){
            artists.insert(make_pair(artist, art));
            it = artists.find(artist);
            it -> second.nsongs = 1; 
            it -> second.time = timeToSec(songTime);
            it -> second.name = artist;

		}

        // if the artist exists, we increment the nsongs counter and add to the 
		// total time

        else {
            it -> second.nsongs += 1;
            it -> second.time += timeToSec(songTime);
        }

        // process for the album
        al_it = it -> second.albums.find(album);
        // if the album exits 
        if(al_it == it -> second.albums.end()) {
            it -> second.albums.insert(make_pair(album, alb));
            al_it = it -> second.albums.find(album);
            al_it -> second.name = album;
            al_it -> second.time = timeToSec(songTime);
            al_it -> second.nsongs = 1;

        }

        // if the album doesnt exist
        else{
            al_it -> second.nsongs += 1; //add the certain songs
            al_it -> second.time += timeToSec(songTime);
        }

        //process for songs; just add the songs
        al_it -> second.songs.insert(make_pair(track, song));
        so_it = al_it -> second.songs.find(track);
        so_it -> second.time = songTime;
        so_it -> second.title = title;
    }

    //Once done, print out everything
    for(it = artists.begin(); it != artists.end(); it++){

        cout << it -> second.name << ": " << it -> second.nsongs << ", " << timeToMin(it -> second.time) << endl;
        
        //albums
        for(al_it = it -> second.albums.begin(); al_it != it -> second.albums.end(); al_it++){

            cout << "        " << al_it -> second.name << ": " << al_it -> second.nsongs << ", " << timeToMin(al_it -> second.time)<< endl;

            //songs
            for(so_it = al_it -> second.songs.begin(); so_it != al_it -> second.songs.end(); so_it++){

                cout << "                " << so_it -> first << ". " << so_it -> second.title << ": " << so_it -> second.time << endl;
            }
        }
    }

    file.close();
    return 0;
}
