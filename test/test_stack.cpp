#include "stack.h"
#include <gtest.h>

///////////// STACK TESTS /////////////
TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW (Stack<int> s(10));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-1));
}

TEST(Stack, cant_create_stack_with_very_big_length)
{
	ASSERT_ANY_THROW(Stack<int> s(101));
}

TEST(Stack, can_get_size)
{
	Stack<int> s(2);
	EXPECT_EQ(2, s.getSize());
}

TEST(Stack, can_get_top)
{
	Stack<int> s(2);
	EXPECT_EQ(-1, s.getTop());
}

TEST(Stack,can_push)
{
	Stack<int> s(2);
	ASSERT_NO_THROW(s.push(1));
}

TEST(Stack,can_pop)
{
	Stack<int> s(2);
	s.push(1);
	ASSERT_NO_THROW(s.pop());
}

TEST(Stack,can_peek)
{
	Stack<int> s(2);
	s.push(2);
	EXPECT_EQ(2, s.peek());
}

TEST(Stack, cant_peek_empty_stack)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW( s.peek());
}


TEST(Stack, peek_does_not_spoil_data) {
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	s.peek();
	EXPECT_EQ(2, s.pop());
}

TEST(Stack, throws_when_full)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	ASSERT_ANY_THROW(s.push(3));
}
TEST(Stack, throws_when_free)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}


///////////// POSTFIX TESTS /////////////
/*
TEST(Postfix, validation1)
{
	string s = "1+2+3";
	ASSERT_NO_THROW(Postfix calculate(s));
}

TEST(Postfix, validation2)
{
	string s = "(-1+2*4)+9/3";
	ASSERT_NO_THROW(Postfix calculate(s));
}

TEST(Postfix, validation3)
{
	string s = "(1+2";
	ASSERT_ANY_THROW(Postfix calculate(s));
}

TEST(Postfix, validation4)
{
	string s = "--1";
	ASSERT_ANY_THROW(Postfix calculate(s));
}

TEST(Postfix, validation5)
{
	string s = "1**2";
	ASSERT_ANY_THROW(Postfix calculate(s));
}

TEST(Postfix, validation6)
{
	string s = "abcd+";
	ASSERT_ANY_THROW(Postfix calculate(s));
}


TEST(Postfix, cant_divide_by_0)
{
	string s = "1/0";
	Postfix calculate(s);
	ASSERT_ANY_THROW(calculate.Result());
}

TEST(Postfix, can_convert_in_postfix_form1)
{
	string s = "1-2+3*4";
	Postfix calculate(s);
	EXPECT_EQ(calculate.Convert(), "1 2 - 3 4 * +");
}

TEST(Postfix, can_calculate1)
{
	string s = "1-2+3*4";
	Postfix calculate(s);
	double result = calculate.Result();
	EXPECT_EQ(calculate.Result(), 11);
}

TEST(Postfix, can_calculate2)
{
	string s = "1-(2+3)*4";
	Postfix calculate(s);
	double result = calculate.Result();
	EXPECT_EQ(calculate.Result(), -19);
}
*/