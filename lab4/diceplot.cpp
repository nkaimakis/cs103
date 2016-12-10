#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Nick Kaimakis 01/31/16
kaimakis@usc.edu
diceplot graphs an inputted amount of random rolls.
*/

#define DICE 4
#define SIDES 6

int roll()
{
	return ((rand() % SIDES) + 1);
}

void printHistogram(int counts[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << (i + DICE) << ": ";	

		for(int j = 0; j < counts[i]; j++)
		{
			cout << "X";
		}
		cout << endl;
	}
	//return;
}

int main()
{
	srand(time(0));
	int n;
	cout << "How many times should I roll my set of " << DICE << " dice with " << SIDES << " sides?" << endl;
	cin >> n;
	int counts[(DICE * (SIDES - 1) + 1)] = {};
	int sum_roll;

	for(int i = 0; i < n; i++)
	{			
		sum_roll = 0;

		for(int j = 0; j < DICE; j++)
		{
			sum_roll = sum_roll + roll();
		}
		counts[sum_roll - DICE]++;
	}
	int length = (DICE * (SIDES - 1) + 1);
	printHistogram(counts, length);
	return 0;
}
	