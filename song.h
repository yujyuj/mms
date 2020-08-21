#ifndef SONG_H
#define SONG_H

#include <fstream>
#include <iomanip>

#include "utility.h"

class Song {
public:
        Song();                                                                                              //default constructor
        Song(const char newTitle[], const char newArtist[], int newMin, int newSec, const char newAlbum[]);  //constructor
	Song(const Song &aSong);                                                                             //copy constructor
	~Song();                                                                                             //destructor

        void setTitle(const char newTitle[]);
        void getTitle(char destination[]) const;

        void setArtist(const char newArtist[]);
        void getArtist(char destination[]) const;

        void setMinute(int newMinute);
        int getMinute() const;

        void setSecond(int newSecond);
        int getSecond() const;

        void setAlbum(const char newAlbum[]);
        void getAlbum(char destination[]) const;

	int readInDuration() const;
        void printSong() const;
        void writeSongToFile(ofstream& outData) const ;
	void readInSong();
	void operator=(const Song &aSong);
	
	friend bool operator< (const Song&, const Song&);
private:
        char *title;
        char *artist;
        int minute;
        int second;
        char *album;
	
	void init(const char newTitle[], const char newArtist[], int newMin, int newSec, const char newAlbum[]);
};

bool operator< (const Song&, const Song&);

#endif
