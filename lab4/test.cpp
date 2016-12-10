#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
Nick Kaimakis 01/31/16
kaimakis@usc.edu
hailstats program calculates how many steps it takes
to get a number to 1.
*/
void printHistogram(int counts[]){
	for(int i = 0; i < 21; i++){
		cout << (i + 4) << ": ";	
		for(int j = 0; j < counts[i]; j++){
			cout << "X";
		}
		cout << endl;
	}
	return;
}

int main(){
	int testCounts[21];
	for(int i = 0; i < 21; i++){
		testCounts[i] = i / 2;
	}
	printHistogram(testCounts);
	return 0;
}