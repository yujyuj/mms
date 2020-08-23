/*
Yujun Liu
CS 162 Project 5
8/13/2020

The program implements a music playlist management sytem.
This app loads songs from an external text file and saves songs to the same file after the user is done. 
Users can view all songs, add/remove/edit songs and search by artist and album.

[Implementation]
1) Use class to implement Song and SongList. Apply ecapsulation by making all member variables private.
   Provide getters and setters to access and manipulate data. 
2) For the Song class, dynamic character array is utilized to model cstring for 3 data members: title, artist and album.
   The character array is allocated with the exact size as needed.
   Use printf to print out each song object with proper padding, trucating and width. 
3) For the SongList class, a doubly linked list is utilized to model a growable, flexible and memory efficient collection of Song objects.
   New song will be added to the sorted list by title.
   Use recursion to print out the linked list.
4) A makefile is included. The executable is named "project5". 


[Data validation]
 This app is able to 
1) Handle bad data. User will be prompted to re-enter if they entered invalid input.
2) Grow itself, so users stock many songs.

sources: none
*/

#include "menutools.h"

int main(){
	start();

	return 0;
}




