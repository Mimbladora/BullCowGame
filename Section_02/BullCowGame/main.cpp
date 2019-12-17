#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

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

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		cout << "Twoj wyraz to: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() 
{
	// get a guess from the player
	cout << "Napisz tutaj wyraz, graczu: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Musisz zagrac jeszcze raz. To rozkaz. (TAK JEST!/NO NIE WIEM...) ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 't' || Response[0] == 'T');
}
