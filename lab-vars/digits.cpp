#include <iostream>

using namespace std;

int main()
{
//define variables
int number, ones, tens, hunds;

//prompt user and receive input
cout << "Enter a digit between 0 and 999" << endl;
cin >> number; //end this line?

//calculations
hunds = number - (number % 100);
tens = (number % 100) - (number % 10);
ones = (number % 10);

//display output
cout << "1's digit is: " << ones << endl << "10's digit is: " << (tens / 10) << endl << "100's digit is: " << (hunds / 100) << endl;


return 0;
}
