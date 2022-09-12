#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
	Text* name = new Text;
	name->createText("what the fuck");
	cout << "here";
	name->getText(name);
	cout << endl;
	name -> deleteText(name);


	return 0;
}