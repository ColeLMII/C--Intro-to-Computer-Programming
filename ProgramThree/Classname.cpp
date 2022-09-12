/*
    Name: Larenzle Coleman II
    Date: October 27, 2020
    Class Section: CSC 1310-001
    Purpose: Just a class declaration for the information held inside of each hash entry.
    -Public Function Declarations for the Song Class.
*/

#include <iostream>
#include "Classname.h"
using namespace std;

//song class function implementations
void Song::setsongName(string x){
        name = x;
    }

void Song::setsongArtist(string x){
    artist = x;
}

string Song::getsongName(){
    return this->name;
}

string Song::getsongArtist(){
    return this->artist;
}

void Song::setID(int x){
    this->idNum=x;
}

int Song::getID(){
    return this->idNum;
}