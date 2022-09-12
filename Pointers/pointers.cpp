#include <iostream>
using namespace std;

int main()
{

    cout << "Pointer Basics >:l" << endl;
    int x = 25; // declares x as 25
    int *ptr; // defines a pointer

    cout << "The memory address of x is: " << &x << "." << endl; // shows memory address of int x
    cout << "The memory address in ptr is (" << ptr << ") before being assigned." << endl; //point to the current memory address inside the pointer "ptr"
    ptr = &x; // changes the address of ptr to the address of the x variable

    cout << "Now the memory address inside of the pointer is (" << ptr << ") !" << endl; // shows the update address inside ptr
    cout << *ptr << endl; //shows what is inside that memory address
    cout << "Shuting Down . . . " << endl; // basic message

 return 0; // terminates program
};
