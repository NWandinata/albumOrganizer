/*Makenzie Johnson and Nicholas Wandinata
TA: Christian, Andrew*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdio.h>      /* printf */
#include "lib_info.h"

using namespace std;

int timeToSec(string time) {
    int min, sec;
    char colon;
    istringstream iss(time);
    iss >> min >> colon >> sec;
    sec += (min * 60);
    return sec;
}

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
    map<string, Artist> :: iterator it;
    map<string, Album> :: iterator al_it;
    map<int, Song> :: iterator so_it;

    ifstream file;
    file.open(argv[1]);
    while(!file.eof()) {
        getline(file, musicInfo);
        //replace(musicInfo.begin(), musicInfo.end(), '_', ' ');
        istringstream iss(musicInfo);
        iss >> title >> songTime >> artist >> album >> genre >> track;

		// process for the artist 
		// if the artist doesnt exists
        it = artists.find(artist);
        if(it == artists.end()){ //if new artist
            artists.insert(make_pair(artist, art));
            it = artists.find(artist);
            it -> second.nsongs = 1; 
            it -> second.time = timeToSec(songTime); 
            it -> second.name = artist;

        } 
        // if the artist exists
        else {
            it -> second.nsongs += 1; // adds songs
			it -> second.time = timeToSec(songTime);
            //for time: create function that converts to seconds and store it below
            //it -> second.time += songTime;
        }

        // process for the album
        al_it = it -> second.albums.find(album);
        // if the album exits 
        if(al_it == it -> second.albums.end()) {
            it -> second.albums.insert(make_pair(album, alb));
            al_it = it -> second.albums.find(album);
            al_it -> second.name = album;
            al_it -> second.time = 0;
            al_it -> second.nsongs = 1;

        }

        // if the album doesnt exist
        else{
            al_it -> second.nsongs += 1; //add the certain songs
        }

        //process for songs; just add the songs
        al_it -> second.songs.insert(make_pair(track, song));
        so_it = al_it -> second.songs.find(track);
        so_it -> second.time = songTime;
        so_it -> second.title = title;
    }

    file.close();
    return 0;
}
