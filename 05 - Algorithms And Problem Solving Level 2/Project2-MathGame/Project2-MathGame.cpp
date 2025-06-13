#include <iostream>

using namespace std;

enum enDifficulty
{
	EASY = 1,
	MEDIUM = 2,
	HARD = 3,
	MIX_DIF = 4
};

enum enOperationType
{
	ADD = 1,
	SUBTRACT = 2,
	MULTIPLY = 3,
	DIVISION = 4,
	MIX_OP = 5
};

struct stQuizSettings
{
	int totalQuestionNumber = 0;
	enDifficulty difficultyLevel = enDifficulty::EASY;
	enOperationType operationType = enOperationType::ADD;
	int correctAnswers = 0;
	int wrongAnswers = 0;
};

struct stQuestionInfo
{
	int questionNumber;
	int number1, number2;
	char operationSymbol;
	int userAnswer;
	int trueAnswer;
};

int RandomNumber(int from, int to)
{
	int randomNumber = rand() % (to - from + 1) + from;

	return randomNumber;
}

int ReadPositiveNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

int ReadQuestionsNumber()
{
	return ReadPositiveNumber("How many questions do you want to answer? ");
}

enDifficulty ReadDifficultyLevel()
{
	string message = "Enter question level [1]: Easy, [2]: Medium, [3]: Hard, [4]: Mix? ";
	int difficultyLevel = ReadPositiveNumber(message);

	return enDifficulty(difficultyLevel);
}

enOperationType ReadOperationType()
{
	string message = "Enter operation type [1]: Add, [2]: Subtract, [3]: Multiply, [4]: Division, [5]: Mix? ";
	int operationType = ReadPositiveNumber(message);

	return enOperationType(operationType);
}

void GenerateNumbers(enDifficulty diffcultyLevel, stQuestionInfo& questionInfo)
{

	switch (diffcultyLevel)
	{
	case EASY:
	{
		questionInfo.number1 = RandomNumber(1, 10);
		questionInfo.number2 = RandomNumber(1, 10);
		break;
	}

	case MEDIUM:
	{
		questionInfo.number1 = RandomNumber(10, 100);
		questionInfo.number2 = RandomNumber(10, 100);
		break;
	}

	case HARD:
	{
		questionInfo.number1 = RandomNumber(100, 1000);
		questionInfo.number2 = RandomNumber(100, 1000);
		break;
	}

	case MIX_DIF:
	{
		GenerateNumbers(enDifficulty(RandomNumber(1, 3)), questionInfo);
		break;
	}
	default:
		break;
 	};
}

char GetOperationSymbol(enOperationType operationType)
{
	char operationSymbols[] = { '+', '-', '*', '/' };

	return operationSymbols[operationType - 1];
}

void SelectOperation(enOperationType operationType, stQuestionInfo& questionInfo)
{
	switch (operationType)
	{
	case ADD:
	{
		questionInfo.operationSymbol = GetOperationSymbol(operationType);
		questionInfo.trueAnswer = questionInfo.number1 + questionInfo.number2;
		break;
	}
	case SUBTRACT:
	{
		questionInfo.operationSymbol = GetOperationSymbol(operationType);
		questionInfo.trueAnswer = questionInfo.number1 - questionInfo.number2;
		break;
	}
	case MULTIPLY:
	{
		questionInfo.operationSymbol = GetOperationSymbol(operationType);
		questionInfo.trueAnswer = questionInfo.number1 * questionInfo.number2;
		break;
	}
	case DIVISION:
	{
		questionInfo.operationSymbol = GetOperationSymbol(operationType);
		questionInfo.trueAnswer = questionInfo.number1 / questionInfo.number2;
		break;
	}
	case MIX_OP:
	{
		SelectOperation(enOperationType(RandomNumber(1, 4)), questionInfo);
		break;
	}
	default:
		break;
	};
}

stQuizSettings ReadQuizSettings()
{
	stQuizSettings quizSettings;

	quizSettings.totalQuestionNumber = ReadQuestionsNumber();
	quizSettings.difficultyLevel = ReadDifficultyLevel();
	quizSettings.operationType = ReadOperationType();

	return quizSettings;
}

stQuestionInfo GenerateQuestion(int questionNo, stQuizSettings& quizSettings)
{
	stQuestionInfo questionInfo;

	questionInfo.questionNumber = questionNo;
	GenerateNumbers(quizSettings.difficultyLevel, questionInfo);
	SelectOperation(quizSettings.operationType, questionInfo);

	return questionInfo;
}

string GetDifficultyLevel(enDifficulty difficultyLevel)
{
	string diffs[] = { "EASY", "MEDIUM", "HARD", "MIX" };

	return diffs[difficultyLevel - 1];
}

string GetOperationType(enOperationType operationType)
{
	string opps[] = { "ADD", "SUBSTRACT", "MULTIPLY", "DIVISON" };

	return opps[operationType - 1];
}

void PrintQuestion(stQuestionInfo questionInfo, int totalQuestionNums)
{
	cout << "\nQuestion [" << questionInfo.questionNumber << "/" << totalQuestionNums << "]:" << endl;
	cout << "\n" << questionInfo.number1 << endl;
	cout << questionInfo.number2 << " " <<  questionInfo.operationSymbol << endl;
	cout << "-----------------" << endl;

}

int ReadQuestionAnswer()
{
	return ReadPositiveNumber("Answer? ");
}

bool ValidateAnswer(stQuestionInfo& questionInfo)
{
	return questionInfo.userAnswer == questionInfo.trueAnswer;
}

void ResetScreen()
{
	system("cls"); // clear screen
	system("Color 07"); // black background, white text (default)
}

void GameOver(stQuizSettings& quizSettings)
{
	cout << "\n\n------------------------------" << endl;
	
	string result = "";

	if (quizSettings.correctAnswers > quizSettings.wrongAnswers)
		result = "PASS :-)";
	else
		result = "FAIL :-(";

	cout << "FINAL RESULT IS " << result << endl;
	cout << "------------------------------" << endl;

	cout << "Number of questions: " << quizSettings.totalQuestionNumber << endl;
	cout << "Difficulty Level: " << GetDifficultyLevel(quizSettings.difficultyLevel) << endl;
	cout << "Operation Type: " << GetOperationSymbol(quizSettings.operationType) << endl;
	cout << "Number of correct answers: " << quizSettings.correctAnswers << endl;
	cout << "Number of wrong answers: " << quizSettings.wrongAnswers << endl;

}

void StartGame()
{
	char playAgain = 'Y';

	do {
		
		ResetScreen();
		stQuizSettings quizSettings = ReadQuizSettings();

		for (int i = 1; i <= quizSettings.totalQuestionNumber; i++)
		{
			stQuestionInfo questionInfo;
			questionInfo = GenerateQuestion(i, quizSettings);
			PrintQuestion(questionInfo, quizSettings.totalQuestionNumber);

			questionInfo.userAnswer = ReadQuestionAnswer();

			if (ValidateAnswer(questionInfo))
			{
				cout << "Right Answer :)" << endl;
				system("Color 2F");
				quizSettings.correctAnswers++;
			}

			else {
				cout << "Wrong Answer :(" << endl;
				system("Color 4F");
				quizSettings.wrongAnswers++;
			}

		}

		GameOver(quizSettings);

		cout << "Do you want to play again? ";
		cin >> playAgain;

	} while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	
	StartGame();

	return 0;
}