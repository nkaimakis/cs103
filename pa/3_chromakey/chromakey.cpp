/*********************************************************************
 File:     chromakey.cpp

 Author:   Nick Kaimakis

 Email address: kaimakis@usc.edu

 Usage: program_name in.bmp background.bmp dist_threshold out1.bmp out2.bmp

 Notes:
 This program performs the chroma key operation on an input 
 using two different methods.

 Method 1 Utilize a user-defined distance threshold from the
          chromakey value as a discriminator

 Method 2 Devise a method that to determine the chromakey mask
          that doesn't require a user-input threshold

********************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Prototypes
// IMPORTANT: you must exactly use these input types, function names, and 
// return types. Otherwise the grader can't test them.
void method1(unsigned char inImage[][SIZE][RGB], 
	bool mask[][SIZE], double threshold);

void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE]);

void replace(bool mask[][SIZE],
	     unsigned char inImage[][SIZE][RGB],
	     unsigned char bgImage[][SIZE][RGB],
	     unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{
  // Image data array
  // Note:  DON'T use the static keyword except where we expressly say so.
  //        It puts the large array in a separate, fixed, area of memory. 
  //        It is bad practice. But useful until we have dynamic allocation.
  static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
    cerr << "usage: program_name in.bmp background.bmp dist_threshold " 
         << "out1.bmp out2.bmp" << endl;
    return 0;
  }
	
  if (readRGBBMP(argv[1], inputImage)) {
    cerr << "Error reading file: " << argv[1] << endl;
    return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }
  
  // Write code to convert the threshold (argv[3])
  //  from string format to a double and assign the 'threshold'
  threshold = atof(argv[3]);

  // Call Method 1 Function
  method1(inputImage, chromaMask, threshold);

  // Produce the output by calling replace()
  replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[4]
  if (writeRGBBMP(argv[4], outputImage)) { //if return value != 0, exit
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }	


  // Call Method 2 Function
  method2(inputImage, chromaMask);

  // Produce the output by calling replace()
  replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5], outputImage)) { //if return value != 0, exit
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }



  return 0;
}



// Use user-provided threshold for chroma-key distance
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method1(unsigned char inImage[][SIZE][RGB], 
    bool mask[][SIZE],
	  double threshold){
  double avgred = 0, avggreen = 0, avgblue = 0;
  for(int row = 0; row < 20; row++){
    for(int column = 0; column < SIZE; column++){
      avgred += inImage[row][column][0];
      avggreen += inImage[row][column][1];
      avgblue += inImage[row][column][2];
    }
  }
  avgred = avgred/20/SIZE;
  avggreen = avggreen/20/SIZE;
  avgblue = avgblue/20/SIZE;

  double temp_dist = 0;
  for(int row = 0; row < SIZE; row++){
    for(int column = 0; column < SIZE; column++){ 
      //determine distance to compare with threshold
      temp_dist = sqrt( pow((inImage[row][column][0] - avgred),2) + 
        pow((inImage[row][column][1] - avggreen),2) +
        pow((inImage[row][column][2] - avgblue),2) ); 

      if(temp_dist <= threshold){ //change mask for pixels within threshold
        mask[row][column] = 1;
      }
    }
  }
}

// Devise a method to automatically come up with a threshold
//  for the chroma key determination
// The "output" of this method is to produce a valid mask array
//  where entries in the mask array are 1 for foreground image
//  and 0 for 'background'
void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE])  
{
  double avgred = 0, avggreen = 0, avgblue = 0;
  for(int row = 0; row < 40; row++){
    for(int column = 0; column < 40; column++){ //avg greenscreen value
      avgred += inImage[row][column][0] + inImage[SIZE-row][SIZE-column][0];
      avggreen += inImage[row][column][1] + inImage[SIZE-row][SIZE-column][1];
      avgblue += inImage[row][column][2] + inImage[SIZE-row][SIZE-column][2];
    }
  }
  avgred = avgred/3200;
  avggreen = avggreen/3200;
  avgblue = avgblue/3200;

  double temp_dist = 0;
  double avg_dist = 0;

  for(int row = 0; row < SIZE; row++){
    for(int column = 0; column < SIZE; column++){ 
      //distance from average green corners
      temp_dist = sqrt( pow((inImage[row][column][0] - avgred),2) + 
        pow((inImage[row][column][1] - avggreen),2) +
        pow((inImage[row][column][2] - avgblue),2) ); 
      avg_dist += temp_dist;
    }
   }
   avg_dist = avg_dist/SIZE/SIZE;
   //average distance from green screen 3200 corner pixels average

    for(int row = 0; row < SIZE; row++){
      for(int column = 0; column < SIZE; column++){ 
        //determine distance to compare with threshold
        temp_dist = sqrt( pow((inImage[row][column][0] - avgred),2) + 
          pow((inImage[row][column][1] - avggreen),2) +
          pow((inImage[row][column][2] - avgblue),2) ); 

        mask[row][column] = 0; //reset mask

        if(temp_dist <= avg_dist){
         //change mask for pixels within determined threshold
          mask[row][column] = 1;
        }
      }
    }

  }

// If mask[i][j] = 1 use the input image pixel for the output image
// Else if mask[i][j] = 0 use the background image pixel
void replace(bool mask[SIZE][SIZE],
	     unsigned char inImage[SIZE][SIZE][RGB],
	     unsigned char bgImage[SIZE][SIZE][RGB],
	     unsigned char outImage[SIZE][SIZE][RGB])
{
  // Create the output image using the mask to determine
  //  whether to use the pixel from the Input or Background image
  for(int row = 0; row < SIZE; row++){
    for(int column = 0; column < SIZE; column++){
      if(mask[row][column]){
        for(int color=0; color<3; color++){
          outImage[row][column][color] = bgImage[row][column][color];
        }
      }
      else{
        for(int color=0; color<3; color++){
          outImage[row][column][color] = inImage[row][column][color];
        }
      }
    }
  }
}
