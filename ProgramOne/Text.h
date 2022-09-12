/*
	Title:  Text.h
	Author:  Mark Boshart, modified by April Crockett , modified by Larenzle Coleman II (t00271500)
	Date:  11/7/2017, modified 09/24/2020
	About:  A structure version of the C++ string class
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Text{		
public:
	Text();
	Text* textArray;
	int textLength;

	Text* editText(Text*,const char*);
	/*
	Function Name:  createText()
	Parameters:  Send a pointer to a constant character array or a string literal to this function
	Returns:  A pointer to a new Text variable, which contains the c-string & the length of the string
	Purpose:  To create a new Text variable
	
	//Text* createText(const char*);
	Function Name:  destroyText()
	Parameters:  Send a pointer to a Text variable, which contains a c-string & length of the string
	Returns:  nothing (void)
	Purpose:  release dynamically allocated memory that the pointer is pointing to.
	void destroyText(Text*);
	*/
	Text* createText(const char*);	
	
	void deleteText(Text *ptr);
	/*
	Function Name:  displayText()
	Parameters:  Send a pointer to a Text variable, which contains a c-string & length of the string
	Returns:  nothing (void)
	Purpose:  prints out the string (character array)
	*/
	//void displayText(Text*);
	/*
	Function Name:  getText()
	Parameters:  Send a pointer to a Text variable, which contains a c-string & length of the string
	Returns:  pointer to a constant character array
	*/
	Text* getText(Text*);
	/*
	Function Name:  getLength()
	Parameters:  Send a pointer to a Text variable, which contains a c-string & length of the string
	Returns:  the length of the string 
	*/
	int getLength(Text*);

private:

};

#endif