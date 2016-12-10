#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]){
	const char* filename = argv[1];

	ifstream infile;
	infile.open(filename);
	int votes;
	stringstream ss;
	ss << infile;
	ss >> votes;
	int repVotes=0;
	int demVotes=0;
	char r[] = "Rep";
	char d[] = "Dem";
	//vectors hold names
	vector<string> repNames;
	vector<string> demNames;

//
while(!infile.fail()){l
	char party[100];
	char n[100];
	stringstream temp;
	stringstream names;
	temp << infile;
	temp >> party;

	if(strcmp(r, party)){
		repVotes++;
		names << infile;
		n << names;
		//adds name to vector to count later
		repNames.push_back(n);
	}
	else if(strcmp(d, party)){
		demVotes++;
		names << infile;
		n<< names;
		//adds name to vector to count later
		demNames.push_back(n);
	}
}
//add code to count names in each vect for winners

// add code to calculate percentage of votes

	

	infile.close();
	//change cout statements to print calculated winners and percents
	cout<< demVotes << " Dem votes, won by:";
	cout<< repVotes << " Rep votes, won by:";

	return 0;
}
