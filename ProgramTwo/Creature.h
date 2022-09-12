/*
    Larenzle Coleman II (T00271500)
    CSC 1310-001, Program Two
    File Contents: Creature Header File
*/

#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>

using namespace std;

class Creature{
    private:

    string name, description;
    float costPM;
    bool deadly;

    public:

    Creature(){
    name = "No Name.";
    description = "No Description.";
    costPM = 0;
    deadly = 0;
    }//default constructor

    Creature(string n, string d, bool dE, float c);
    
    //accessor functions.
    string getName();
    string getDescription();
    float getCost();
    bool getDangerous();

    //mutator functions.
    void setName();
    void setDescription();
    void setCost();
    void setDangerous();

    //misc prototypes
    void printCreature();
    void printCreatureToFile(string);

};

#endif