//Header file
//Makenzie Johnson and Nicholas Wandinata
//2-3-23
//Got this from Plank's Notes

#include <map>
#include <string>
using namespace std;

struct Song {
    string title; // Song title 
    string time;  // could also be a string; Song's total runtime
};

struct Album {
    map <int, Song > songs; // int key represents the track number
    string name; // Album name 
    int time = 0; // Album's total runtime
    int nsongs = 0;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums; // string key is the album name
    string name; // The artist name
    int time = 0; // Total runtime of all artist's 
    int nsongs = 0;
};

int timeToSec(string time);
string timeToMin(int time);

