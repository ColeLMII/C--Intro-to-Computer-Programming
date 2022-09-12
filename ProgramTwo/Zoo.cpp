/*
    Larenzle Coleman II (T00271500)
    CSC 1310-001, Program Two
    File Contents: Zoo Driver 
*/

#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Creature.h"

using namespace std;

void enterMagicalCreature(LinkedList<Creature> x);
void enterMagicalCreatureFromFile(LinkedList<Creature> x);
void deleteCreature(LinkedList<Creature> x);
void printCreature(LinkedList<Creature> x);
void saveCreatureToFile(LinkedList<Creature> x);

//extra fucntions for program
int menu();
int cOne();
int cFour();


int main(){
    LinkedList<Creature> cList;
    int choice = -1;

   //program display header
   {
       cout << "*******************************************************************************************"<< endl;
    cout << "************************************Creature Log************************************" << endl;
    cout << "*******************************************************************************************" << endl;
   }
   
   choice = menu();

    switch(choice){
        case '1':{
            int enter = cOne();

            if(enter == 1){ //manual
                enterMagicalCreature(cList);
            }
            else if(enter == 2){ //import
                enterMagicalCreatureFromFile(cList);
            }

            choice = menu();
        }

        case '2':{
            deleteCreature(cList);
            choice = menu();
        }

        case '3':{
            printCreature(cList);
            choice = menu();
        }

        case '4':{
            int dec = cFour();
            if(dec == 1){

            }
            else if(dec == 2){

            }
            cout << " Closing Program, Good Bye . . .\n";
            break;
        }
    }

    return 0;
}

void enterMagicalCreature(LinkedList<Creature> x){
    Creature a;

    cout << "Fill in the Following:\n" << endl;

    cout << "Enter Creature Name:" << endl;
        a.setName();
        cin.ignore();
            cout << endl;
    cout << "Enter Creature Description:\n";
        a.setDescription();
        cin.ignore();
            cout << endl;
    cout << "Enter Monthly Upkeep Cost: ";
        a.setCost();
        cin.ignore();
            cout << endl;
    cout << "Is the Creature Dangerous or Passive?\n";
    cout << " 1.) Dangerous\n";
    cout << " 2.) Passive (Non-Threatening)\n";
        a.setDangerous();
        cin.ignore();
        cout << endl;

        //stopped here for the night >:)

    x.appendNode();
};

void enterMagicalCreatureFromFile(LinkedList<Creature> x){
    string file;
    Creature temp;

    cout <<"Enter File Name (yourfilename.txt): ";
        cin >> file;
        cin.ignore();

    ifstream myfile;
    myfile.open(file);

    string a;
    myfile << a;
        temp.setName(a);
             myfile << a;
                temp.setDescription();
    float b;
    myfile << b;
        temp.setCost(b);
    
    int c;
    myfile << c;
        temp.setDangerous(c);

    //how do i make the while loop thru until the last creature is reached . . .
};

void deleteCreature(LinkedList<Creature> x){
    int choice = -1;
    int count = 0;

    LinkedList<Creature> ptr;
    ptr = x;

    //Display the Node Lsit
    do{
        for(int xx = 1; xx < (x.getNumNodes()); xx++){
            x.getNodeValue(xx);
        }
        
    }while(count != (x.getNumNodes()));

    cout << "What node should be deleted? (Numbers Only 1 - " << x.getNumNodes() << ") : ";
    do{
        cin >> choice;

        if(choice < 1 || choice > (x.getNumNodes())){
            cout << "Invalid Choice, Try Again."
        }
    }while (choice < 1 || choice > (x.getNumNodes()) );

    //protcol to delete that creature
    x.deleteNode(choice);
    
    /*
    LinkedList<Creature> ptr;
    ptr = x;

    Creature temp;

    //print the creatures first
    //user selects creature to delete

    //protcol to delete that creature
    for(int x; x <= (x.numNodes); x++){
        if( x == pos;){
            temp = ptr.getNodeValue(x);
        
        }
    }
*/
};

int cFour(){
    int input = -1;

    cout << "Would you like to save your Creature list?\n";
    cout << "  1.) Yes\n";
    cout << "  2.) No\n";
        do{
            cin >> input;
                cin.ignore();
            
            if(input < 1 || input > 2){
                cout << "Invalid Input ! Try a option ( 1 or 2 ) only.\n" << endl;
            }

        }while(input < 1 || input > 2);

    cout << "*******************************************************************************************"<< endl;

    return input;
}

int cOne(){
    int input = -1;

    cout << "(Append Addtional Creature) Select an option below. (1-2):\n" << endl;
    cout << "   1.) Manually Enter the Creature." << endl;
    cout << "   2.) Import the Creatures from a File." << endl;
   
        do{
            cin >> input;
                cin.ignore();
            
            if(input < 1 || input > 2){
                cout << "Invalid Input ! Try a option ( 1 or 2 ) only.\n" << endl;
            }

        }while(input < 1 || input > 2);

    cout << "*******************************************************************************************"<< endl;

    return input;
}

int menu(){
    int input = -1;

    cout << "Select an option below. (1-4):\n" << endl;
    cout << "   1.) Enter a New/Old Creature." << endl;
    cout << "   2.) Delete a Creature." << endl;
    cout << "   3.) Print current list of Creatures." << endl;
    cout << "   4.) Close Program (Optional Save)." << endl;
        do{
            cin >> input;
                cin.ignore();
            
            if(input < 1 || input > 4){
                cout << "Invalid Input ! Try a option ( 1 - 4 ) only.\n" << endl;
            }

        }while(input < 1 || input > 4);

    cout << "*******************************************************************************************"<< endl;
    return input;
}