/*
    Name: Larenzle Coleman II
    Date: October 27, 2020
    Class Section: CSC 1310-001
    Purpose: The Main function plus additionan implementation code
*/

#include <iostream>
#include <fstream>
//#include "Classname.h"
//#include "HashEntry.h"
#include "HashTable.h"

using namespace std;

HashTable<sEntry<Song>>* readFromFile(string x, HashTable<sEntry<Song>>*);
HashTable<sEntry<Song>>* addValue(int x, HashTable<sEntry<Song>>* y);
void search(int x, HashTable<sEntry<Song>>* y);
HashTable<sEntry<Song>>* removeVal(int x, HashTable<sEntry<Song>>* y);
void display();


int main(){
	cout <<"\n\n" << "_________________________________________________\n" <<endl;
    //opener
    cout << "Your Personal Song Scroll is being unraveled . . .\n" <<endl;
    for(int x = 0; x < 2;x++){
        cout << " ( >_> ) . . .  \n" << endl;
            cout << "Almost there  (>:D)" << endl;
        cout <<  setw(12) << " . . . ( <_< )\n" << endl;
    }

	int menuChoice = 0;
	bool bacon = true;
	string filename;
	HashTable<sEntry<Song>>* Scroll = new HashTable<sEntry<Song>>(10);

    //menu
    while(bacon != 0){
        cout << "_________________________________________________\n" <<endl;
		cout << "\nSong Scroll Editor Options:\n";
		cout << "1.  Import Song from file.\n";
		cout << "2.  Add a Song.\n";
		cout << "3.  Delete a song from the Scroll.\n";
		cout << "4.  Search for a Song.\n";
		cout << "5.  Display Song Scroll.\n";
		cout << "6.  Close Song Scroll.\n";
		cout << "_________________________________________________\n" <<endl;
		cout << setw(12) <<"CHOOSE 1-6: ";
		
			cin >> menuChoice;
			menuChoice = static_cast<int> (menuChoice);

		while(menuChoice < 1 || menuChoice >= 7)
		{
			cout << "That is not a valid choice.\n";
			cout << setw(12) << "CHOOSE 1-6:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:{//Import from song file
				cout << "\n\nOpening the File . . . \n\n";
					filename = "datatext.txt";
					//cin >> filename;
					Scroll = readFromFile(filename, Scroll); //function is in Movies.cpp

				menuChoice = 0;
				display();
				break;
			}	
					
			case 2:{// Add a new song.
				cout << "Adding new song . . .\n" << endl;
				
				cout << "What's the numerical rank of this song? (i.e. 1-10) ";
					cin.ignore();
				int num;
					cin >> num;

				//send the name and artist
				Scroll = addValue( num, Scroll);

				menuChoice = 0;
				display();
				break;
			}

			case 3:{//Delete a song from the Scroll
				cout << "What song would you like to delete? (i.e. 1-10): ";
				int cow;
					cin.ignore();
					cin >> cow;

				Scroll = removeVal(cow, Scroll);

				menuChoice = 0;
				//display();
				break;
			}

			case 4:{//Search for Song.
				cout << "Which song are you looking for? (i.e. 1-10): ";
				int pig;
					cin.ignore();
					cin >> pig;
				search(pig, Scroll);

				menuChoice = 0;
				//display();
				break;
			}

			case 5:{//Display song scroll.
				cout << "Printing . . .\n" << endl;

				Scroll->printHashTable();
				menuChoice = 0;
				//display();
				break;
			}

			case 6: {//close the scroll
				bacon = 0;
			}
		}
	};

	cout << "\n\n . . . Rolling up your scroll . . . " << endl;
	return 0;
}

HashTable<sEntry<Song>>* readFromFile(string x, HashTable<sEntry<Song>>* Scroll){
	bool done = 0;
	int count = 0;
	ifstream file;
	Song temp;
	string name;
	string Artist;
	int key;
file.open(x);
	if(!file){
		string d;
		cout << "Wrong File Name, Enter Correct Name (i.e. 'datatext.txt'): ";
			cin >> d;
		file.open(d);
	}
		
	while(done != 1){
		file >> key;
		getline(file,name);
		getline(file, Artist);
		(file >> done);

		temp.setsongArtist(Artist);
		temp.setsongName(name);
		temp.setID(key);

		sEntry<Song> crow;
		crow.setValue(temp);
		//crow.setID(key);
		//crow.setEntry(temp, key);

		Scroll[count].putValue(key, crow);
		count++;
	};

file.close();

	cout << "Done Reading from File . . ." << endl;

	return Scroll;
}

HashTable<sEntry<Song>>* addValue(int x, HashTable<sEntry<Song>>* y){
	cout << "What is the song's name? ";
		cin.ignore();
	string name;
		cin >> name;

	cout << "What's the artist name ? ";
		cin.ignore();
	string artist;
		cin >> artist;

	Song now;
	now.setsongName(name);
	now.setsongArtist(artist);

	sEntry<Song> crow;
	crow.setValue(now);
	crow.getValuee().setID(x);

	int assign = x % 10;
	y[assign].putValue(x, crow);

	return y;
}

void search(int x, HashTable<sEntry<Song>>* y){
	int assign = x % 10;
	y[assign].sSearch(x);

	cout << "Done Searching  . . ." << endl;
}

HashTable<sEntry<Song>>* removeVal(int x, HashTable<sEntry<Song>>* y){
	int assign = x % 10;
	y[assign].removeValue(x);
	cout << "Song removed . . .\n" << endl;

	//HashTable<sEntry<Song>> *Scroll = new sEntry<Song>[10]

	//check the rating??
	/*for(uno = 0; uno < 10; uno++){
		if(y[uno].getValue().getSNO() == x){
			tired* holder = (this->sList[assign]);

        while(this->sList[assign].getValue().getNext() != NULL){
            holder = (this->sList[assign].getValue().getNext();
        }
		}
	}*/
	return y;
}

void display(){
	cout << "_________________________________________________\n" <<endl;
		cout << "\nSong Scroll Editor Options:\n";
		cout << "1.  Import Song from file.\n";
		cout << "2.  Add a Song.\n";
		cout << "3.  Delete a song from the Scroll.\n";
		cout << "4.  Search for a Song.\n";
		cout << "5.  Display Song Scroll.\n";
		cout << "6.  Close Song Scroll.\n";
		cout << "_________________________________________________\n" <<endl;
		cout << setw(12) <<"CHOOSE 1-6: ";
}