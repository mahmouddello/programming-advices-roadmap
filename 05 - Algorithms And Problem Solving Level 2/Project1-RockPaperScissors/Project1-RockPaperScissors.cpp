#include <iostream>

using namespace std;

/* COLORS
	system("Color 6F"); --> yellow
	system("Color 4F"); --> red
	system("Color 2F"); --> green
*/

enum enGameChoices {
	ROCK = 1,
	SCISSORS = 2,
	PAPER = 3
};

struct stGameStatistics
{
	int numberOfRounds = 0;
	int draws = 0;
	int playerWins = 0;
	int computerWins = 0;
};

struct stRoundChoices 
{
	enGameChoices playerChoice;
	enGameChoices computerChoice;
};

int RandomNumber(int from, int to)
{
	int randomNumber = rand() % (to - from + 1) + from;

	return randomNumber;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int HowManyRounds()
{
	 return ReadPositiveNumber("Enter the number of rounds? ");
}

void InputPlayerChoice(stRoundChoices& roundChoices)
{
	
	int choice;

	do {
		choice = ReadPositiveNumber("Your Choice : [1] : Rock, [2] : Scissors, [3] : Paper ? ");
	} while (choice < 1 || choice > 3);

	roundChoices.playerChoice = enGameChoices(choice);
}

void RandomComputerChoice(stRoundChoices& roundChoices)
{
	int choice = RandomNumber(1, 3);

	roundChoices.computerChoice = enGameChoices(choice);
}

string DisplayChoice(enGameChoices choice)
{
	switch (choice)
	{
	case enGameChoices::ROCK: return "Rock";
	case enGameChoices::SCISSORS: return "Scissors";
	case enGameChoices::PAPER: return "Paper";
	default: return "Error";
	}
}

void RingBell()
{
	cout << "\a";
}

string CheckRoundWinner(stGameStatistics& gameStats, const stRoundChoices roundChoices)
{
	if (roundChoices.playerChoice == roundChoices.computerChoice) // draw case
	{
		gameStats.draws++;
		system("Color 6F"); // yellow
		return "No Winner";
	}

	else if (roundChoices.playerChoice == ROCK)
	{
		if (roundChoices.computerChoice == SCISSORS)
		{
			gameStats.playerWins++;
			system("Color 2F"); // green
			return "Player";
		}
		
		else {
			// computer chooses paper so wins agains rock
			gameStats.computerWins++;
			RingBell();
			system("Color 4F");
			return "Computer";
		}
	}

	else if (roundChoices.playerChoice == PAPER)
	{
		if (roundChoices.computerChoice == ROCK)
		{
			gameStats.playerWins++;
			system("Color 2F"); // green
			return "Player";
		}

		else {
			// computer chooses scissors so wins agains paper
			gameStats.computerWins++;
			RingBell();
			system("Color 4F");
			return "Computer";
		}
	}

	else if (roundChoices.playerChoice == SCISSORS)
	{
		if (roundChoices.computerChoice == PAPER)
		{
			gameStats.playerWins++;
			system("Color 2F"); // green
			return "Player";
		}

		else {
			// computer chooses scissors so wins agains paper
			gameStats.computerWins++;
			RingBell();
			system("Color 4F");
			return "Computer";
		}
	}

	return "Error";
}

void ResetScreen()
{
	system("cls"); // clear screen
	system("Color 07"); // black background, white text (default)
}

string DecideGameWinner(stGameStatistics gameStats)
{
	if (gameStats.playerWins == gameStats.computerWins)
		return "No Winner";

	else if (gameStats.playerWins > gameStats.computerWins)
		return "Player";

	else
		return "Computer";
}

void GameOver(stGameStatistics gameStats)
{
	cout << "\t\t----------------------------------------"<< endl;
	cout << "\t\t\t  +++ GAME OVER +++ " << endl;
	cout << "\t\t-------------[Game Results]-------------\n" << endl;

	cout << "\t\tGame Rounds: " << gameStats.numberOfRounds << endl;
	cout << "\t\tPlayer won round: " << gameStats.playerWins << endl;
	cout << "\t\tComputer won round: " << gameStats.computerWins << endl;
	cout << "\t\tDraw times: " << gameStats.draws << endl;

	cout << "\t\tFinal Winner: " << DecideGameWinner(gameStats) << endl;
	cout << "\n\t\t----------------------------------------\n" << endl;
}

void StartGame()
{

	bool flag = true;
	
	while (flag)
	{
		stGameStatistics gameStats;
		stRoundChoices roundChoices;

		gameStats.numberOfRounds = HowManyRounds();

		for (int i = 1; i <= gameStats.numberOfRounds; i++)
		{
			cout << "\nRound [" << i << "] begins: \n";

			InputPlayerChoice(roundChoices);
			RandomComputerChoice(roundChoices);

			cout << "\n---------------------- Round [" << i << "] ----------------------\n" << endl;
			cout << "Player Choice: " << DisplayChoice(roundChoices.playerChoice) << endl;
			cout << "Computer Choice: " << DisplayChoice(roundChoices.computerChoice) << endl;
			cout << "Round Winner: " << CheckRoundWinner(gameStats, roundChoices) << endl;
			cout << "\n--------------------------------------------------------\n" << endl;
		}

		GameOver(gameStats);

		string restartGame;
		cout << "\t\tDo you want to play again? Y/N: ";
		cin >> restartGame;

		if (restartGame == "N")
			flag = false;
		else
			ResetScreen();
	}
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}