CSCI 103 Programming Assignment 4, A Mazeing BFS

Name: Nick Kaimakis

Email Address: kaimakis@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

:
=============================== Prelab ==================================

1. What data structure will you use to remember which cells have
already been added to the queue or not?
A two dimensional array of booleans. 1 means it has been added, 0 means 
it has not.
:

2. At what step of the BFS algorithm do you have to mark a cell as visited?
I marked the cells as visited after checking that they were not already
visited. This could be done in several different ways, but I marked the
cells after I had added them to the queue or determined that they
were a wall.
:

=============================== Review ==================================

1. Describe your "mymaze.txt" test file. It should have multiple paths
of different distances. When you ran your program on it, did your program 
behave as expected?
In the maze I created, I made several paths of varying distance. My 
program did run as expected, finding the shortest possible path.
:

============================== Remarks ==================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially 
useful to know if you turned it in incomplete.

:

Do you have any other remarks?

:

