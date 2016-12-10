CSCI 103 Programming Assignment 2, Chroma Key, Fall 2014

Name: Nick Kaimakis

Email Address: kaimakis@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

Pixel                |    RGB Value     |  Distance from Chroma Key
-------------------------------------------------------------------
Top-left background  | ( 69, 138, 19)  |  n/a
Arm                  | ( 252, 157, 113)  | 206.606
Vest                 | ( 28, 32, 31)  | 114.28
Shirt                | ( 246, 212, 247)  | 297.975

================================== Review ===================================
1. Discuss and justify which pixels you chose to compute the average 
background value for method 1. Was there a reason not to choose more or
fewer pixels?

Response 1: I decided to use the first twenty rows all the way to
column 255 because the light of the pixels contrasted the most
across rows rather than columns, and this produced the best average
for distance. I first tried using a 40x40 pixel box in the top
left corner. I also tried using the first 50 columns, but using the
first 20 rows gave the best result.

2. For method 1, do some experiments to find the range of distance thresholds 
for which the program seems to operate the best. You may use different 
thresholds for the two different sample images (Colbert and Bird). 
Note: threshold values that are too low will cause certain portions of the 
chroma key to stay in the picture; values that are too high will cause parts 
of the foreground image to disappear.

Response 2:

  Image                  Min Threshold           Max Threshold
  Colbert range:  from       60            to  90
  Bird range:     from       3            to  95


3. For method 2, explain what you implemented and why.  How did you go about 
implementing it? Walk us through a high-level description of what you did in 
your code (and use comments in the actual .cpp file to fill in the details). 
What other alternatives did you consider either before or after you
implemented your selected method?  What are the relative pros and cons of 
these methods? [This question is open-ended!]

Response 3:
For method 2, I calculated average values of the rgb pixels that one can
assume is part of the greenscreen. I used this average to determine the
average distance of pixels from these greenscreen averages. I then used
a loop to set a mask for the pixels whose distance from the average
rgb values was less than that of the average across the entire image.
My reasoning for this was that the average distance from green of the
whole image will more than likely always be greater than the distance
between the average of chosen greenscreen pixels and the individual
greenscreen pixels. However, this may encounter problems with
images that have tiny images on top of mostly greenscreen
backgrounds. It would also work better if there was a description
of greenscreen guarenteed pixels or a certain number of buffer
rows and columns that can be assumed to be greenscreen rather
than varying image placements.
I considered finding the most common pixel value of the greenscreen
image (assuming it would be a greenscreen pixel) and using that most often
pixel value and using an average distance from it rather than an average of
certain pixels (like how I did 40x40 pixels in two corners). This
proved difficult to code as I was unsure how to count number of occurences
to find the most often occuring rgb value. It would have complicated
the program more than necessary.


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?
Longest one yet. Upwards of 8 hours.
:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.
Did not comprehend how the red, green, and blue values were stored when
I started. Took me a long time to figure out from the pdf explanations.
:

Do you have any other remarks?
Fun assignment once I got rolling! Guarenteed greenscreen pixels for images
would have been nice for a base for method2.
:
