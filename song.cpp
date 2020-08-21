#include "song.h"

//default constructor
Song::Song(){
	init("UNKNOW", "UNKNOWN", 0, 0, "UNKNOWN");
}

//constructor that takes 5 parameters
Song::Song(const char newTitle[], const char newArtist[], int newMin, int newSec, const char newAlbum[]){
	init(newTitle, newArtist, newMin, newSec, newAlbum);
}

//copy constructor
Song::Song(const Song &aSong){
	title = nullptr;
	artist = nullptr;
	album = nullptr;
	*this = aSong;  //assume operator= is overloaded to do deep copy

}

//init function for constructors
void Song::init(const char newTitle[], const char newArtist[], int newMin, int newSec, const char newAlbum[]){
	title = new char[strlen(newTitle)+1];
	strcpy(title, newTitle);
	
	artist = new char[strlen(newArtist)+1];
	strcpy(artist, newArtist);

	minute = newMin;
	second = newSec;

	album = new char[strlen(newAlbum)+1];
	strcpy(album, newAlbum);
}


//operator= overload
void Song::operator=(const Song &aSong){
	if(this == &aSong)
		return;

	setTitle(aSong.title);
	setArtist(aSong.artist);
	setMinute(aSong.minute);
	setSecond(aSong.second);
	setAlbum(aSong.album);
}


//destructor
Song::~Song(){
	if(title)
		delete [] title;
	if(artist)	
		delete [] artist;
	if(album)
		delete [] album;
}

//setter for title
void Song::setTitle(const char newTitle[]){
	if(title)
		delete [] title;
	title = new char[strlen(newTitle)+1];
	strcpy(title, newTitle);
}

//getter for title
void Song::getTitle(char destination[]) const{
        strcpy(destination, title);
}

//setter for artist
void Song::setArtist(const char newArtist[]){
	if(artist)
		delete [] artist;
	artist = new char[strlen(newArtist)+1];
        strcpy(artist, newArtist);
}

//getter for artist
void Song::getArtist(char destination[]) const{
        strcpy(destination, artist);
}

//setter for minute
void Song::setMinute(int newMinute){
        if(newMinute >= 0 && newMinute < 60){
                minute = newMinute;
        }
        else{
                cout << "Invalid entry for minute! " << endl;
        }
}

//getter for minute
int Song::getMinute() const {
        return minute;
}

//setter for second
void Song::setSecond(int newSecond){
        if(newSecond >= 0 && newSecond < 60){
                second = newSecond;
        }
        else{
                cout << "Invalid entry for second!" << endl;
        }
}

//getter for second
int Song::getSecond() const{
        return second;
}

//setter for album
void Song::setAlbum(const char newAlbum[]){
	if(album)
		delete [] album;
	album = new char[strlen(newAlbum)+1];
        strcpy(album, newAlbum);
}

//getter for album
void Song::getAlbum(char destination[]) const{
        strcpy(destination, album);
}


//prompt user to enter duration
int Song::readInDuration() const{
        int temp;
        temp = getInt();
        while(temp < 0 || temp >=60){
                cout << "Invalid entry. Please enter value between 0 and 59: " ;
                temp = getInt();
        }
        return temp;
}

//display data of a Song object
void Song::printSong() const{
	printf( "%-25.24s (%02d:%02d) %-15.14s [Album] %-15.15s\n", title, minute, second, artist, album);	
}

//prompt user to enter a new song
void Song::readInSong(){
       char input_title[STR_SIZE], input_artist[STR_SIZE], input_album[STR_SIZE];
       int input_minute, input_second;

       cout << "Please enter the title: ";
       getString(input_title, STR_SIZE);

       cout << "Please enter the artist: ";
       getString(input_artist, STR_SIZE);

       cout << "Please enter the duration of minute: ";
       input_minute = readInDuration();

       cout << "Please enter the duration of second: ";
       input_second = readInDuration();

       cout << "Please enter the album: ";
       getString(input_album, STR_SIZE);

       setTitle(input_title);
       setArtist(input_artist);
       setMinute(input_minute);
       setSecond(input_second);
       setAlbum(input_album);
}


//write each Song object's information using ; as delimiter
void Song::writeSongToFile(ofstream& outData) const{
        outData << title << ';'
                << artist << ';'
                << minute << ';'
                << second << ';'
                << album << endl;
}

//overload operator< to compare two Song objects based on title
bool operator< (const Song& s1, const Song& s2){

	//convert title to all lower case
	char t1[STR_SIZE], t2[STR_SIZE];
	strcpy(t1, s1.title);
	strcpy(t2, s2.title);
	convertToLower(t1);
	convertToLower(t2);	

	//compare the lower-case version of the two titles
	return strcmp(t1, t2) < 0;
}



