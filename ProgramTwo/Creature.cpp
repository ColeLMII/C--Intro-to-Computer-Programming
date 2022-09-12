/*
    Larenzle Coleman II (T00271500)
    CSC 1310-001, Program Two
    File Contents: Creature Function implementation file.
*/

#include <iostream>
#include "Creature.h"
#include <fstream>

using namespace std;

Creature::Creature(string n, string d, bool dE, float c){
    name = n;
    description = d;
    costPM = c;
    deadly = dE;
    }//user constructor

//accessor functions.
string Creature::getName(){
    return this->name;
};

string Creature::getDescription(){
    return this->description;
};

float Creature::getCost(){
    return this->costPM;
};

bool Creature::getDangerous(){
    return this->deadly;
};

//mutator functions.
void Creature::setName(){
    string x;
        cin >> x;
    this->name = x;
};

void Creature::setDescription(){
    string x;
        cin >> x;
    this->description = x;
};

void Creature::setCost(){
    float val;
        cin >> val;
    this->costPM = val;
};

void Creature::setDangerous(){
    int x;
    do{
        cin >> x;

        if( x < 0 || x > 1){
            cout << "Invalid Response ! Choose Either ( 0 or 1 ): ";
        }
    }while( x < 0 || x > 1);
    
    bool cr = x;

    this-> deadly = cr;
};

//misc prototypes
void Creature::printCreature(){
    cout << "Name: ";
        this->getName();
        cout << endl;
    cout << "Description: " << endl;
        this->getDescription();
        cout << endl;
    cout << "Cost : $";
        this->getCost();
        cout << "\n" << endl;
    cout << "Threat Level: ";
        this->getDangerous();
        cout << "\n" << endl;
};

void Creature::printCreatureToFile(string x) { //does this rewrite the file if its opened a second time?
    ofstream cFile;
    cFile.open (x);
    cFile << this->name << endl;
    cFile << this->description << endl;
    cFile << this->costPM << endl;
    cFile << this->deadly << endl;
    cFile.close();
};