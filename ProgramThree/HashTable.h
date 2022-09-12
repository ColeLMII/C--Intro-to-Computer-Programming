/*
    Name: Larenzle Coleman II
    Date: October 27, 2020
    Class Section: CSC 1310-001
    Purpose: Implementation of the Hash Table Function Header file.
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

template <typename tired>
class HashTable{

    private:
       int amount; //amount of song space holders in hashtable
       tired* sList; //the list of songs 

    public:
        //constructor
        HashTable(int x){
            amount = x;
           //sList = new HashTable<tired<Songs>[amount]; 
            sList = new tired[amount];// had to do the empty constructor on hashentry . . .
            
            //assigns every song space holder to empty for the time being.
            for(int fo = 0; fo < amount; fo++){
                sList[fo] = tired();
            }
        }

        //destructor
        ~HashTable(){
           delete [] sList;
        }

        /*
            more function portypes . . . 
            + insert, delete, print and search . . .
        */
        void putValue(int key, tired x);
        tired getValue(int);
        void removeValue(int);
        void printHashTable() const;
        void sSearch(int) const;
};

template<typename tired>
void HashTable<tired>::putValue(int key, tired x){
    int assign = key % 10;

    cout << "Favorite Song No. " << assign << "\n" << endl;
    string test = "No Title";

    //inserts into empty first table space
    if(this->sList[assign].emp()== true){
        //x.getValuee().setID(key);
        this->sList[assign].setValue(x.getValuee());   
    }

    //chaining implementation
    else if(this->sList[assign].emp() == false){
        tired* holder = &(this->sList[assign]);
        tired* temp = NULL;


        //check the next
        while(holder->tNext == true){
            holder = holder->getNext();
        }

        if(this->sList[assign].emp() == true){
            //x.getValuee().setID(key);
            holder->setNext(x,key);
        }
    }

    cout << "Did it work?" << endl;
}

template<typename tired>
tired HashTable<tired>::getValue(int key){
   int assign = key % 10;
    string test = "No Title";

    //if the table space is empty
   if((this->sList[assign]).getSNO() == -1){
       return (
           this->sList[assign]).sEntry("-1"); //problems hear . . .
   }

   while((this->sList[assign]).getValue().getsongName() != test && (this->sList[assign].getSNO() != key)){
       //assign = (assign + 1) % 10;
       return (this->sList[assign]).getValue();
   }

    
}

template<typename tired>
void HashTable<tired>::removeValue(int key){
   tired* cur;
   //tired* previous;
   int assign = key % 10;

    tired empty;
        empty.getValuee().setsongName("unassigned.");
        empty.getValuee().setsongArtist("unassigned.");

    //checking the chain
   if((this->sList[assign]).emp() == false){
       cur = &(this->sList[assign]);
       //previous = NULL;
       tired* next;
       next = &(*(this->sList[assign].getNext()));

       while( next != NULL && cur->getValuee().getID() != key){
           //previous = cur;
           cur = (cur->getNext());

            if(cur->getValuee().getID() == key){
                tired nxt = *(cur->getNext());
                delete cur;
                (this->sList[assign]) = nxt;
            }
            else{
                tired nxt = *(cur->getNext());
                delete cur;
                this->sList[assign].setValue(nxt.getValuee());
            }
                
        }
    }
}

template<typename tired>
void HashTable<tired>::printHashTable() const{
    cout << "Favorite Songs: \n" << endl;
    cout << "*********************************\n" << endl;

    for (int q = 0; q < 10; q++){

        if((this->sList[q]).emp() != false){
            
            cout << "---->" << setw(12) << (this->sList[q]).getValuee().getsongName() << " by " << (this->sList[q]).getValuee().getsongArtist() << "\n" << endl;
            
           //tired* po = (this->sList[q]).getValue();
           /*tired* po = this->sList[q];
           bool dog = po->getNext()->emp();
           cout << "here";
            while(dog = false){
                cout << "---->" << setw(12) << (this->sList[q]).getValuee().getsongName() << " by " << (this->sList[q]).getValuee().getsongArtist() << setw(8);
                
                po = po->getNext();
            }*/
        }
        else{
            cout << "--->" << setw(12) << "Empty\n" << endl;
        }
    }

    cout << "*********************************\n" << endl;
}

template<typename tired>
void HashTable<tired>::sSearch(int x) const{
    cout << "Searching . . . \n";

    for(int q = 0; q < this->amount; q++){
        if((this->sList[q].emp() == false)){
            cout << "*********************************\n" << endl;

            cout << "---->" << setw(12) << (this->sList[q]).getValuee().getsongName() << " by " << (this->sList[q]).getValuee().getsongArtist() << "\n" << endl;

            cout << "*********************************\n" << endl;
        }

        else
        {
            cout << "Not Found.\n" << endl;
        }
    }
}

#endif