#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

int main() {
   unsigned char image[SIZE][SIZE];

   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }

   for(int i = 0; i < SIZE; i++){
      image[255 - i][i] = 0;
   }
   
   // at end, display complete image
   showGSBMP(image);
   
   // save to file
   writeGSBMP("cross.bmp", image);
   return 0;
}
