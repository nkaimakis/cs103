#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Nick Kaimakis 02/08/16
kaimakis@usc.edu
broke simulates three people flipping coins in a monte
carlo situation until one goes broke.
*/
bool unfair_flip(double heads)
{
	double result = heads * 100000;
	if(rand() % 100000 <= result){ //heads including odds
		return 1;
	}
	else{
		return 0;
	}
}



int main()
{
	srand(time(0));  

	int coins, times;
	double odds_heads;
	cout << "Enter number of coins, fairness, and simulations" << endl;
	cin >> coins >> odds_heads >> times;
	

	bool flip [3];
	int player[3];
	/*define arrays where flip[] records the results for each players flips 
	and play[] keeps track of each player's remaining coins */


	int turns = 0;
	int sum = 0;
	
	for(int i = 0; i < times; i++){
		turns = 0;
		//resets turns to zero after being added to sum
		bool stop = 1;
		//used to end program when first player runs out of coins

		player[0] = coins, player[1] = coins, player[2] = coins;

		while(stop == 1){
			for(int c = 0; c < 3; c++){
				flip[c] = unfair_flip(odds_heads);
			} //records results of 3 flips with given odds
		
			if(flip[0] == flip[1] & flip[2] != flip[1]){
				player[2] = player[2] + 2;
				player[1]--;
				player[0]--;
			}
			else if(flip[1] == flip[2] & flip[0] != flip[2]){
				player[0] = player[0] + 2;
				player[1]--;
				player[2]--;
			}
			else if(flip[0] == flip[2] & flip[1] != flip[2]){
				player[1] = player[1] + 2;
				player[0]--;
				player[2]--;
			}	

			turns++;	

			if(player[1] == 0 ){
				stop = 0;
				sum = sum + turns;
			}
			else if(player[0] == 0){
				stop = 0;
				sum = sum + turns;
			}
			else if(player[2] == 0){
				stop = 0;
				sum = sum + turns;
			}
		}
	}

double average = sum / 1.0 / times;
cout << "Average: " << setprecision(5) << average << endl;

return 0;
}