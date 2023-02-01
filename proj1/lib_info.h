//Header file
//Makenzie Johnson and Nicholas Wandinata

#include <map>
#include <string>
using namespace std;

struct Song {
    string title; // Song title 
    int time;  // could also be a string; Song's total runtime
};

struct Album {
    map <int, Song > songs; // int key represents the track number
    string name; // Album name 
    int time; // Album's total runtime
    int nsongs;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums; // string key is the album name
    string name; // The artist name
    int time; // Total runtime of all artist's 
    int nsongs;
};

