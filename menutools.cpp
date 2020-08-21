#include "menutools.h"

void start(){
        system("clear");
	logo();
        char filename[] = "songs.txt";
        char command;

        //create a SongList object passing in an external text file
        SongList playlist(filename);

        //keep looping until the user wants to quit
        do{
                displayMenu();
                command = readInCommand();
                executeCommand(playlist, filename, command);
        } while(command!='6');
}


//display the menu for the user
void displayMenu() {
        cout << endl << endl 
		<< " --- M A I N   M E N U ---" << endl << endl          
                << "1. Add a song" << endl
                << "2. Search for a song" << endl
                << "3. Remove a song" << endl
		<< "4. Edit a song" << endl
                << "5. View all songs" << endl
                << "6. Quit" << endl <<endl;
        return;
}

//prompt user for a command
char readInCommand(){
	cout << "Choose your option: ";
	return tolower(getChar());
}

//execute the command entered by the user
void executeCommand(SongList& list, const char filename[],  char cmd){

	
	switch(cmd){
		
		case '1':
			list.readInSong();
			break;
		case '2':
			list.searchSong();	
			break;
		case '3':
			list.deleteSongAtIndex();
			break;
		case '4':
			list.editSong();
			break;
		case '5':
			list.displayList(); 
			break;
		case '6':
			farewell();
			list.writeFile(filename);
			break;
		default:
			cout << "Invalid command!" << endl;
			break;
			
	}			
 }


void farewell(){
	system("clear");
	cout << endl;
	cout << "                           --- B Y E  B Y E ---                           " << endl;
	logo();
}


void logo(){
	cout << endl	
	     << " -------------------------------------------------------------------------" << endl
	     << "                                                                          " << endl
	     << "                                                                          " << endl
	     << "    M U S I C    P L A Y L I S T    M A N A G E M E N T    S Y S T E M    " << endl
	     << "                                                                          " << endl
	     << "                                                                          " << endl
	     << " -------------------------------------------------------------------------" << endl;
}

