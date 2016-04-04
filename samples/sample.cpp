#include "postfix.h"

int main()
{
	try
	{
		cout << "Enter an arithmetic expression:"<< endl;

		string row;
		cin >> row;
		string expression(row);
		Postfix calculate(expression);
		string polishform = calculate.Convert();
		double result = calculate.Result();

		cout << "Expression: " << expression<< endl;
		cout << "Postfix form: " << polishform << endl;
		cout << "Result: " << result << endl;
	}

	catch (const char* error)
	{
		cout << error << endl;
	}

	return 0;
}
