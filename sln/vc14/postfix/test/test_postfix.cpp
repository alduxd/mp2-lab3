#include "postfix.h"
#include <gtest.h>


TEST(Postfix, validation0)
{
	string s = "1";
	ASSERT_NO_THROW(Postfix calculate(s));
}


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


TEST(Postfix, validation7)
{
	string s = "1+2+!";
	ASSERT_ANY_THROW(Postfix calculate(s));
}


TEST(Postfix, cant_divide_by_0)
{
	string s = "1/0";
	Postfix calculate(s);
	ASSERT_ANY_THROW(calculate.Result());
}


TEST(Postfix, cant_divide_by_0_2)
{
	string s = "(1+2)/0";
	Postfix calculate(s);
	ASSERT_ANY_THROW(calculate.Result());
}

TEST(Postfix, can_convert_in_postfix_form1)
{
	string s = "1-2+3*4";
	Postfix calculate(s);
	EXPECT_EQ(calculate.Convert(), "1 2 - 3 4 * + ");
}

TEST(Postfix, can_calculate1)
{
	string s = "1-2+3*4"; //=11
	Postfix calculate(s);
	double result = calculate.Result();
	EXPECT_EQ(calculate.Result(), 11);
}

TEST(Postfix, can_convert_in_postfix_form2)
{
	string s = "(1+2)*(4-2)";
	Postfix calculate(s);
	EXPECT_EQ(calculate.Convert(), "1 2 + 4 2 - * ");
}


TEST(Postfix, can_convert_in_postfix_form3)
{
	string s = "(-2+5)*5";
	Postfix calculate(s);
	EXPECT_EQ(calculate.Convert(), "-2 5 + 5 * ");
}

TEST(Postfix, can_calculate2)
{
	string s = "1-(2+3)*4"; //=-19
	Postfix calculate(s);
	double result = calculate.Result();
	EXPECT_EQ(calculate.Result(), -19);
}

TEST(Postfix, can_convert3)
{
	string s = "(-1+12*4)+9*(-1+3)/3";
	Postfix calculate(s);
	ASSERT_NO_THROW(calculate.Convert());
}

TEST(Postfix, can_convert4)
{
	string s = "(-1*4+3)-20-(-1*2+3)";
	Postfix calculate(s);
	ASSERT_NO_THROW(calculate.Convert());
}


TEST(Postfix, can_convert5)
{
	string s = "(-2)*(2+3)";
	Postfix calculate(s);
	ASSERT_NO_THROW(calculate.Convert());
}


TEST(Postfix, can_convert6)
{
	string s = "(-1*(20+3)-4/3)-2-(-1/(-2)+3+(1+2))";
	Postfix calculate(s);
	ASSERT_NO_THROW(calculate.Convert());
}

