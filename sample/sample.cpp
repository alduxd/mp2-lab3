#include "postfix.h"

int main()
{
	try
	{
		cout << "Enter an arithmetic expression:" << endl;
		
		string expression;
		cin >> expression;
		
		Postfix calculate(expression);
		string postfixform = calculate.Convert();
		double result = calculate.Result();

		cout << "Expression: " << expression << endl;
		cout << "Postfix form: " << postfixform << endl;
		cout << "Result: " << result << endl;

		//(-2+1/2-9*4-3)+(1+3)
		//(-1+12*4)+9*(-1+3)/3
		return 0;
	}
	catch (const char* error)
	{
		cout<<error<<endl;
	}
}