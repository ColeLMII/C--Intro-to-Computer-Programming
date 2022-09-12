/*
    Name: Larenzle Coleman II
    Date: October 27, 2020
    Class Section: CSC 1310-001
    Purpose: Just a class declaration for the information held inside of each hash entry.
    - Data Held Inside favorite song titles directory.
*/
#ifndef CLASSNAME_H
#define CLASSNAME_H

#include <iostream>

using namespace std;

class Song{

    private:
        int idNum;
        string name; // song title
        string artist; // song artist

    public:
        
        //constructor
        Song(){
            name = "No Title";
            artist = "No Name";
        }

        /*  
            Song(string n, string a){
                name = n;
                artist = a;
            }
        */

        //accessor and mutator functions for song attributes
        void setsongName(string x);
        void setsongArtist(string x);
        void setID(int);
        string getsongName();
        string getsongArtist();
        int getID();

};

#endif
