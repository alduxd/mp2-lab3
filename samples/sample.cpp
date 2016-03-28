#include "postfix.h"

int main()
{
	try
	{
		cout << "Enter the arithmetic expression"<< endl;

		Postfix Convertor;
		string Expression;
		string row;

		cin >> Expression;

		string PolishExpression = Convertor.Convert(Expression);
		double result = Convertor.Result(PolishExpression);
		cout << "Expression: " << Expression << endl;
		cout << "Postfix form: " << PolishExpression << endl;
		cout << "Result: " << result << endl;
	}

	catch (const char* error)
	{
		cout<<error<<endl;
	}
	return 0;
}
