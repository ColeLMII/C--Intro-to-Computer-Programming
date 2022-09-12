/*
    Name: Larenzle Coleman II (T00271500)
    Course: CSC 1310-001
    Assignment: Program 4
    Purpose: Holds AVLTree function definitions.
*/

#include "AVLTree.h"
#include <iostream>

using namespace std;

Professor* AVLTree::searchNode(string name){
   TreeNode *hold = root;

   while(hold){
       cout << hold->name << endl;
        if(name.compare(hold->name) == 0)
            return hold->prof;
        else if(name < hold->name){
            hold=hold->left;
        }
        else{
            hold=hold->right;
        }
   }
   cout << "\n Error . . .";
   cout << "\n***************************\n";
  
   return NULL;
}

void AVLTree::insertNode(string x, Professor* y){
    TreeNode* hold = NULL;
    hold = new TreeNode;
    hold->name = x;
    hold->prof = y;
    hold->left = hold->right = NULL;

    insert(root,hold);
}

void AVLTree::displayInOrder() const{
    displayInOrder(root);
}