#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main()
{
	PrintIntro();

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) 
	{
		GetGuessAndPrintBack();
		cout << endl;
	}
	
	cout << endl;
	return 0;
}

// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;
	cout << "Witejcie w gierce o byczkoch i krowkach, jest to powazna gra w zgadywanie wyrazow." << endl;
	cout << "Czy dasz rade zgadnac " << WORD_LENGTH;
	cout << " literowy wyraz, ktory mam na mysli?\n";
	cout << endl;
	return;
}


string GetGuessAndPrintBack() 
{
	// get a guess from the player
	cout << "Napisz tutaj wyraz, graczu: ";
	string Guess = "";
	getline(cin, Guess);

	// print the guess back
	cout << "Twoj wyraz, graczu, to: " << Guess << endl;
	return Guess;
}