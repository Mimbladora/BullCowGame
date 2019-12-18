#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGAme; // juz nie wiem co

// the entry point for our application
int main()
{
	std::cout << BCGAme.GetCurrentTry();

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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Witejcie w gierce o byczkoch i krowkach, jest to powazna gra w zgadywanie wyrazow." << std::endl;
	std::cout << "Czy dasz rade zgadnac " << WORD_LENGTH;
	std::cout << " literowy wyraz, ktory mam na mysli?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGAme.Reset();
	int32 MaxTries = BCGAme.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();
		std::cout << "Twoj wyraz to: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess() 
{
	int32 CurrentTry = BCGAme.GetCurrentTry();

	// get a guess from the player
	std::cout << "Sproboj po raz " << CurrentTry << ". Napisz wyraz: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Musisz zagrac jeszcze raz. To rozkaz. (TAK JEST!/NO NIE WIEM...) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 't' || Response[0] == 'T');
}
