#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

int main() {
   unsigned char image[SIZE][SIZE];

   for (int i=0; i <= SIZE; i++) {
      for (int j=0; j <= 255 - i; j++) {
         image[i][j] = floor((i + j));
         image[255 - i][255 - j] = floor(i+j);
      }
   }

 

   
   // at end, display complete image
   showGSBMP(image);
   
   // save to file
   writeGSBMP("cross.bmp", image);
   return 0;
}
