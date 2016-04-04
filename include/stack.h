#ifndef _STACK_H_
#define _STACK_H_

#define MaxSize 100

template <typename T>
class Stack
{
private:
    T *array;                      
    const int size;                   
    int top;                          
public:
	Stack(int s=15);	// ����������� �������������
    ~Stack();	// ����������   
    void push(const T &val );	// �������� ������� � ����
	T pop();	// ����� ������� �� �����
    const T &peek();	// �������� �������� �����
	int getSize();	//�������� ������ �����
    int getTop();	//�������� ����� �������� ��������
};

template <typename T>
Stack<T>::Stack(int s):size(s), top(-1)
{
	if (size>MaxSize) throw "Error! Size must be <=100";
	if (size<0) throw "Error! Size must be >=0";
    array = new T[size]; 
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] array; 
}


template <typename T>
void Stack<T>::push(const T &val)
{
	if (top+1>=size) throw "Error! Stack is full";
	array[++top] = val; 
}


template <typename T>
T Stack<T>::pop()
{ 
	if (top<0) throw "Error! Stack is empty"; 
	return array[top--];
}


template <class T>
const T &Stack<T>::peek()
{
	if (top<0) throw "Error! Stack is empty";
	return array[top]; 
}


template <typename T>
int Stack<T>::getSize()
{
    return size;
}


template <typename T>
int Stack<T>::getTop()
{
    return top;
}

#endif