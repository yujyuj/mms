#ifndef SONGLIST_H
#define SONGLIST_H

#include <cstdlib>
#include "song.h"

class SongList {
	struct Node{
		Song data;
		Node* next;
		Node* prev;
		Node(const Song& aSong):data(aSong), next(nullptr), prev(nullptr){} //constructor
	};	
	Node* head;
	Node* tail;
	int size;
	
	void displayList(Node* , int) const; //recursively display the linked list
public:
        SongList();                       //default constructor
        SongList(const char fileName[]);  //constructor that takes a file as parameter and create a object with the data
        ~SongList();                      //destructor
        void insertByTitleSong(const Song &);
	void readInSong();
        void displayList() const;
        void searchSong() const;
	void searchArtist() const;
	void searchAlbum() const;
        void deleteSongAtIndex();
	void editSong();
        int getSize() const;
        void writeFile(const char fileName[]);
	int getIndex();
};

#endif
