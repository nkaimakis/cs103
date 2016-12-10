/**
 *  File: election.cpp
 *  Name: _____________
 *  Email: _____________@usc.edu
 *
 *  Description:
 *    Counts votes for Republic and Democratic candidates
 *    printing the total number of votes in the Dem and Rep party,
 *    the winner in each party and the percentage of 
 *    votes the winner received from all those who voted in that party
 *
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/* Convenience struct to group candidate info. Use if desired */
struct Candidate {
  std::string name;
  int votes;
};

/* Prototype for given printResults function         *
 *  You must use this function to print your results */
void printResults(int totalDemVotes, 
		  std::string demWinnerName, 
		  double demWinningPercent,
		  int totalRepVotes, 
		  std::string repWinnerName, 
		  double repWinningPercent);

// Add other prototypes here if you like


int main(int argc, char* argv[])
{
  if(argc < 2){
    cout << "Please provide an input file" << endl;
    return 1;
  }
  ifstream infile(argv[1]);
  stringstream ss;
  string dem = "Dem";
  string rep = "Rep";
  vector<string> demo;
  vector<string> repu;


  while(!infile.fail()){
    string myline;
    string temp_party;
    getline(infile, myline);
    myline.copy(temp_party, 4, 0);
    if(dem.compare(temp_party)){
      demo.push_back(myline);
    }
    //

  }


  return 0;
}


void printResults(int totalDemVotes, 
		  std::string demWinnerName, 
		  double demWinningPercent,
		  int totalRepVotes,
		  std::string repWinnerName, 
		  double repWinningPercent)
{

  cout << totalDemVotes << " Dem votes, won by: " << demWinnerName << " ";
  cout << setprecision(2) <<  demWinningPercent << endl;
  cout << totalRepVotes << " Rep votes, won by: " << repWinnerName << " ";
  cout << setprecision(2) <<  repWinningPercent << endl;
}
