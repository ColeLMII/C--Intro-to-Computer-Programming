/*
	Title:  Text.cpp
	Author:  Mark Boshart, modified by April Crockett, modifided by Larenzle Coleman II
	Date:  11/7/2017, 09/25/2020
	About:  A structure version of the C++ string class
*/

#include "Text.h"
#include <iostream>

using namespace std;

// create text contructor
Text::Text(){
	
	textLength = getLength(textArray);
	textArray = nullptr; //not complete yet***
}

//edit function
Text* Text::editText(Text* old, const char* text){
	delete old->textArray;
	char* tempTextArray = new char[(old->textLength)+1];
	memcpy(old->textArray, text, old->textLength);
	return this->textArray;
}

Text* Text::createText(const char* text)
{
	//dynamically allocate a new Text
	Text* myText = new Text; 
	
	//get the length of the string passed to this function
	myText->textLength = strlen(text);
	
	//dynamically allocate a new character array
	//the line below wont work because I need textArray to be const but I can't dynamically allocate a const char array 
	//myText->textArray = new char[(myText->textLength)+1];
	char* tempTextArray = new char[(myText->textLength)+1];
	
	/*
		Now put text inside of tempTextArray
		I can either use the cstring function called strcpy OR
		I could have created a for loop and copy one character at a time.
	*/
	strcpy(tempTextArray, text); 

	//put the text sent to this function into the newly created array
	//I can do assignment because it is assigning a pointer (not a cstring)
	myText->textArray = tempTextArray;	
	
	return myText;
}

// text decontructor
void Text::deleteText(Text *ptr)
{
	delete ptr;
}

/*void Text::destroyText(Text* myText)
{
	//create a temporary c-string to make the syntax easier to delete the array
	const char* tempTextArray = myText->textArray;
	//delete the character array (c-string), which is inside the structure
	delete [] tempTextArray;
	//delete the entire structure
	delete myText;
}

void Text::displayText(Text* myText)
{
	//print out the c-string
	cout << myText->textArray;
}*/

Text* Text::getText(Text* myText)
{
	return this->textArray;
}

int Text::getLength(Text* myText)
{
	return myText->textLength;
}