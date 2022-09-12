/*
    Name: Larenzle Coleman II
    Date: October 27, 2020
    Class Section: CSC 1310-001
    Purpose: Implmentation of values to be held inside the hash table head file.
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include "Classname.h"
using namespace std;

template <typename omg>
class sEntry{
private:
    bool empty;
    omg val;
    sEntry<omg>* next;


public:
    bool tNext;
    //constructor
    sEntry(){
        this->next = NULL;
        this->tNext = false;
        this->empty = true;
    }

    sEntry sEntr(int r, omg x){
        sEntry cre;
        cre.empty = false;
        cre.val = x;
        cre.tNext =NULL;

        return cre;
    }

    bool emp(){
         return this->empty;
     }

    void resetSName(){
        omg empty;
        empty.setsongName("unassigned.");
        empty.setsongArtist("unassigned.");

        this->val = empty;
        this->no = -1;
    }

    omg getValuee(){
        return this->val;
    }

    void setValue(omg x){
        this->val = x;
        this->empty = false;
    }

    sEntry<omg>* getNext(){
        return this->next;
    }

    void setNext(sEntry<omg> x, int y){
        this->next = &x;
        next->getValuee().setID(y);
        next->empty = false;
        this->tNext = true;

    }

    //returns an empty sEntry
    omg Knots(){

        cout << "not avaliable" << endl;
    }


};

#endif