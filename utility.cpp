#include "utility.h"

//utility function. Prompt user to enter an integer with data validation
int getInt()
{
      int temp;

      cin >> temp;
      while (!cin)
      {
              cin.clear();
              cin.ignore(STR_SIZE, '\n');

              cout << "You entered an illegal integer. Please try again: ";
              cin >> temp;
      }
      cin.ignore(STR_SIZE, '\n');
      return temp;
}

//utility function. Prompt user to enter a string with data validation
void getString(char str[], int maxChar)
{
      cin.get(str, maxChar, '\n');
      while (!cin)
      {
              cin.clear();
              cin.ignore(maxChar, '\n');

              cout << "You did not enter anything. Please try again: ";
              cin.get(str, maxChar, '\n');
      }
      cin.ignore(STR_SIZE, '\n');
}

//utility function. Prompt user to enter a character with data validation
char getChar()
{
      char temp;

      cin >> temp;
      while (!cin)
      {
              cin.clear();
              cin.ignore(STR_SIZE, '\n');

              cout << "You need to enter a character. Please try again: ";
              cin >> temp;
      }
      cin.ignore(STR_SIZE, '\n');
      return temp;
}

//utility function. Convert a cstring to all lowercase
void convertToLower(char cstring[]){
	for(size_t i=0; i < strlen(cstring); i++){
		cstring[i] = tolower(cstring[i]);
	}
}
