/* 
maze.cpp

Author: Nick Kaimakis

Short description of this file:
Take maze text file and find shortest route to finish
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main() {
   int rows, cols;
   int result = 0;
   char** mymaze;
   
   mymaze = read_maze(&rows, &cols); // FILL THIS IN
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); 

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
      }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // delete all memory 
   // that read_maze allocated
   for(int i=0; i<rows; i++){
      delete [] mymaze[i];
   }
   delete [] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols){
   //initialize Location object
   Location temp, start, finish;
   int valid_start = 0; 
   int valid_finish = 0;

   bool** visited = new bool* [rows]; 
   //allocate char array for remembering visited

   for(int i=0; i< rows; i++){
      visited[i] = new bool [cols]; //allocate columns for 2D
   }
   for(int i=0; i<rows; i++){ //initilize bools to 0
      for(int j=0; j<cols; j++){
         visited[i][j] = 0;
      }
   }

   Location** predecessor = new Location* [rows]; 
   //allocate Location array to hold predecessors

   for(int i=0; i< rows; i++){
      predecessor[i] = new Location [cols]; //allocate columns for 2D
   }
   for(int i=0; i<rows; i++){ //initilize predecessors to (-1,-1)
      for(int j=0; j<cols; j++){
         predecessor[i][j].row = -1;
         predecessor[i][j].col = -1;
      }
   }


   for(temp.row = 0; temp.row < rows; temp.row++){

      for(temp.col = 0; temp.col < cols; temp.col++){
         if(maze[temp.row][temp.col] == 'S'){
            start = temp;
            valid_start++;
            visited[start.row][start.col] = 1;
            //mark start as visited
         }
         else if(maze[temp.row][temp.col] == 'F'){
            finish = temp;
            valid_finish++;
         }
      }
   }
   if(valid_finish != 1 || valid_start != 1){ 
   	   //delete memory
	   for(int i=0; i<rows; i++){
	      delete [] visited[i];
	      delete [] predecessor[i];
	   }
		delete [] visited;
		delete [] predecessor;
    	return -1; //pass back invalid maze
   }

   //initialize queue
   Queue q(rows*cols);

   //BFS happens below
   q.add_to_back(start);
   Location curr, n, w, e, s;
   bool path_found = 0;

   while(q.is_empty() != 1){
      
      curr = q.remove_from_front();
      if(curr.row == finish.row && curr.col == finish.col){
         //rewrite maze with path
         while(curr.row != start.row || curr.col != start.col){
            maze[curr.row][curr.col] = '*';
            curr = predecessor[curr.row][curr.col];
         }
         path_found = 1;
         break;
      }
      n = curr; w = curr; e = curr; s = curr;
      n.row--; w.col--; e.col++; s.row++;
      //set breadth sources

      //neighbor to north
      if(n.row == finish.row && n.col == finish.col){
         //check if finish, then rewrite maze with path
         predecessor[n.row][n.col] = curr;
         while(curr.row != start.row || curr.col != start.col){
            maze[curr.row][curr.col] = '*';
            curr = predecessor[curr.row][curr.col];
         }
         path_found = 1;
         break;
      }
      else if(n.row >= 0 && n.row < rows && visited[n.row][n.col] == 0){
         //check if path or wall
         if(maze[n.row][n.col] == '.'){
           q.add_to_back(n);
            //record predecessor
            predecessor[n.row][n.col] = curr;
         }
         visited[n.row][n.col] = 1;
      }

      //neighbor to west
      if(w.row == finish.row && w.col == finish.col){
         //rewrite maze with path
         predecessor[w.row][w.col] = curr;
         while(curr.row != start.row || curr.col != start.col){
            maze[curr.row][curr.col] = '*';
            curr = predecessor[curr.row][curr.col];
         }
         path_found = 1;
         break;
      }
      else if(w.col >= 0 && w.col < cols && visited[w.row][w.col] == 0){     
         //check if path or wall
         if(maze[w.row][w.col] == '.'){
           q.add_to_back(w);
            //record predecessor
            predecessor[w.row][w.col] = curr;
         }
         visited[w.row][w.col] = 1;
      }

      //neighbor to south
      if(s.row == finish.row && s.col == finish.col){
         //rewrite maze with path
         predecessor[s.row][s.col] = curr;
         while(curr.row != start.row || curr.col != start.col){
            maze[curr.row][curr.col] = '*';
            curr = predecessor[curr.row][curr.col];
         }
         path_found = 1;
         break;
      }
      else if(s.row >= 0 && s.row < rows && visited[s.row][s.col] == 0){
         //check if path or wall
         if(maze[s.row][s.col] == '.'){
           q.add_to_back(s);
            //record predecessor
            predecessor[s.row][s.col] = curr;
         }
         visited[s.row][s.col] = 1;
      }

      //neighbor to east
      if(e.row == finish.row && e.col == finish.col){
         //rewrite maze with path
         predecessor[e.row][e.col] = curr;
         while(curr.row != start.row || curr.col != start.col){
            maze[curr.row][curr.col] = '*';
            curr = predecessor[curr.row][curr.col];
         }
         path_found = 1;
         break;
      }
      else if(e.col >= 0 && e.col < cols && visited[e.row][e.col] == 0){
         //check if path or wall
         if(maze[e.row][e.col] == '.'){
           q.add_to_back(e);
            //record predecessor
            predecessor[e.row][e.col] = curr;
         }
         visited[e.row][e.col] = 1;
      }
   }



   //delete memory
   for(int i=0; i<rows; i++){
      delete [] visited[i];
      delete [] predecessor[i];
   }
   delete [] visited;
   delete [] predecessor;

   if(path_found) return 1;
   
   return 0;
}