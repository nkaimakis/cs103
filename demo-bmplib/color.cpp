#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

int main() {
   unsigned char image[SIZE][SIZE][3];

   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         if(j < SIZE/4){
        	 image[i][j][0] = 255; //red
        	 image[i][j][1] = 0; //green
        	 image[i][j][2] = 0; //blue
    	}
    	else if(j < SIZE/2){
    		image[i][j][0] = 0; //red
        	image[i][j][1] = 255; //green
        	image[i][j][2] = 0; //blue
    	}
    	else if(j < 3*SIZE/4){
    		image[i][j][0] = 0; //red
        	image[i][j][1] = 0; //green
        	image[i][j][2] = 255; //blue
        }
        	else{
        	image[i][j][0] = 255; //red
        	image[i][j][1] = 255; //green
        	image[i][j][2] = 255; //blue
        	}
    	
      }
   }

 

   
   // at end, display complete image
   showRGBBMP(image);
   
   // save to file
   writeRGBBMP("cross.bmp", image);
   return 0;
}
