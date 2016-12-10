#include <iostream>
using namespace std;
/*
Nick Kaimakis 01/31/16
kaimakis@usc.edu
hailstats program calculates how many steps it takes
to get a number to 1.
*/


int main()
{

int counter, first, last, num, length, maxlength, minlength, maxnum, minnum;

cout << "Enter the range you want to search: ";
cin >> first >> last;

if(first > last){
	cout << "Invalid range" << endl;
}	
else{
	for(counter = first; counter <= last; counter++){
		num = counter;	//new variable so that we can use counter later
		length = 0;		//resetting length of value to zero
	
		//hailstone loop
		while(num > 1){ 	
	    	if(num % 2 == 1){
	        	num = (num * 3) + 1;
	    	}
	    	else{
				num = num / 2;
			}
		length++;
		}

		//set initial values
		if(counter == first){ 	
			maxlength = length;
			minlength = length;
		}
	
		//evaluate and reassign maximums and minimums
		if(maxlength < length){ 
			maxlength = length;
			maxnum = counter;
		}
		if(minlength > length){
			minlength = length;
			minnum = counter;
		}
	}

cout << "Minimum length: " << minlength << "\n" << "Achieved by: " << minnum << endl;
cout << "Maximum length: " << maxlength << "\n" << "Achieved by: " << maxnum << endl;
}






return 0;
}
