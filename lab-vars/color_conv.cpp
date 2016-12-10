#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  //define variables
  double red, green, blue;
  double white, cyan, magenta, yellow, black;
  
  //prompt user
  cout << "Input red, green, and blue in order, separated by a space" << endl;
  
  //take input
  cin >> red >> green >> blue;
  
  //calculations
  if (red > green && red > blue)
  { 
  white = red/255;
  }
  else if ( green > red && green > blue )
  {
  white = green/255;
  }
  else
  {
  white = blue/255;
  }
  //set white to highest value
  
  cyan = ( white - (red/255)) / white;
  magenta = ( white - (green/255)) / white;
  yellow = ( white - (blue/255)) / white;
  black = 1 - white;
  
  
  //output values
  cout << "cyan= " << cyan << endl << "magenta= " << magenta << endl << "yellow= " << yellow << endl << "black= " << black << endl;
   
   
   return 0;
}
