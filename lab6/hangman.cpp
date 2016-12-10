// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  int stars = strlen(targetWord); 
  //clearing word to show stars
  for(int i = 0; i < stars; i++){
  	word[i] = '*';
  }






  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
for(int turns = numTurns; turns > 0 & wordGuessed == false; turns--){
	cout << "Current word: ";
	for(int i = 0; i < stars; i++){
		cout << word[i];
	}
	cout << "\n" << turns << " remain . . . Enter a letter to guess;" << endl;
	cin >> guess;

	//adding turn back if user guesses correctly
	int correct = processGuess(word, targetWord, guess);
	if(correct > 0){
		turns++; 
	}
	
	//end loop if word is completely guessed
	if(strcmp(targetWord, word) == 0){
			wordGuessed = true;
	}
}



// Print out end of game status
if(strcmp(targetWord, word) == 0) {
	cout << "The word was: " << targetWord << ". You win!" << endl;
}
else{
	cout << "Too many turns . . . You lose!" << endl;
}
    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
	int count = 0;
	int stars = strlen(targetWord);
	for(int i = 0; i < stars; i++){
		if(guess == targetWord[i]){
			word[i] = guess;
			count++;
		}
	}
return count;
}

