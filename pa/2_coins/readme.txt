CSCI 103 Programming Assignment: Going Broke

Name: Nick Kaimakis

Email Address: kaimakis@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

1. How will you generate a coin-toss outcome for each player? (i.e. map the 
random number returned by rand() to a Heads/Tails outcome)

Response 1: I will use srand(time) to produce a random number, and then I
will use %2 to receive a value of either 0 or 1, standing for true or false.

2. Based on the coin-toss outcome for each player, what cases do you need to 
check for to decide how to do the coin bookkeeping? What logical 
connectors do you use?

Response 2: I need to check for two cases, the 
first being three of the same outcomes 
(resulting in returning all coins to owners), the second being one outcome being
different than the other two. The first case will trigger two and gates, and the
second will trigger one and gate and on exclusive or gate.

3. Is the number of iterations/turns that a single game requires known a priori
(which simply means "beforehand" but is used quite often in computer 
science speak). What kind of loop should then be used and what is its 
terminating condition?

Response 3: The number of turns is not a priori, and therefore a while or for loop
should be used to run the simulation to completion. The terminating condition
is when at least one player is out of coins.

4. What data needs to be maintained for the total simulation (i.e. across 
several games)? What type?

Response 4: The data that needs to be maintained is the total amount of coins
each player has. These can be ints within an array.

5. Is the number of iterations for the total simulations known before entering 
the loop? What kind of loop should then be used?

Response 5: No, a while loop should be used.

6. Also, consider the case that somehow the players all use unfair (possibly 
weighted) coins that come up as heads with probability, p. We will start by 
simulating fair coins where p=0.5. Assuming that for fair coins (p=0.5) we 
calculate x number of flips per game. How will the number of flips per game 
change if p = 0.1? Will it stay the same or go up or down and how 
dramatically? Think about this scenario and write a sentence of two
explaining your prediction and your reasoning before starting to code your 
solution.

Response 6: The number of flips per game will go up dramatically, because
the probability that all three of the same coins are rolled increases
dramatically. There is a smaller chance that one coin will be different.

====================== Data from Procedure Step 6 ==========================

coins |  p  |   n    | output
------------------------------
  3   | 0.5 | 5      | 4.2
  3   | 0.5 | 10     | 5.3
  3   | 0.5 | 50     | 4.72
  3   | 0.5 | 100    | 5.16
  3   | 0.5 | 1000   | 5.2
  3   | 0.5 | 10000  | 5.1609
  3   | 0.5 | 100000 | 5.1437
 
====================== Data from Procedure Step 7 ==========================

coins |  p  |   n    | output
------------------------------
  3   | 0.1 | 10000  | 14.291
  3   | 0.2 | 10000  | 8.1532
  3   | 0.3 | 10000  | 6.1485
  3   | 0.4 | 10000  | 5.3651
  3   | 0.5 | 10000  | 5.1416
  3   | 0.6 | 10000  | 5.3461
  3   | 0.7 | 10000  | 6.1356
  3   | 0.8 | 10000  | 8.0137
  3   | 0.9 | 10000  | 14.208

================================== Review ===================================

1. For your first data set, what, in your opinion, is the "point of 
diminshing returns" where the extra time waiting for the simulation 
is not worth the increased accuracy?

Response 1: The point of diminishing return comes at 10 million, or 7 zeroes. 
At this point it is not worth it to wait several seconds for an 
insignificantly more accurate answer.

2. Examine your results as p varies in your second data set.
Do these results match your expectations of the behavior of the average 
number of flips as p approaches 0 or 1?

Response 2: Yes, the higher the chances that the coins will flip as only heads/tails
should be directly related to the average number of turns. The more 
likely the coins are the same, the less likely a player will lose.

3. When we examined the effects of varying p, why did we start at 0.1 and end 
at 0.9 rather than starting at 0.0 and ending at 1.0?

Response 3: Because a simulation of 0.0 or 1.0 would never end, as the coins
would never come up as different results

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
