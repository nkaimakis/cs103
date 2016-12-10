/* 
mazeio.cpp

Author:Nick Kaimakis

Short description of this file:
Reads maze from cin, allocates and returns
a 2D array for the maze.
*/

#include <iostream>
#include <cstring>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from cin into a dynamically allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * such as integers for the size not found.
 *
 * We also pass in two pointers to integers. Fill 
 * the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(int* rows, int* cols) {
   // FILL THIS IN
	int r, c;
	cin >> r >> c; //grab number of rows and columns
	*rows = r;
	*cols = c;

	char** og_maze = new char* [r]; 
	//allocate char array for maze rows

	for(int i=0; i< r; i++){
		og_maze[i] = new char [c]; //allocate columns for 2D
	}

	for(int i=0; i<r; i++){
		string current_row;
		cin >> current_row;
		for(int j=0; j<c; j++){
			og_maze[i][j] = current_row[j];
		}
	}

	return og_maze;
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) {
   // FILL THIS IN
	cout << rows << " " << cols <<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
}

