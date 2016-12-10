#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int x, int y, int height, int width) {
   //changes width to stop after hitting pixel 255
   if(x + width > 255){ 
      width = 255 - x;
   }
   //adjusts drawing if x is negative
   if(x < 0){ 
      width = width + x;
      x = 0;
   }
   //changes height to stop after hitting pixel 255
   if(y + height > 255){ 
      height = 255 - y;
   }
   //adjusts drawing if y is negative
   if(y < 0){ 
      height = height + y;
      y = 0;
   }
   //prints remaining valid image
   for(int w = 0; w < width; w++){
      for(int h = 0; h < height; h++){
         image[y][x + w] = 0;
         image[y + h][x] = 0;         
         image[y + height][x + w] = 0;
         image[y + h][x + width] = 0;
      }
   }
}

// Fill in this function:
void draw_ellipse(int cx, int cy, int height, int width) {

   for(double theta = 0; theta < 2 * M_PI; theta = theta + 0.01){         
      int w = cx + (width / 2) * cos(theta);
      int h = cy + (height / 2) * sin(theta);

      //only change pixel if valid pixel, avoids crashing program outside bounds
      if(w >= 0 & w <= 255){ 
         if(h >= 0 & w <= 255){
            image[h][w] = 0;
         }
      }
   }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   

bool i = true; //bool to end infinite loop

while(i == true){
   int choice, x, y, height, width;
   cout << "Enter 0 for rectangle, 1 for ellipse, 2 to quit" << endl;
   cin >> choice;
   if(choice == 2){
      i = false;
   }
   else if(choice == 1){
      cout << "To draw an ellipse, enter initial point x y followed by height width" << endl;
      cin >> x >> y >> height >> width;
      draw_ellipse(x, y, height, width);
   }
   else if(choice == 0){
      cout << "To draw a rectangle, enter center point x y followed by height width" << endl;
      cin >> x >> y >> height >> width;
      draw_rectangle(x, y, height, width); 
   }
   else{
      cout << "Invalid input" << endl; //if user enters input other that 0,1,2
   }

      
      // Write the resulting image to the .bmp file
      writeGSBMP("output.bmp", image);
      showGSBMP(image);
}

return 0;
}
