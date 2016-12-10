#include <iostream>
#include <cmath>

using namespace std;

int main() {

int theta, star, counter;
double rad, slope;
bool block = false;

cout << "Enter an angle between 15 and 75 degrees" << endl;
cin >> theta;

//convert theta to radians
rad = ( (theta / 360.0) * 2 * M_PI);


//determine slope
slope = tan ( rad );




for(counter = 0; counter < 30; counter++){ 
   if(counter * slope >= 20 && counter * slope <= 30){ //create block using boolean
     for(int i = 0; i < 20; i++){
             cout << "*";
     }              
   } else {
      for(star = 0; star < counter * slope; star++){
          cout << "*";
      }
   }
      
   cout << endl;
}





return 0;
}

