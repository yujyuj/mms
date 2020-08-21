#include "songlist.h"
#include "menutools.h"

//defualt consturctor
SongList::SongList():head(nullptr), tail(nullptr), size(0){}

//constuctor that takes a file as parameter and create create an object with the date from the file
SongList::SongList(const char fileName[]):SongList(){  //constructor delegation
        ifstream inData;
        char song_title[STR_SIZE];
        char song_artist[STR_SIZE];
        int song_minute;
        int song_second;
        char song_album[STR_SIZE];

        inData.open(fileName);

        //print out a message when it fails to open a file
        if (!inData) {
                cerr << "Failed to open " << fileName << " for reading!" << endl;
                exit(1);
        }

        inData.get(song_title, STR_SIZE, ';');
        // keep grabbing information until it gets to the end of the file or it reaches the capacity of a SongList object
        while (!inData.eof()) {

                inData.get();  //throw away ; delimiter

                inData.get(song_artist, STR_SIZE, ';');
                inData.get();  //throw away ; delimiter

                inData >> song_minute;
                inData.get();  //throw away ; delimiter

                inData >> song_second;
                inData.get();  //throw away ; delimiter

                inData.get(song_album, STR_SIZE, '\n');
                inData.ignore(STR_SIZE, '\n');  //throw away '\n'

                //initialize a Song object with the the file contents
                Song current_song(song_title, song_artist, song_minute, song_second, song_album);
		
		//add a Song object to the end of the linked list
                insertByTitleSong(current_song);
                inData.get(song_title, STR_SIZE, ';');
        }
	
        inData.close();
}

//destructor that loop thru the linked list and deallocate each song object
SongList::~SongList(){
	if(!head)
		return;
	
	Node *current = head;
	while(current){
		head = head->next;
		delete current;
		current = head;
	}
}


//mutator to add a Song object to the sorted linked list by title
void SongList::insertByTitleSong(const Song &aSong){
	
	size++;

	//create a Song Node, and traverse the linked list until it find a spot
	Node* new_node = new Node(aSong);
	Node* current = head;
	while(current && current->data < aSong){  //assume that operator< is overloade to compare 2 Song objects based on their titles
		current = current->next;
	} 

	//add the new_node as head
	if(current == head){
		if(!tail)     //when the linked list is empty
			tail = new_node;
		else{         //when the linked list is non-empty
			new_node->next = head;
			head->prev = new_node;
		}
		head = new_node;
		return;
	}

	// add the new_node as tail
	if(!current){       
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
		return;
	}

	// add the new_node somewhere in the linked list
	new_node->prev = current->prev;
	new_node->next = current;
	current->prev = new_node;
	new_node->prev->next = new_node;

	return;
}


//prompt user to enter the index of the song they want to delete, then delete that Song object from the linked list
void SongList::deleteSongAtIndex(){

        //when the SongList object does not contain any songs
        if(size==0){
                cout << "No song to delete. The music stock is empty." << endl;
                return;
        }

        //prompt user to enter the index
        cout << "Please enter the index of the song to delete: ";
        int index = getIndex();

        //traverse to the target node, delete current node, update head and tail as needed
        Node *current = head;
        for(int i = 1; i < index; i++){
                current = current->next;
        }
       
	//delete head
	if(current == head){
                head = head->next;
		head->prev = nullptr;
	}
	//delete tail
        else if(current == tail){
                tail = current->prev;
		tail->next = nullptr;
	}
	//delete somewhere in the middle
        else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
        }
        delete current; //deallcoate the memory
        size--;

        cout << "Just deleted a song." << endl;
        return;
}

//prompt user to enter a song and append it to the linked list
void SongList::readInSong(){

	//call function of the Song class to perform data input from the user	
	Song aSong;
	aSong.readInSong();
	insertByTitleSong(aSong);
}

//search for a song
void SongList::searchSong() const{

	cout << "Would you like to search by 1.artist or 2.album? ";
	char command = readInCommand();
	
	switch(command){
		
		case '1':
			searchArtist();
			break; 
		case '2':
			searchAlbum();
			break;
		default:
			cout << "Invalid command!" << endl;
			break;
	}
}

