/*
    Name: Larenzle Coleman II (T00271500)
    Course: CSC 1310-001
    Assignment: Program 4
    Purpose: AVLTree Header File, class declaraction
*/

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "Professor.h"
#include <iomanip>

using namespace std;

class AVLTree{
private:
    struct TreeNode{
        string name;
        Professor* prof;
        TreeNode* left;
        TreeNode* right;

        string getName(){
            return this->name;
        }
        Professor* getProf(){
            return this->prof;
        }
    };

TreeNode* root;
   
void insert(TreeNode*& parent,TreeNode*& child){//done
    if(parent == NULL){
        parent = child; // sets the root node.
    }
    else if( child->name < parent->name){
        insert(parent->left, child);
    }
    else{
        insert(parent->right, child);
    }

    balance(this->root);
}

void destroySubTree(TreeNode* mise){//done
    if(mise){
        if(mise->right){destroySubTree(mise->right);}
        if(mise->left){destroySubTree(mise->left);}

        delete mise;
    }
}

void displayInOrder(TreeNode* go) const{//done?
    if(go){
        displayInOrder(go->left);
        cout << "-->   " << go->getName() << endl;
        displayInOrder(go->right);
    }
}

int height(TreeNode*& nodePtr){ //done (returns the nodes height)
    int h = 0;

    if(nodePtr != NULL){
        int left = height(nodePtr->left);
        int right = height(nodePtr->right);
        h = max(left,right) + 1;
    }

    return h;
}

int diff(TreeNode*& nodePtr){ //returns the difference in height between two subtrees
    int lsub;
    lsub = height(nodePtr->left);
    int rsub;
    rsub = height(nodePtr->right);
    int bFactor;
        bFactor = lsub - rsub;
    return bFactor;
}

void balance(TreeNode*& nodePtr){//done
int bFac;
    if( nodePtr != NULL){
        bFac = diff(nodePtr); 
        
        if(bFac < -1){//the lefts
            if( diff(nodePtr->right) > 0){ //(-2,1)right-left rot.
                nodePtr = rl_rotation(nodePtr);
                    //cout << "\nRight-Left  . . .\n";
            }
            else{
                nodePtr = l_rotation(nodePtr);
                    //cout << "\nLeft . . .\n";
            }
            balance(nodePtr->right);
        }

        else if(bFac > 1){
            if(diff(nodePtr->left) > 0){
                nodePtr = r_rotation(nodePtr);
                //cout << "\nRight . . .\n";
            }
            else{
                nodePtr = lr_rotation(nodePtr);
                //cout << "\nLeft-Right . . .\n";
            }
            balance(nodePtr->left);
        }
        balance(nodePtr->left);
        balance(nodePtr->right);
        
    }
}

//twist and turns :O . . .
TreeNode* l_rotation(TreeNode*& parent){
    TreeNode* hold;
    hold = parent->right;
    parent->right = hold->left;
    hold->left = parent;

    return hold;
}

TreeNode* r_rotation(TreeNode*& parent){
    TreeNode* hold;
    hold = parent->left;
    parent->left = hold->right;
    hold->right = parent;

    return hold;
}

TreeNode* lr_rotation(TreeNode*& parent){
    TreeNode* hold;
    hold = parent->left;

    parent->left = l_rotation(hold);

    return r_rotation(parent);
}

TreeNode* rl_rotation(TreeNode*& parent){
    TreeNode* hold;
    hold = parent->right;
    parent->right = r_rotation(hold);

    return l_rotation(parent);
}


public:
    AVLTree(){
        root = NULL;
    }

    ~AVLTree(){
        destroySubTree(root);
    }

    Professor* searchNode(string search);

    TreeNode* getRoot(){
        return root;
    }

    void insertNode(string x, Professor* y);

    void displayInOrder() const;

};

#endif