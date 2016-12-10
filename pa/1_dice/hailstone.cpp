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
int length = 0;
int num;

cout << "Enter a positive number greater than one" << endl;
cin >> num;


while(num > 1){
   while(num % 2 == 1){
      num = (num * 3) + 1;
      cout << num << " ";
      length++;
   }
   while(num % 2 == 0){
      num = num / 2;
      cout << num << " ";
      length++;
   }
}
if(length == 0){ //invalid input
   cout << "Invalid input" << endl;  
   }
else{ //output length
   cout << "\n" << "Length: " << length << endl;
}


return 0;
}
