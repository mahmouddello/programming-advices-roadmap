#pragma once
#include <stack>

using namespace std;

class clsMyString
{
private:
	stack<string> _undoStack;
	stack<string> _redoStack;
	string _value;

public:
	void setValue(const string& value)
	{
		this->_value = value;
		this->_undoStack.push(this->_value);
	}

	string getValue()
	{
		return this->_value;
	}

	__declspec(property(get = getValue, put = setValue)) string value;

	void undo()
	{
		if (!_undoStack.empty())
		{
			_redoStack.push(_value);
			_value = _undoStack.top();
			_undoStack.pop();
		}
		else
			cout << "Stack is empty on undo!" << endl;
	}

	void redo()
	{
		if (!_redoStack.empty())
		{
			_undoStack.push(_value);
			_value = _redoStack.top();
			_redoStack.pop();
		}
		else
			cout << "Stack is empty on redo!" << endl;
	}
};

