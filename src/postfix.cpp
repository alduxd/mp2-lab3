#include "postfix.h"

int Postfix::IsOperator(char c)     // проверка на операцию
{
	if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='('|| c==')') return 1;
	else if (c==' ' || c=='=') return 2;
	else return 0;
}

int Postfix::GetOperationPrt(char c)  // определение приоритета операции
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

string Postfix::Convert(string infix)
{
	int len = infix.length();
	string polish;                   // Строка для обратной польской записи
	Stack<char> OperationStack(len); // Стек для операторов
	bool var = true;
	int count1=0,count2=0;

	for (int i=0;i<len;i++)         // Проверка на правильный ввод
	{
		
		if ((!isdigit(infix[i])) && (!IsOperator(infix[i]))) // Проверяем есть ли посторонние символы
			throw "Error! Invalid character" ;
		
		if (isdigit(infix[i])) var = false; // Проверяем: выражение не может быть без цифр
		
		if ((infix[i])=='(') count1++; // Проверяем: кол-во '(' и ')' должно быть равно
		if ((infix[i])==')') count2++;
	
		if (strchr("+-/*^", infix[i])!=NULL && strchr("+-/*^", infix[i+1])!=NULL && i<len-1) 	// Проверяем: орерации не могут быть друг за другом
			throw "Error! Operations are not consistent" ;
	}

	if (var == true) throw "Error! The expression does not contain numbers" ;
	if (count1!=count2) throw "Error! Not agreed number of brackets" ;

	for (int i=0;i<len;i++) 
	{
		if ((i==1) && (infix[0]=='-')) polish="-"; // Если в начале минус
		if ((IsOperator(infix[i]))==2) continue;   // Если пробел или равно, пропускаем
		if (isdigit(infix[i]))                     // Если цифра,
		{
			while (!IsOperator(infix[i]))          // считываем всё число
			{
				polish+=infix[i++]; 
				if (i==len) break;
			}
			polish.push_back(' ');                 // добавляем пробел после числа
			i--;
		}
		if ((IsOperator(infix[i]))==1)             // если операция или скобки
			if (infix[i] == '(' && infix[i+1] == '-' && i<len-2)  // Если '-' после '('
			{
				i=i+2;
				if (isdigit(infix[i]))
				{
					polish.push_back('-');
					while (!IsOperator(infix[i]))
					{
						polish+=infix[i++]; 
						if (i==len) break;
					}
					polish.push_back(' ');
				}
			}
			else if (infix[i]=='(') OperationStack.push(infix[i]); 
			else if (infix[i]==')') 
			{
				char s = OperationStack.pop();
				while (s != '(')
				{
					polish.push_back(s);
					polish.push_back(' ');
					s=OperationStack.pop();
				}
			}
			else if (i!=0) // если не минус в начале
			{
				while ((OperationStack.getTop()>-1) && (GetOperationPrt(infix[i])<=GetOperationPrt(OperationStack.peek())))
				{
					polish.push_back(OperationStack.pop());
					polish.push_back(' ');
				}
				OperationStack.push(infix[i]);
			}
	}
	//Когда прошли по всем символам, выкидываем из стека все оставшиеся там операторы в строку
	while (OperationStack.getTop()>-1)
	{
		polish.push_back(OperationStack.pop());
		polish.push_back(' ');
	}
	return polish; 
}

double Postfix::Result(string polish) // вычисление результата
{
	double res=0;
	int len = polish.length();
	Stack<double> ResultStack(len);
	for (int i=0;i<len;i++) 
	{
		//Если цифра, то читаем все число и толкаем на вершину стека
		if (isdigit(polish[i])) 
		{
			string str;
			double op;
			while (!IsOperator(polish[i])) 
			{
				str+=polish[i++]; 
				if (i==len) break;
			}
			istringstream(str)>>op;
			ResultStack.push(op); 
			i--;
		}
		// Если встречен минус
		if (polish[i]=='-' && isdigit(polish[i+1]) && i<len-1)
		{
			i=i+1;
			string str;
			double op;
			while (!IsOperator(polish[i])) 
			{
				str+=polish[i++]; 
				if (i==len) break;
			}
			istringstream(str)>>op;
			ResultStack.push(-op); 
			i--;
		}
		else if (((IsOperator(polish[i]))==1) && (i!=0))
		{
			double op1=ResultStack.pop(); 
			double op2=ResultStack.pop();
			switch (polish[i])
			{ 
			case '+': res = op2 + op1; break;
			case '-': res = op2 - op1; break;
			case '*': res = op2 * op1; break;
			case '/': 
				if (op1!=0)
				{
					res = op2 / op1; break;
				}
				else throw "Division by 0!";
			case '^': res = pow(op2,op1); break;
			}
			ResultStack.push(res); 
		}
	}
	return ResultStack.peek();
}