#ifndef _POSTFIX_H_
#define _POSTFIX_H_

#include "stack.h"
#include <cstring>
#include <sstream> 
#include <iostream>
using namespace std;

class Postfix
{
public:
	string Convert(string input);	// перевод инфиксной формы в постфиксную
    double Result(string input);	// подсчёт результата 
	int IsOperator(char c);			// проверка на операцию
	int GetOperationPrt(char c);	// определение приоритета операции
};
#endif