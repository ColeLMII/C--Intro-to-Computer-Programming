/*
    Name: Larenzle Coleman II (T00271500)
    Course: CSC 1310-001
    Assignment: Program 4
    Purpose: Driver Implementation of AVLTree
*/

#include <iostream>
#include <fstream>
#include "Professor.h"
#include "AVLTree.h"

//additional functions
bool sTob(string no){
    if(no == "0"){
        //cout << "f\n";
        return false;
    }
    else
        //cout << "t\n";
        return true;
}

AVLTree readFromFile(AVLTree profTree){
    string name, cName;
    string cG,gF,c,r,tg,lh,a;
    bool pcG,pgF, pc, pr, ptg,plh,pa;
    int count = 0;
    
    ifstream infile;
    string filename = "ProfessorData.txt";
    infile.open(filename);
        if(!infile){
            cout << "Sorry!  Can’t read professor data from file.\n";
            return profTree;
        }

    for(int x = 0; x < 11; x++){
        getline(infile,name,'$');
        getline(infile,cName,'$');
        getline(infile,cG,'$');
            pcG = sTob(cG); 
        getline(infile,gF,'$');
            pgF = sTob(gF);
        getline(infile,c,'$');
            pc = sTob(c);
        getline(infile,r,'$');
            pr = sTob(r);
        getline(infile,tg,'$');
            ptg = sTob(tg);
        getline(infile,lh,'$');
            plh = sTob(lh);
        getline(infile,a,'$');
            pa = sTob(a);
        
        Professor* temp;
        temp = new Professor(name,cName,pcG,pgF,pc,pr,ptg,plh,pa);
        
        profTree.insertNode(name, temp);
        count++;
    } 
    cout << "\nImported ("<< count <<") Professors.\n\n";

    return profTree;
}

int main(){
    string name;
    AVLTree profTree;
    profTree = readFromFile(profTree);
    int userC = 1;

    do{
    switch (userC){
        case 1:{
                    cout << "\n***************************\n";
            cout << "\n Professor Name List:\n";
                    cout << "***************************\n\n";
                profTree.displayInOrder();
                    cout << "\n***************************\n";
            
            cout << "\nWhich Professor (Type Name): ";
                cin >> name; 
                    cout << "\n***************************\n";
            Professor* bingo;
            bingo = (profTree.searchNode(name));
                
            if(bingo != NULL){
                    cout << "\n***************************\n";
                cout << *bingo;
                    cout << "\n***************************\n";
                }

            else{
                delete bingo;
                cout << "\nWould you like to try again? (y/n):";
                string res;
                        cin >> res;
                        cin.ignore();
                    if(res == "N" || res == "n"){
                        userC = 2;
                    }
                    else{
                        userC = 1;
                    }
            }
            break;
        }
        case 2:{
            userC = 0;
            return 0;
        }
    }
    }while(userC <= 2 && userC >= 1);

    cout << "\nEnding Program . . . \n";
    return 0;
}