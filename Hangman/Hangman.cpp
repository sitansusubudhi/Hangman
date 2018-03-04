// Hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void printDesign(string message, bool printTopBorder = true, bool printBottomBorder = true) {
	
	if (printTopBorder) {
		cout << "+-----------------------------------+"<< endl;
		cout<< "|";
	}
	else {
		cout << "|";
	}
	//Displaying message in middle
	bool front = true;
	for (int i = message.length(); i < 35; i++) {
		if (front) {
			message = " " + message;
		}
		else {
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();
	if (printBottomBorder) {
		cout << "|"<< endl;
		cout << "+-----------------------------------+" << endl;
	}
	else {
		cout << "|" << endl;
	}
}

/*
+-----------------------------------+
|             HANGMAN               |
+-----------------------------------+
|          †††††††††                |
|          †       †                |
|          †       O                |
|          †      /|\               |
|          †       |                |
|          †      / \               |
|          †††††††††††              |
|          †††††††††††              |
+-----------------------------------+
|	     Available letters          |
+-----------------------------------+
|     A B C D E F G H I J K L M     |
|     N O P Q R S T U V W X Y Z     |
+-----------------------------------+
|		  Guess the word            |
+-----------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+-----------------------------------+
*/

void drawHangman(int noOfGuesses = 0) {
	if (noOfGuesses >= 1)
		printDesign("+++++++++", false, false);
	else
		printDesign("", false, false);

	if (noOfGuesses >= 2)
		printDesign("+       !", false, false);
	else
		printDesign("", false, false);

	if (noOfGuesses >= 3)
		printDesign("+       O", false, false);
	else
		printDesign("", false, false);

	if (noOfGuesses == 4)
		printDesign("+       |", false, false);
	if (noOfGuesses == 5)
		printDesign("+      /|", false, false);
	if (noOfGuesses >= 6)
		printDesign("+      /|\\", false, false);
	else
		printDesign("", false, false);

	if (noOfGuesses >= 7)
		printDesign("+       |", false, false);
	else
		printDesign("", false, false);

	if (noOfGuesses == 8)
		printDesign("+       / ", false, false);
	if (noOfGuesses >= 9)
		printDesign("+      / \\", false, false);
	else
		printDesign("", false, false);
	printDesign("  +           ", false, false);
	printDesign("+++++++++++++", false, false);
	printDesign("+++++++++++++", false, false);
}


void printLettersAvailable(string input, char from, char to) {
	string s;
	for (char i = from; i <= to; i++) {
		if (input.find(i) == string::npos) {
			s += i;
			s += " ";
		}
		else {
			s += "  ";
		}
	}
	printDesign(s, false, false);
}

void printLettersAvailable(string i) {
	printDesign("Available Letters");
	printLettersAvailable(i, 'A', 'M');
	printLettersAvailable(i, 'N', 'Z');
}

//checks if user has correctly guessed the word.
bool printWordPlaceholderCheckAnswer(string word, string guess) {		
	bool won = true;
	string x;
	for (int i = 0; i < word.length(); i++) {
		if (guess.find(word[i]) == string::npos) {
			won = false;
			x += "_ ";
		}
		else {
			x += word[i];
			x += " ";
		}
	}
	printDesign(x, false);
	return won;
}

int main()
{
	string guesses = "ABCS";

	printDesign("HANGMAN");
	drawHangman(9);
	printLettersAvailable(guesses);
	printDesign("Guess Word");
	printWordPlaceholderCheckAnswer("SIRI", guesses);
	cout << endl;
	cout << "Hello World!";
	cout << endl;
	
	return 0;
}

