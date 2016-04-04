#include "postfix.h"

Postfix::Postfix(string s_)
{
	s = s_;
	Validation();
}


void Postfix::Validation()
{
	string infix = this->s;
	int length = infix.length(), count1 = 0, count2 = 0;
	bool flag = true;

	for (int i = 0; i < length; i++)
	{
		if ((!isdigit(infix[i])) && (!IsOperator(infix[i])))	// Проверка на посторонние символы
			throw "Error! Invalid character";

		if (isdigit(infix[i]))	// Проверка на содержание цифр
			flag = false;

		if ((infix[i]) == '(') count1++;	//Проверка соответствия скобок
		if ((infix[i]) == ')') count2++;

		if (strchr("+-/*^", infix[i]) != NULL && strchr("+-/*^", infix[i + 1]) != NULL && i < length - 1)	// Проверка на идущие подряд операции
			throw "Error! Operations are not consistent.";
	}
	if (flag == true)
		throw "Error! The expression does not contain numbers.";
	if (count1 != count2)
		throw "Error! Not agreed number of brackets.";
}


int Postfix::IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
		return 1;
	else if (c == ' ' || c == '=')
		return 2;
	else
		return 0;
}


int Postfix::GetOperationPrt(char c)
{
	switch (c)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	case '^': return 4;
	default: return -1;
	}
}

string Postfix::Convert()
{
	string infix = this->s;
	string postfix;
	int length = infix.length();
	Stack<char> operatorstack(length);

	for (int i = 0; i < length; i++)
	{
		if ((i == 1) && (infix[0] == '-')) 	// Если в начале минус, добавляем его в выходную строку
			postfix = "-";

		if ((IsOperator(infix[i])) == 2) 	// Если пробел или равно, пропускаем символ
			continue;

		if (isdigit(infix[i]))	// Если цифра, помещаем все число в выходну строку
		{
			while (!IsOperator(infix[i]))
			{
				postfix += infix[i++];
				if (i == length)
					break;
			}
			postfix.push_back(' ');
			i--;
		}

		if ((IsOperator(infix[i])) == 1)	// Если скобки или опереатор
		{
			if (infix[i] == '(' && infix[i + 1] == '-' && i < length) // Если отрицательное число после скобки
			{
				operatorstack.push(infix[i]);
				i = i + 2;
				if (isdigit(infix[i]))
				{
					postfix.push_back('-');
					while (!IsOperator(infix[i]))
					{
						postfix.push_back( infix[i++]);
						if (i == length)
							break;
					}
					postfix.push_back(' ');
				}
			}

			if (infix[i] == '(' && infix[i + 1] != '-')	// Если просто открывающая скобка
					operatorstack.push(infix[i]);

			if (infix[i] == ')')	// Если закрывающа скобка
				{
					char s = operatorstack.pop();
					while (s != '(')
					{
						postfix.push_back(s);
						postfix.push_back(' ');
						s = operatorstack.pop();
					}
			}

			if ((infix[i] == '+')|| (infix[i] == '-')||(infix[i] == '*')|| (infix[i] == '/')|| (infix[i] == '^'))
			{
				while ((operatorstack.getTop() > -1) && (GetOperationPrt(infix[i]) <= GetOperationPrt(operatorstack.peek())))
				{
					postfix.push_back(operatorstack.pop());
					postfix.push_back(' ');
				}
				operatorstack.push(infix[i]);
			}
		}
	}

	while (operatorstack.getTop() > -1)	//После того, как прошли по всем символам, выкидываем из стека оставшиеся операторы в выходную строку
	{
		postfix.push_back(operatorstack.pop());
		postfix.push_back(' ');
	}

	return postfix;
}

double Postfix::Result()	// Вычисление результата
{
	string postfix = this->Convert();
	double result = 0;
	int length = postfix.length();
	Stack<double> ResultStack(length);

	for (int i = 0; i < length; i++)
	{
		if (isdigit(postfix[i]))	//Если цифра, помещаем все число в стек
		{
			string str;
			double op;
			while (!IsOperator(postfix[i]))
			{
				str += postfix[i++];
				if (i == length) break;
			}
			istringstream(str) >> op;
			ResultStack.push(op);
			i--;
		}

		if (postfix[i] == '-' && isdigit(postfix[i + 1]) && i < length - 1)	// Если минус
		{
			i = i + 1;
			string str;
			double op;
			while (!IsOperator(postfix[i]))
			{
				str += postfix[i++];
				if (i == length) break;
			}
			istringstream(str) >> op;
			ResultStack.push(-op);
			i--;
		}
		else if (((IsOperator(postfix[i])) == 1) && (i != 0))
		{
			double op1 = ResultStack.pop();
			double op2 = ResultStack.pop();
			switch (postfix[i])
			{
			case '+': result = op2 + op1; break;
			case '-': result = op2 - op1; break;
			case '*': result = op2 * op1; break;
			case '/':
				if (op1 != 0)
				{
					result = op2 / op1; break;
				}
				else
					throw "Error! Division by 0.";
			case '^': result = pow(op2, op1); break;
			}
			ResultStack.push(result);
		}
	}
	return ResultStack.peek();
}
