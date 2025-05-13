#include <iostream>

using namespace std;

class clsCalculator
{
private:
	float _result = 0;
	float _lastResult = 0;
	float _lastNumber = 0;
	string _operation = "";

	float getResult()
	{
		return _result;
	}

	void setResult(float result)
	{
		_result = result;
	}

	float getLastResult()
	{
		return _lastResult;
	}

	void setLastResult(float result)
	{
		_lastResult = result;
	}

	float getLastNumber()
	{
		return _lastNumber;
	}

	void setLastNumber(float number)
	{
		_lastNumber = number;
	}

	string getOperation()
	{
		return _operation;
	}

	void setOperation(string operation)
	{
		_operation = operation;
	}

	bool isOperationClearOrCancel()
	{
		return getOperation() == "Clearing" || getOperation() == "Canceling";
	}

public:
	void add(float number)
	{
		setOperation("Adding");
		setLastNumber(number);
		setLastResult(getResult());
		setResult(getResult() + number);
	}

	void substract(float number)
	{
		setOperation("Substracting");
		setLastNumber(number);
		setLastResult(getResult());
		setResult(getResult() - number);
	}

	void divide(float number)
	{
		// for demo purposes
		if (number <= 0)
			number = 1;

		setOperation("Dividing");
		setLastNumber(number);
		setLastResult(getResult());
		setResult(getResult() / number);
	}

	void multiply(float number)
	{
		setOperation("Multiplying");
		setLastNumber(number);
		setLastResult(getResult());
		setResult(getResult() * number);
	}

	void printResult()
	{
		if (!isOperationClearOrCancel())
			cout << "Result after " << getOperation() << " " << getLastNumber() << " is: " << getResult() << endl;
		else
			cout << "Result after " << getOperation() << " is: " << getResult() << endl;
	}

	void clear()
	{
		setOperation("Clearing");
		setResult(0);
	}

	void cancelLastOperation()
	{
		setOperation("Canceling");
		setLastNumber(0);
		setResult(getLastResult());
	}
};

int main()
{
	clsCalculator calculator;

	calculator.clear();

	calculator.add(10);
	calculator.printResult();

	calculator.add(100);
	calculator.printResult();

	calculator.substract(20);
	calculator.printResult();

	calculator.divide(0);
	calculator.printResult();

	calculator.divide(2);
	calculator.printResult();

	calculator.multiply(3);
	calculator.printResult();

	calculator.cancelLastOperation();
	calculator.printResult();

	calculator.clear();
	calculator.printResult();

	return 0;
}