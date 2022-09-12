/*
    Larenzle Coleman II (T00271500)
    CSC 1310-001, Program Two
    File Contents: LinkedList Template Header file
*/

#ifndef LINKEDLIST_H
#define LINKEDLIT_H
#include <iostream>

using namespace std;

template<typename A>
class LinkedList{

private:
        struct ListNode{
        A value; 
        struct ListNode *next;
    };

    ListNode* head;
    ListNode* tail;
    int numNodes;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        numNodes = 0;
    } //constructor

    ~LinkedList(){
        ListNode* temp;
        ListNode* nextN;

        temp = head;

        while(temp != NULL){
            nextN = temp->nxtNode;
            delete temp;
            temp = nextN;
        }
    }; //deconstructor

    //program operation protypes
    int getLength(A);
    A getNodeValue(int);
    void appendNode(A obj);
    void deleteNode(int);
    int getNumNodes();

};

template<typename A>
int getnumNodes(){
    return this->numNodes;
}

template<typename A> //done???
int LinkedList<A>::getLength(A){
    return numNodes; //should only be one line?

    /*ListNode* temp;

    temp = A;
    int CT = 0;

    while(temp != NULL){
        ++CT;
        temp = a->next;
    }

    return CT;
    */
}

template<typename A>//done??
A LinkedList<A>::getNodeValue(int pos){
    ListNode* temp = NULL;
    int CT = 0;

    temp = head;

    while(temp != NULL){
        if( CT == pos){
            return temp->value; //shows everything?
        }

        CT++;
    }
}

template<typename A>//done??
void LinkedList<A>::appendNode(A obj){
    ListNode* temp;
    ListNode* holder;
    int CT;
    
    temp = new ListNode;
    temp->value = obj;
    temp->next = NULL;

    if(head = NULL){
        head = temp;
        numNodes++;
    }
    else if(head != NULL){
        //tail = temp; //is that right?
        holder = head;
        
        while(holder->next != NULL){
            holder = holder->next;
        }//searches for the end of the list

        holder->next = temp;//assigns at the end of the list hopefully . . .
        numNodes++;
    }
}

template<typename A>//does this work??
void LinkedList<A>::deleteNode(int pos){
    ListNode* temp;
    ListNode* holder;
    int ct = 0;

    temp = head;

    while(temp != NULL){
        if(ct == pos){
            holder = temp;
            temp = temp->next;
            delete holder;
            
            cout << "Creature No." << ct << " has been deleted.\n" << endl;
            numNodes--;
            break;
        }

        temp = temp->next;
        ct++;
    }  
}

#endif
