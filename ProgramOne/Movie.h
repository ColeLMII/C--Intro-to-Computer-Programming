/*
	Title:  Movie.h
	Author:  April Crockett, modified by Larenzle Coleman II
	Date:  11/7/2017, 09/24/2020
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Movie{

public:
	Movie(); //constructor
	Text* movieTitle;  //title of movie
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
	Text* movieRating; //G, PG, PG-13, R, MA
	int movieOscars; //number of oscars won
	float movieNumStars; //taken from IMDB on 10 star scale

//was only public before, below
	void destroyMovie(Movie* movie); // deconstructor		
	/*
	Function name:  createMovie (overloaded function)
	Parameters:  	1) A pointer to a Text variable, containing a c-string and the length of the string.
					2) An integer containing the length of the movie
	Returns: 		A pointer to a new Movie structure
	Purpose:  		This function should be called when only the title of the movie and the length of
					the movie is known and it will create a new movie with this information.

	//Movie* createMovie(Text*, int); */
	/*
		Function name:  createMovie (overloaded function)
		Parameters:  	1) A pointer to a Text variable, containing the title of the movie
						2) An integer containing the length of the movie
						3) An integer containing the year the movie was released
						4) A pointer to a Text variable, containing the genre of the movie
						5) A pointer to a Text variable, containing the rating of the movie
						6) An integer containing the number of oscars the movie won
						7) A float containing the IMDB rating of the movie (out of 10 stars)
		Returns: 		A pointer to a new Movie structure
		Purpose:  		This function should be called when all movie information is known and 
						it will create a new movie with this information.
	*/
	Movie* setMovie(Text*, int, int, Text*, Text*, int, float); 
	/*
		Function name:  editMovie 
		Parameters:  	A pointer to a movie structure
		Returns: 		nothing (void)
		Purpose:  		This function should be called when the user wants to edit a single
						movie's data
	*/
	void editMovie(Movie* myMovie);
	/*
		Function name:  destroyMovie 
		Parameters:  	A pointer to a movie structure
		Returns: 		nothing (void)
		Purpose:  		This function should be called when there is no longer need for the
						movie in the database (like when removing or deleting a movie).
	void destroyMovie(Movie*);


		Function name:  printMovieDetails 
		Parameters:  	A pointer to a movie structure
		Returns: 		nothing (void)
		Purpose:  		This function should be called when the user wants to print ALL
						the movie information to the screen.
	*/
	void getMovieDetails(Movie*);
	/*
		Function name:  printMovieDetailsToFile 
		Parameters:  	A pointer to a movie structure, a file stream object (sent by reference)
		Returns: 		nothing (void)
		Purpose:  		This function should be called when the user wants to print ALL
						the movie information to the file.
	*/
	void printMovieDetailsToFile(Movie* myMovie, ofstream &outFile);

	Text* getMovieTitle(Movie*); //accessor
	int getMovieLength(Movie*); //accessor
	int getMovieYear(Movie*); //accessor
	Text* getMovieGenre(Movie*); //accessor
	Text* getMovieRating(Movie*); //accessor
	int getMovieOscar(Movie*); //accessor
	float getMovieNumStars(Movie*); //accessor
	void setMovieTitle(Movie*); // mutator
	void setMovieLength(Movie*); //mutator
	void setMovieYear(Movie*); //mutator
	void setMovieGenre(Movie*); //mutator
	void setMovieRating(Movie*); //mutator
	void setMovieOscar(Movie*); //mutator
	void setMovieNumstars(Movie*); //mutator

private:
	

};

#endif