/*
	Title:  Movie.cpp
	Author:  April Crockett, modified by: Larenzle Coleman II
	Date:  11/7/2017, 09/24/2020
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"

Movie::Movie() //movie contructor
{
	movieTitle = nullptr;  //title of movie
	movieLength = 0; //length of movie in minutes
	movieYear= 0000; //year released
	movieGenre = nullptr; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
	movieRating = nullptr; //G, PG, PG-13, R, MA
	movieOscars = 0; //number of oscars won
	movieNumStars = 0.0;
}
/*
Movie* createMovie(Text* title, int length)
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure memebers
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	
	return myMovie;
}*/

Movie* setMovie(Text* title, int length, int year, Text* genre, Text* rating, int nom, float stars) //all info is know // mutator now !!
{
	//dynamically allocate a new Movie
	Movie* myMovie = new Movie;
	
	//assign parameter data to structure members
	myMovie->movieTitle = title;
	myMovie->movieLength = length;
	myMovie->movieYear = year;
	myMovie->movieGenre = genre;
	myMovie->movieRating = rating;
	myMovie->movieOscars = nom;
	myMovie->movieNumStars = stars;
	
	return myMovie;
}

void Movie::destroyMovie(Movie* movie) //movie deconstructor
{
	
	delete movie->movieTitle;
	delete movie->movieGenre;
	delete movie->movieRating;
	delete movie;
}
/*
void destroyMovie(Movie* myMovie)
{
	destroyText(myMovie->movieTitle);
	destroyText(myMovie->movieGenre);
	destroyText(myMovie->movieRating);
	delete myMovie;
}*/

void Movie::getMovieDetails(Movie* myMovie) //accessor
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	myMovie->movieTitle;
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << myMovie->movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << myMovie->movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	myMovie->movieGenre;
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	myMovie->movieRating;
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << myMovie->movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << myMovie->movieNumStars << endl << endl;
}

void printMovieDetailsToFile(Movie* myMovie, ofstream &outFile) //accessor
{
	char temp[1000];
	memcpy(temp, (myMovie->movieTitle)->getText(myMovie->movieTitle), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieLength << endl;
	outFile << myMovie->movieYear << endl;
	memcpy(temp, (myMovie->movieGenre)->getText(myMovie->movieGenre), 1000);
	outFile << temp << endl;
	memcpy(temp, (myMovie->movieRating)->getText(myMovie->movieRating), 1000);
	outFile << temp << endl;
	outFile << myMovie->movieOscars << endl;
	outFile << myMovie->movieNumStars << endl;
}

void editMovie(Movie* myMovie) //mutator
{
	int choice;
	Text* tempText;
	char temp[100];
	
	do
	{
		cout << "\n\nWhich detail do you wish to edit?\n";
		cout << "1.  Title\n";
		cout << "2.  Length\n";
		cout << "3.  Year\n";
		cout << "4.  Genre\n";
		cout << "5.  Rating\n";
		cout << "6.  Number of Oscars Won\n";
		cout << "7.  Number of Stars\n";
		cout << "8.  DONE EDITING\n";
		cout << "CHOOSE 1-8:  ";
		cin >> choice;
		while(choice < 1 || choice > 8)
		{
			cout << "\nOOPS!  Enter choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore();
		
		switch(choice)
		{
			case 1: cout << "\nCurrent Title: ";
					tempText->getText(myMovie->movieTitle);
					tempText->deleteText(myMovie->movieTitle);
					cout << "\nNEW TITLE:  ";
					cin.getline(temp, 100);
					tempText = tempText->createText(temp);
					myMovie->movieTitle = tempText;
					break;
			
			case 2:	cout << "\nCurrent Length: " << myMovie->movieLength;
					cout << "\nNEW LENGTH:  ";
					cin >> myMovie->movieLength;
					break;
					
			case 3: cout << "\nCurrent Year: " << myMovie->movieYear;
					cout << "\nNEW LENGTH:  ";
					cin >> myMovie->movieYear;
					break;
					
			case 4:	cout << "\nCurrent Genre: ";
					tempText->getText(myMovie->movieGenre);
					tempText->deleteText(myMovie->movieGenre);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = tempText->createText(temp);
					myMovie->movieGenre = tempText;
					break;
					
			case 5: cout << "\nCurrent Rating: ";
					tempText->getText(myMovie->movieRating);
					tempText->deleteText(myMovie->movieRating);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = tempText->createText(temp);
					myMovie->movieRating = tempText;
					break;
			
			case 6: cout << "\nCurrent Number of Oscars Won: " << myMovie->movieOscars;
					cout << "\nNEW NUMBER OF OSCARS:  ";
					cin >> myMovie->movieOscars;
					break;
					
			case 7:	cout << "\nCurrent Star Rating from IMDB: " << myMovie->movieNumStars;
					cout << "\nNEW STAR RATING:  ";
					cin >> myMovie->movieNumStars;
					break;
		}
	}while(choice != 8);
}

Text* getMovieTitle(Movie* myMovie) //accessor
{
	return myMovie->movieTitle;
}

int getMovieLength(Movie* myMovie) //accessor
{
	return myMovie->movieLength;
}

int getMovieYear(Movie* myMovie) //accessor
{
	return myMovie->movieYear;
}

Text* getMovieGenre(Movie* myMovie) //accessor
{
	return myMovie->movieGenre;
}

Text* getMovieRating(Movie* myMovie) //accessor
{
	return myMovie->movieRating;
}

int getMovieOscars(Movie* myMovie) //accessor
{
	return myMovie->movieOscars;
}

float getMovieNumStars(Movie* myMovie) //accessor
{
	return myMovie->movieNumStars;
}

void setMovieTitle(Movie* myMovie, Text* title) //mutator
{
	myMovie->movieTitle = title;
}

void setMovieLength(Movie* myMovie, int length) // mutator
{
	myMovie->movieLength = length;
}

void setMovieYear(Movie* myMovie, int year) //mutator
{
	myMovie->movieYear = year;
}

void setMovieGenre(Movie* myMovie, Text* genre) //mutator
{
	myMovie->movieGenre = genre;
}

void setMovieRating(Movie* myMovie, Text* rating) //mutator
{
	myMovie->movieRating = rating;
}

void setMovieOscars(Movie* myMovie, int oscars) //mutator
{
	myMovie->movieOscars = oscars;
}

void setMovieNumStars(Movie* myMovie, float stars) //mutator
{
	myMovie->movieNumStars = stars;
}