//search by artist
void SongList::searchArtist() const{

	char input_artist[STR_SIZE], onfile_artist[STR_SIZE];
	int result_index = 1;
	
	//prompt user to enter the artist to search	
	cout << "Please enter the artist: ";
	getString(input_artist, STR_SIZE);
	convertToLower(input_artist); //convert user input to all lowercase using a utility function
	
	//traverse the linked list to extract artist information of each Song object
	//then compare each Song object's artist data with user input
	//display each Song that contains the target artist
	cout << "Searching result:" << endl;
	
	Node *current = head;
	while(current){
		current->data.getArtist(onfile_artist);
		convertToLower(onfile_artist);

		char index_str[10];
		if(strstr(onfile_artist, input_artist)){
			sprintf(index_str, "[%d]", result_index++);
			cout << left << setw(6) << index_str;
			current->data.printSong();
		}
		current = current->next;
	}

	//if result_index didn't get incremented, then no artist was found
	if(result_index == 1) cout << "No artist was found." << endl;
}

//search by album
void SongList::searchAlbum() const{

	char input_album[STR_SIZE], onfile_album[STR_SIZE];
	int result_index = 1;
	
	//prompt user to enter the album to search	
	cout << "Please enter the album: ";
	getString(input_album, STR_SIZE);
	convertToLower(input_album); //convert user input to all lowercase using a utility function
	
	//traverse the linked list to retrieve album information of each Song object
	//then compare each Song object's album data with user input
	//display each Song that contains the target album
	cout << "Searching result:" << endl;
	
	Node *current = head;
	while(current){
		current->data.getAlbum(onfile_album);
		convertToLower(onfile_album);

		char index_str[10];
		if(strstr(onfile_album, input_album)){
			sprintf(index_str, "[%d]", result_index++);
			cout << left << setw(6) << index_str;
			current->data.printSong();
		}
		current = current->next;
	}

	//if result_index didn't get incremented, then no album was found
	if(result_index == 1) cout << "No album was found." << endl;
}



// prompt user to enter the index of a song to remove/edit
int SongList::getIndex(){

	//prompt user to enter the index
	int index;
	index = getInt();
	//keeps prompting until user enter a valid index
	while(index > size  || index < 1){
		printf("Index out of range. Please enter again (from 1 to %d): ", size );
		index = getInt();
	}
	return index;	
}

void SongList::editSong(){

	// prompt user to enter the index of the song to edit
	cout << "Please enter the index of the song to edit: ";
	int index = getIndex();
	
	// prompt user to choose what to edit
	cout << "What would you like to edit? " << endl
	     << "1. title \n2. artist \n3. duration(minute) \n4. duration(second) \n5. album" << endl;
	char command = readInCommand();
	
	//traverse the linked list to get to the song object
	Node *current = head;
	for(int i = 1; i < index; i++){
		current = current->next;
	}

	char input[STR_SIZE];
	int duration;

		switch(command){
		
			case '1':
				cout << "Please enter a new title: ";
				getString(input, STR_SIZE);
				current->data.setTitle(input);
				break;
			case '2':
				cout << "Please enter a new artist: ";
				getString(input, STR_SIZE);
				current->data.setArtist(input);
				break;
			case '3':
				cout << "Please enter minute: ";
				duration = getInt();
				current->data.setMinute(duration);
				break;
			case '4':
				cout << "Please enter second: ";
				duration = getInt();
				current->data.setSecond(duration);
				break;
			case '5':
				cout << "Please enter a new album: ";
				getString(input, STR_SIZE);
				current->data.setAlbum(input);
				break;
			default:
				cout << "Invalid command!" << endl;
				break;
		}
		cout << endl << "The song has been updated: "<< endl;
		current->data.printSong();
}

//helper function that calls another function to recursively display the linked list
void SongList::displayList() const{
	displayList(head, 1);
}

//recursively traverse the linked list and display all Song objects
void SongList::displayList(Node * currHead, int index) const{

	if(currHead){
		char index_str[10];
		sprintf(index_str, "[%d]", index);
                cout << left << setw(6) << index_str;
                currHead->data.printSong();
		displayList(currHead->next, index+1);
	}
}

//getter for size
int SongList::getSize() const{
        return size;
}


//write data back to a file
void SongList::writeFile(const char fileName[]){

        ofstream outData;

        //print out a message when it fails to write to a file
        outData.open(fileName);
        if (!outData) {
                cerr << "Failed to open " << fileName << " for writing! " << endl;
                exit(1);
        }

        //write each Song object's information to the file using ; as delimiter
	Node *current = head;
	while(current){
                current->data.writeSongToFile(outData);
		current = current->next;
	} 
        outData.close();
}

