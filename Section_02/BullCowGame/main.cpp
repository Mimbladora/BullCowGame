#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGAme;

int main()
{
	setlocale(LC_ALL, "pl_PL");
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

void PrintIntro() 
{
	std::cout << " \n\nSiEmAnKo, WiTaM w MoJeJ gIeRcE! dZiSiAj BęDzIeMy ZgAdYwAć FaNtAsTyCzNe WyRaZy! " << std::endl;
	std::cout << " CzY dAsZ rAdĘ zGaDnĄć " << BCGAme.GetHiddenWordLength();
	std::cout << " LiTeRoWy WyRaZ, kTóRy MaM nA mYśLi?\n";
	std::cout << " \n--- d o b r z e ,  d o ś ć  g a d a n i a . ---\n";
	std::cout << " \n\n--- C Z A S  Z A B I J A Ć ---\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGAme.Reset();
	int32 MaxTries = BCGAme.GetMaxTries();
	while (!BCGAme.IsGameWon() && BCGAme.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGAme.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGAme.GetCurrentTry();
		std::cout << "Sproboj po raz " << CurrentTry << ". Napisz wyraz: ";
		std::getline(std::cin, Guess);

		Status = BCGAme.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << " No no, ktos tu chce umrzec. Wyraz musi miec " << BCGAme.GetHiddenWordLength() << " liter. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << " Papug, głupcze! Wyraz nie moze miec powtarzalnych liter! \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << " Tylko male litery sa akceptowalne... \n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}
	
	bool AskToPlayAgain()
	{
		std::cout << "Musisz zagrać jeszcze raz. To rozkaz. (TAK JEST!/NO NIE WIEM...) ";
		FText Response = "";
		std::getline(std::cin, Response);
		return (Response[0] == 't' || Response[0] == 'T');
	}
	
	void PrintGameSummary()
	{
		if (BCGAme.IsGameWon())
		{
			std::cout << "C O  T A K I E G O ? ! ? ! \n";
		}
		else
		{
			std::cout << "DED_ded_DED\n";
		}
	}


