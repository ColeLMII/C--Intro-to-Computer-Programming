#include <iostream>

using namespace std;

//destructor
    /*~sEntry(){
        delete val;
    }*/

    //inserts song
    void insS(){
        
        //might need a for loop implmentation ???
        cout << "Enter the Songs Name? :";
            string name;
                cin.ignore();
            cin >> name;
            
        cout << "Enter Artist Name:";
            string artist;
                cin.ignore();
            cin >> artist;

        //increment entry position after this

    }

    //set entry position number
    void setSNo(int x){
        no = x;
    }

    int getSNo(){
        return this->no;
    }

    //deletes a song
    void delS(int key, /* send hashTable*/ ){

    }

    //searches for a song
    void seaS(int key, /*send hash table*/){
        // go thru the hashtable and compare each value, to find the key
        // if the key is not found, indicate it was not found
    }z