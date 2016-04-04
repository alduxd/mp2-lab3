#ifndef _POSTFIX_H_
#define _POSTFIX_H_

#include "stack.h"
#include <cstring>
#include <sstream> 
#include <iostream>
using namespace std;

class Postfix
{
	string s;
public:
	Postfix(string = "");
	string Convert();	// Перевод инфиксной формы в постфиксную
	double Result();	// Вычисление результата 
private:
	void Validation();	// Валидация исходного выражения
	int IsOperator(char с);	// Проверка на операцию
	int GetOperationPrt(char с);	// Определение приоритета операции
};
#endif
